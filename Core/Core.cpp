#include "Core.h"
#include "IO.h"
#include "XmlDeserializer.h"
#include "WeightsMatrix.h"
#include "DrawingMode.h"

Core::Core(QObject *parent) :
    QObject(parent),
    linkCreator(&map),
    nodeCreator(&map),
    elementEditor(&map)
{
    changeStateToEdit();
    DrawingMode::showDelay();
}

void Core::refreshNetworkMap()
{
    emit signalRefreshNetworkMapView(map.draw());
}

void Core::handleMouseReleaseEvent(QPoint position)
{
    tool->handleMouseUp(position);
    refreshNetworkMap();
}

void Core::handleMousePressEvent(QPoint position)
{
    tool->handleMouseDown(position);
    refreshNetworkMap();
}

void Core::handleMouseMoveEvent(QPoint position)
{
    if (tool->handleMouseMove(position))
    {
        refreshNetworkMap();
    }
}

void Core::handleDoubleClickEvent(QPoint position)
{
    tool->handleMouseDoubleClicked(position);
    refreshNetworkMap();
}

void Core::handleKeyDeletePressEvent()
{
    tool->handleKeyDeletePressEvent();
    refreshNetworkMap();
}

void Core::changeStateToEdit()
{
    tool = &elementEditor;
}

void Core::prepareSdnController()
{
    tool = &nodeCreator;
    nodeCreator.setSdnControllerCreation();
}

void Core::prepareHost()
{
    tool = &nodeCreator;
    nodeCreator.setHostCreation();
}

void Core::prepareSwitch()
{
    tool = &nodeCreator;
    nodeCreator.setSwitchCreation();
}

void Core::prepareLink()
{
    tool = &linkCreator;
}

void Core::prepareTextLabel()
{
    tool = &nodeCreator;
    nodeCreator.setTextLabelCreation();
}

void Core::showPorts(bool status)
{
    DrawingMode::needShowPorts = status;
    refreshNetworkMap();
}

void Core::showBandwidth()
{
    DrawingMode::showBandwidth();
    refreshNetworkMap();
}

void Core::showDelay()
{
    DrawingMode::showDelay();
    refreshNetworkMap();
}

void Core::showPacketLossRate()
{
    DrawingMode::showPacketLossRate();
    refreshNetworkMap();
}

void Core::createMininetScript(QString filePath)
{
    IO io;
    io.writeFile(map.createMininetScript(), filePath);
}

void Core::saveNetworkMap(QString filePath)
{
    IO io;
    io.writeFile(map.createXmlDocument(), filePath);
}

void Core::loadNetworkMap(QString filePath)
{
    IO io;
    XmlDeserializer deserializer;
    QString xmlDocument = io.readFile(filePath);
    deserializer.deserialize(xmlDocument, &map);
    elementEditor.handleMouseDown(QPoint(-999, -999));
    refreshNetworkMap();
}

void Core::visualizePath(QList<int> path)
{
    map.unselectLinks();
    map.visualizePath(path);
    refreshNetworkMap();
}

void Core::visualizePaths(QList<QList<int> > paths)
{
    map.unselectLinks();
    map.visualizePaths(paths);
    refreshNetworkMap();
}

void Core::visualizeTree(QList<QList<int> > tree)
{
    map.unselectLinks();
    map.visualizeTree(tree);
    refreshNetworkMap();
}

void Core::visualizeTrees(QList<QList<QList<int> > > trees)
{
    map.unselectLinks();
    map.visualizeTrees(trees);
    refreshNetworkMap();
}

void Core::eraseMarks()
{
    map.unselectLinks();
    map.unselectNodes();
    refreshNetworkMap();
}

void Core::changeMetric(QVector<float> metricData)
{
    map.changeMetric(metricData);
    refreshNetworkMap();
}

void Core::createWeightsMatrix(QString path)
{
    WeightsMatrix matrix;
    IO io;
    QString content = matrix.build(map.getGraphMatrix(), map.getSwitches());
    io.writeFile(content, path);
}

void Core::connectSdnController()
{
    map.connectSdnController();
    refreshNetworkMap();
}

void Core::clearNetworkMap()
{
    elementEditor.handleMouseDown(QPoint(-999, -999));
    map.clear();
    refreshNetworkMap();
}

void Core::runAntColonyAlgorithm(int numAnts, int numIterations, double alpha, double beta, double evaporation, double Q, QString startSwitch, QString endSwitch, int percentage)
{
    if (isAntColonyRunning || antColonyAnimationActive) {
        emit signalShowMessage("Алгоритм муравьиной колонии уже запущен!");
        return;
    }
    isAntColonyRunning = true;
    antColonyAnimationActive = true;
    //ОЧИСТКА ВЫДЕЛЕНИЯ КРАТЧАЙШЕГО ПУТИ НА ТОПОЛОГИИ
    map.unselectLinks();
    map.unselectNodes();
    refreshNetworkMap();

    // Сохраняем параметры для анимации
    antColonyNumAnts = numAnts;
    antColonyNumIterations = numIterations;
    antColonyAlpha = alpha;
    antColonyBeta = beta;
    antColonyEvaporation = evaporation;
    antColonyQ = Q;
    antColonyStartSwitch = startSwitch;
    antColonyEndSwitch = endSwitch;
    AntColonypercentage = percentage;
    antColonyCurrentIter = 0;
    antColonyBestPath.clear();
    antColonyBestLength = std::numeric_limits<double>::max();

    const QList<Host*>& hosts = map.getHosts();
    const QList<Switch*>& switches = map.getSwitches();
    antColonyNodeType.clear();
    QList<Node*> candidates;
    if (hosts.count() >= 2) {
        for (auto* h : hosts) candidates.append(h);
        antColonyNodeType = "host";
    } else if (switches.count() >= 2) {
        for (auto* s : switches) candidates.append(s);
        antColonyNodeType = "switch";
    } else {
        emit signalShowMessage("Требуется как минимум 2 коммутатора для работы!");
        isAntColonyRunning = false;
        antColonyAnimationActive = false;
        return;
    }
    // Используем все коммутаторы для поиска пути
    QList<Switch*> switchesList = map.getSwitches();
    antColonyAllNodes.clear();
    for (Switch* sw : switchesList) antColonyAllNodes.append(static_cast<Node*>(sw));
    antColonyNodeToIdx.clear();
    for (int i = 0; i < antColonyAllNodes.count(); ++i) antColonyNodeToIdx[antColonyAllNodes.at(i)] = i;
    antColonyN = antColonyAllNodes.count();
    if (antColonyN < 2) {
        emit signalShowMessage("Не достаточно узлов для работы!");
        isAntColonyRunning = false;
        antColonyAnimationActive = false;
        return;
    }
    // Найти выбранные коммутаторы среди всех
    antColonyStart = nullptr;
    antColonyEnd = nullptr;
    for (Node* node : antColonyAllNodes) {
        if (node->getName() == antColonyStartSwitch) antColonyStart = node;
        if (node->getName() == antColonyEndSwitch) antColonyEnd = node;
    }
    if (!antColonyStart || !antColonyEnd || antColonyStart == antColonyEnd) {
        emit signalShowMessage("Не выбраны начальный и конечный коммутаторы!");
        isAntColonyRunning = false;
        antColonyAnimationActive = false;
        return;
    }
    auto matrix = map.getGraphMatrix();
    // --- Инициализация феромонов ---
    antColonyPheromone = QVector<QVector<double>>(antColonyN, QVector<double>(antColonyN, 1.0));
    antColonyDistance = QVector<QVector<double>>(antColonyN, QVector<double>(antColonyN, std::numeric_limits<double>::max()));
    for (int i = 0; i < antColonyN; ++i) {
        Node* ni = antColonyAllNodes.at(i);
        auto neighbors = matrix.getNeighbors(ni);
        for (Node* nb : neighbors) {
            int j = antColonyNodeToIdx.value(nb, -1);
            if (j != -1) {
                SSLink* link = dynamic_cast<SSLink*>(matrix.getLink(ni, nb));
                if (link) {
                    antColonyDistance[i][j] = link->getDelay();
                }
            }
        }
    }
    // Запускаем анимацию через QTimer
    if (!antColonyTimer) {
        antColonyTimer = new QTimer(this);
        connect(antColonyTimer, &QTimer::timeout, this, &Core::antColonyAnimationStep);
    }
    antColonyTimer->start(350); // 350 мс задержка
}

void Core::antColonyAnimationStep()
{
    if (antColonyCurrentIter >= antColonyNumIterations) {
        antColonyTimer->stop();
        isAntColonyRunning = false;
        antColonyAnimationActive = false;
        // Финальная визуализация и сообщение
        if (!antColonyBestPath.isEmpty()) {
            QList<int> globalIdPath;
            for (int idx : antColonyBestPath) {
                globalIdPath << antColonyAllNodes[idx]->getGlobalId();
            }
            map.unselectLinks();
            map.unselectNodes();
            map.visualizePath(globalIdPath);
            refreshNetworkMap();
            emit signalShowMessage(QString("Кратчайший путь найден и визуализирован, длина = %1, тип = %2").arg(antColonyBestLength).arg(antColonyNodeType));
            QStringList bestPathStrList;
            for (int idx : antColonyBestPath) bestPathStrList << QString::number(idx);
            emit signalShowMessage(QString("Индексы кратчайшего пути: %1").arg(bestPathStrList.join(", ")));
            for (int idx : antColonyBestPath) {
                emit signalShowMessage(QString("Узел: %1").arg(antColonyAllNodes[idx]->getName()));
            }
        } else {
            emit signalShowMessage("Путь не найден");
        }
        return;
    }
    // Одна итерация алгоритма
    QList<QList<int>> allAntPaths;
    QList<double> allAntLengths;
    for (int ant = 0; ant < antColonyNumAnts; ++ant) {
        QVector<bool> visited(antColonyN, false);
        QList<int> path;
        int current = antColonyNodeToIdx.value(antColonyStart);
        int goal = antColonyNodeToIdx.value(antColonyEnd);
        path.append(current);
        visited[current] = true;
        double pathLength = 0.0;
        for (int steps = 0; steps < antColonyN*2; ++steps) {
            if (current == goal) break;
            QList<int> candidatesIdx;
            for (int j = 0; j < antColonyN; ++j) {
                if (antColonyDistance[current][j] < std::numeric_limits<double>::max() && !visited[j]) {
                    candidatesIdx.append(j);
                }
            }
            if (candidatesIdx.isEmpty()) break;
            QVector<double> probs;
            double sum = 0.0;
            for (int idx = 0; idx < candidatesIdx.count(); ++idx) {
                int j = candidatesIdx.at(idx);
                double tau = pow(antColonyPheromone[current][j], antColonyAlpha);
                double eta = pow(1.0 / antColonyDistance[current][j], antColonyBeta);
                double p = tau * eta;
                probs.append(p);
                sum += p;
            }
            double r = QRandomGenerator::global()->generateDouble() * sum;
            double acc = 0.0;
            int next = candidatesIdx.last();
            for (int idx = 0; idx < candidatesIdx.count(); ++idx) {
                acc += probs[idx];
                if (r <= acc) {
                    next = candidatesIdx.at(idx);
                    break;
                }
            }
            pathLength += antColonyDistance[current][next];
            current = next;
            path.append(current);
            visited[current] = true;
        }
        if (current == antColonyNodeToIdx.value(antColonyEnd)) {
            if (pathLength < antColonyBestLength) {
                antColonyBestLength = pathLength;
                antColonyBestPath = path;
            }
            allAntPaths.append(path);
            allAntLengths.append(pathLength);
        }
    }
    for (int i = 0; i < antColonyN; ++i)
        for (int j = 0; j < antColonyN; ++j)
            antColonyPheromone[i][j] *= (1.0 - antColonyEvaporation);
    for (int k = 0; k < allAntPaths.count(); ++k) {
        const QList<int>& path = allAntPaths.at(k);
        double len = allAntLengths.at(k);
        if (len > 0.0) {
            for (int i = 0; i < path.count() - 1; ++i) {
                int u = path.at(i);
                int v = path.at(i+1);
                antColonyPheromone[u][v] += antColonyQ / len;
                antColonyPheromone[v][u] += antColonyQ / len;
            }
        }
    }
    // Визуализируем текущий лучший путь
    if (!antColonyBestPath.isEmpty()) {
        QList<int> globalIdPath;
        for (int idx : antColonyBestPath) {
            globalIdPath << antColonyAllNodes[idx]->getGlobalId();
        }
        map.unselectLinks();
        map.unselectNodes();
        map.visualizePath(globalIdPath);
        refreshNetworkMap();
        emit signalShowMessage(QString("[Итерация %1/%2] Текущий путь, длина = %3").arg(antColonyCurrentIter+1).arg(antColonyNumIterations).arg(antColonyBestLength));
    }
    antColonyCurrentIter++;
}

void Core::visualizePath(QList<int> path, QColor color)
{
    map.unselectLinks();
    map.visualizePath(path, color);
    refreshNetworkMap();
}

void Core::visualizeColoredPaths(const QList<QList<int>>& paths, const QVector<QColor>& colors)
{
    map.unselectLinks();
    for (int i = 0; i < paths.size(); ++i) {
        QColor color = colors[i % colors.size()];
        map.visualizePath(paths[i], color);
    }
    refreshNetworkMap();
}




