#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QFileDialog>
#include <QTime>
#include "Core.h"
#include "AntAlgorithm.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>

MainWindow::MainWindow(QWidget * parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), openedFilePath(QString())
{
    ui->setupUi(this);
    setupComponents();
    QObject::connect(ui->networkMapView, SIGNAL(signalMouseLeftButtonReleased(QPoint)), this, SLOT(mouseLeftButtonReleaseEventOccured(QPoint)));
    QObject::connect(ui->networkMapView, SIGNAL(signalMouseLeftButtonPressed(QPoint)), this, SLOT(mouseLeftButtonPressEventOccured(QPoint)));
    QObject::connect(ui->networkMapView, SIGNAL(signalMouseMoved(QPoint)), this, SLOT(mouseMoveEventOccured(QPoint)));
    QObject::connect(ui->networkMapView, SIGNAL(signalMouseDoubleClicked(QPoint)), this, SLOT(mouseDoubleClickEventOccured(QPoint)));
}

void MainWindow::setupComponents()
{
    metricGroupInMenu = new QActionGroup(this);
    toolsGroupInMenu = new QActionGroup(this);
    toolsGroup = new QActionGroup(this);
    metricGroupInMenu->addAction(ui->actionDisplayDelay);
    metricGroupInMenu->addAction(ui->actionDisplayBandwidth);
    metricGroupInMenu->addAction(ui->actionDisplayPacketLoss);
    toolsGroupInMenu->addAction(ui->actionSdnController);
    toolsGroupInMenu->addAction(ui->actionHost);
    toolsGroupInMenu->addAction(ui->actionSwitch);
    toolsGroupInMenu->addAction(ui->actionLink);
    toolsGroupInMenu->addAction(ui->actionEdit);

    setupInstrumentsToolBar();
    setupUtilitiesToolBar();
}

void MainWindow::setupInstrumentsToolBar()
{
    toolsToolBar = new QToolBar("toolsToolBar");
    toolsToolBar->setIconSize(QSize(64, 64));
    actionSdnController = toolsToolBar->addAction(QPixmap(":images/controller.png"), "Controller (C)", this, SLOT(on_actionSdnController_triggered()));
    actionSdnController->setCheckable(true);
    toolsGroup->addAction(actionSdnController);
    actionSwitch = toolsToolBar->addAction(QPixmap(":images/switch.png"), "Switch (S)", this, SLOT(on_actionSwitch_triggered()));
    actionSwitch->setCheckable(true);
    toolsGroup->addAction(actionSwitch);
    actionHost = toolsToolBar->addAction(QPixmap(":images/host.png"), "Host (H)", this, SLOT(on_actionHost_triggered()));
    actionHost->setCheckable(true);
    toolsGroup->addAction(actionHost);
    actionLink = toolsToolBar->addAction(QPixmap(":images/link.png"), "Link (L)", this, SLOT(on_actionLink_triggered()));
    actionLink->setCheckable(true);
    toolsGroup->addAction(actionLink);
    actionText = toolsToolBar->addAction(QPixmap(":images/text.png"), "Text (T)", this, SLOT(on_actionText_triggered()));
    actionText->setCheckable(true);
    toolsGroup->addAction(actionText);
    toolsToolBar->addSeparator();
    actionEdit = toolsToolBar->addAction(QPixmap(":images/edit.png"), "Edit (E)", this, SLOT(on_actionEdit_triggered()));
    actionEdit->setCheckable(true);
    actionEdit->setChecked(true);
    toolsGroup->addAction(actionEdit);
    addToolBar(Qt::TopToolBarArea, toolsToolBar);
}

void MainWindow::setupUtilitiesToolBar()
{
    utilitiesToolBar = new QToolBar("utilitiesToolBar");
    utilitiesToolBar->setIconSize(QSize(64, 64));
    utilitiesToolBar->addAction(QPixmap(":images/new.png"), "New", this, SLOT(on_actionNew_triggered()));
    utilitiesToolBar->addAction(QPixmap(":images/open.png"), "Open...", this, SLOT(on_actionOpen_triggered()));
    utilitiesToolBar->addAction(QPixmap(":images/save.png"), "Save...", this, SLOT(on_actionSave_triggered()));
    utilitiesToolBar->addAction(QPixmap(":images/save_as.png"), "Save as...", this, SLOT(on_actionSaveAs_triggered()));
    utilitiesToolBar->addAction(QPixmap(":images/python.png"), "Export Mininet Script", this, SLOT(on_actionCreateMnDataFile_triggered()));
    utilitiesToolBar->addSeparator();
    utilitiesToolBar->addAction(QPixmap(":images/fullConnection.png"), "Full Connection", this, SLOT(on_actionMake_Full_Connection_triggered()));
    utilitiesToolBar->addAction(QPixmap(":images/ant.png"), "Run Ant Colony", this, SLOT(on_actionRun_Ant_Colony_triggered()));
    addToolBar(Qt::TopToolBarArea, utilitiesToolBar);
}

void MainWindow::prepareTerminal()
{
    ui->terminal->clear();
}

QString MainWindow::getFileNameFromOpenedFilePath()
{
    return openedFilePath.split("/").last();
}

void MainWindow::updateWindowTitle()
{
    this->setWindowTitle(QString("SDN ACO [") +
                         getFileNameFromOpenedFilePath() +
                         QString("]"));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int keyCode = event->key();
    switch(keyCode)
    {
        case Qt::Key_Delete:
            emit signalHandleKeyDeletePressEvent();
            break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSdnController_triggered()
{
    ui->actionSdnController->setChecked(true);
    actionSdnController->setChecked(true);
    emit signalPrepareSdnController();
}

void MainWindow::on_actionHost_triggered()
{
    ui->actionHost->setChecked(true);
    actionHost->setChecked(true);
    emit signalPrepareHost();
}

void MainWindow::on_actionSwitch_triggered()
{
    ui->actionSwitch->setChecked(true);
    actionSwitch->setChecked(true);
    emit signalPrepareSwitch();
}

void MainWindow::on_actionLink_triggered()
{
    ui->actionLink->setChecked(true);
    actionLink->setChecked(true);
    emit signalPrepareLink();
}

void MainWindow::on_actionEdit_triggered()
{
    ui->actionEdit->setChecked(true);
    actionEdit->setChecked(true);
    emit signalChangeStateToEdit();
}

void MainWindow::on_actionText_triggered()
{
    ui->actionText->setChecked(true);
    actionText->setChecked(true);
    emit signalPrepareTextLabel();
}

void MainWindow::on_actionShowPorts_triggered(bool checked)
{
    emit signalShowPorts(checked);
}

void MainWindow::on_actionDisplayDelay_triggered()
{
    emit signalShowDelay();
}

void MainWindow::on_actionDisplayBandwidth_triggered()
{
    emit signalShowBandwidth();
}

void MainWindow::on_actionDisplayPacketLoss_triggered()
{
    emit signalShowPacketLossRate();
}

void MainWindow::on_actionCreateMnDataFile_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    "Save MiniNet Script",
                                                    "topology.sdn.py",
                                                    "Python files (*.py)");
    if (!filePath.isEmpty())
    {
        emit signalCreateMininetScript(filePath);
    }
}

void MainWindow::mouseLeftButtonReleaseEventOccured(QPoint cursorPosition)
{
    emit signalHandleMouseReleaseEvent(cursorPosition);
}

void MainWindow::mouseLeftButtonPressEventOccured(QPoint cursorPosition)
{
    emit signalHandleMousePressEvent(mapFrom(this, cursorPosition));
}

void MainWindow::mouseMoveEventOccured(QPoint cursorPosition)
{
    emit signalHandleMouseMoveEvent(cursorPosition);
}

void MainWindow::mouseDoubleClickEventOccured(QPoint cursorPosition)
{
    emit signalHandleDoubleClickEvent(cursorPosition);
}

void MainWindow::refreshNetworkMapView(QPixmap image)
{
    ui->networkMapView->refresh(image);
}

void MainWindow::showMessage(QString message)
{
    ui->terminal->append(QTime::currentTime().toString() +
                         QString(" [Controller] ") + message);
}

void MainWindow::on_actionSaveAs_triggered()
{
    openedFilePath = QFileDialog::getSaveFileName(this,
                                                  "Save topology",
                                                  "topology.sdn.xml",
                                                  "Xml files (*.xml)");
    if (!openedFilePath.isEmpty())
    {
        emit signalSaveNetworkMap(openedFilePath);
        updateWindowTitle();
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (openedFilePath.isEmpty())
    {
        on_actionSaveAs_triggered();
    }
    else
    {
        emit signalSaveNetworkMap(openedFilePath);
        updateWindowTitle();
    }
}

void MainWindow::on_actionOpen_triggered()
{
    openedFilePath = QFileDialog::getOpenFileName(this,
                                                  "Open topology file",
                                                  "topology.sdn.xml",
                                                  "Xml files (*.xml)");
    if (!openedFilePath.isEmpty())
    {
        emit signalLoadNetworkMap(openedFilePath);
        updateWindowTitle();
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionWeights_Matrix_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    "Save Metric Data",
                                                    "metric_data.txt",
                                                    "Text files (*.txt)");
    if (!filePath.isEmpty())
    {
        emit signalCreateWeightMatrix(filePath);
    }
}

void MainWindow::runAntColonyViaRest(int numAnts, int numIterations, double alpha, double beta, double evaporation, double Q, int startIdx, int endIdx, const QString& metricFilePath, int percentage, bool treeMode)
{
    QFile file(metricFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        showMessage("Не удалось открыть файл метрик!");
        return;
    }
    QString metricContent = file.readAll();
    file.close();

    QJsonObject json;
    json["num_ants"] = numAnts;
    json["num_iterations"] = numIterations;
    json["alpha"] = alpha;
    json["beta"] = beta;
    json["evaporation"] = evaporation;
    json["Q"] = Q;
    json["start"] = startIdx;
    json["end"] = endIdx;
    json["metric_content"] = metricContent;
    json["percentage"] = percentage;
    QUrl url;
    if (!treeMode) {
        json["end"] = endIdx;
        url = QUrl("http://127.0.0.1:8080/antcolony/start");
    } else {
        url = QUrl("http://127.0.0.1:8080/antcolony/tree");
    }
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkReply* reply = manager->post(request, QJsonDocument(json).toJson());
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            showMessage("Муравьиный алгоритм запущен на контроллере!");
            startAntColonyStatusPolling();
        } else {
            showMessage("Ошибка запуска алгоритма: " + reply->errorString());
        }
        reply->deleteLater();
    });
}

void MainWindow::startAntColonyStatusPolling()
{
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this, timer]() {
        QNetworkRequest request(QUrl("http://127.0.0.1:8080/antcolony/status"));
        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        QNetworkReply* reply = manager->get(request);
        connect(reply, &QNetworkReply::finished, this, [this, reply, timer]() {
            if (reply->error() == QNetworkReply::NoError) {
                QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
                QJsonObject obj = doc.object();
                QVariantList bestPath = obj["best_path"].toArray().toVariantList();
                auto switches = core->getSwitches();
                QList<int> path;
                for (const QVariant& v : bestPath) {
                    int idx = v.toInt();
                    if (idx >= 0 && idx < switches.size()) {
                        path << switches[idx]->getGlobalId();
                    }
                }
                // Визуализируем путь красным цветом
                if (!path.isEmpty()) {
                    core->visualizePath(path, Qt::red);
                }
                // Новое: отображение всех путей и вывод в терминал
                bool visualized = false;
                if (obj.contains("all_paths")) {
                    QJsonArray allPathsArray = obj["all_paths"].toArray();
                    QList<QList<int>> allPaths;
                    for (const QJsonValue& val : allPathsArray) {
                        QJsonArray arr = val.toArray();
                        QList<int> p;
                        for (const QJsonValue& v : arr) {
                            int idx = v.toInt();
                            if (idx >= 0 && idx < switches.size()) {
                                p << switches[idx]->getGlobalId();
                            }
                        }
                        allPaths.append(p);
                    }
                    if (!allPaths.isEmpty()) {
                        if (core) core->visualizeTree(allPaths);
                        visualized = true;
                    }
                }
                // В любом случае визуализируем лучший путь
                visualizePath(path);
                // Выводим длину пути, если есть
                double bestLength = obj.contains("best_length") ? obj["best_length"].toDouble() : (obj.contains("length") ? obj["length"].toDouble() : -1);
                if (bestLength >= 0) {
                    showMessage(QString("Длина пути на итерации: %1").arg(bestLength));
                }
                if (obj["finished"].toBool()) {
                    timer->stop();
                    timer->deleteLater();
                    showMessage("Муравьиный алгоритм завершён!");
                    // Итоговый путь и длина
                    QStringList pathNames;
                    for (int v : path) {
                        for (auto* sw : switches) {
                            if (sw->getGlobalId() == v) {
                                pathNames << sw->getName();
                                break;
                            }
                        }
                    }
                    showMessage(QString("Итоговый путь: %1").arg(pathNames.join(" -> ")));
                    if (bestLength >= 0) {
                        showMessage(QString("Длина итогового пути: %1").arg(bestLength));
                    }
                }
            }
            reply->deleteLater();
        });
    });
    timer->start(350); // 350 мс, как в анимации
}

void MainWindow::on_actionRun_Ant_Colony_triggered()
{
    QStringList switchNames;
    for (auto* sw : core->getSwitches()) {
        switchNames << sw->getName();
    }
    AntAlgorithmDialog dlg(switchNames, this);

    if (dlg.exec() == QDialog::Accepted) {
        pendingAntColonyParams.numAnts = dlg.getNumAnts();
        pendingAntColonyParams.numIterations = dlg.getNumIterations();
        pendingAntColonyParams.alpha = dlg.getAlpha();
        pendingAntColonyParams.beta = dlg.getBeta();
        pendingAntColonyParams.evaporation = dlg.getEvaporation();
        pendingAntColonyParams.Q = dlg.getQ();
        pendingAntColonyParams.startIdx = switchNames.indexOf(dlg.getStartSwitch());
        pendingAntColonyParams.endIdx = switchNames.indexOf(dlg.getEndSwitch());
        pendingAntColonyParams.percentage = dlg.getPercentage();
        pendingAntColonyParams.isTree = dlg.isTreeMode(); // Сохраняем режим дерева
        pendingAntColonyParams.valid = true;

        QString tempMetricFile = QDir::temp().filePath("metric_data.txt");
        emit signalCreateWeightMatrix(tempMetricFile);
    }
}

void MainWindow::setCore(Core* coreInstance)
{
    core = coreInstance;
    QObject::connect(core, SIGNAL(signalShowMessage(QString)), this, SLOT(showMessage(QString)));
}
void MainWindow::on_actionMake_Full_Connection_triggered()
{
    emit signalConnectSdnController();
}

void MainWindow::on_actionNew_triggered()
{
    emit signalClearNetworkMap();
}
void MainWindow::onWeightMatrixCreated(const QString& filePath)
{
    if (pendingAntColonyParams.isValid()) {
        if (pendingAntColonyParams.isTree) {
            // Режим дерева - запускаем алгоритм для дерева
            runAntColonyTreeViaRest(
                pendingAntColonyParams.numAnts,
                pendingAntColonyParams.numIterations,
                pendingAntColonyParams.alpha,
                pendingAntColonyParams.beta,
                pendingAntColonyParams.evaporation,
                pendingAntColonyParams.Q,
                pendingAntColonyParams.startIdx,
                filePath,
                pendingAntColonyParams.percentage
            );
        } else {
            // Режим одного пути
            runAntColonyViaRest(
                pendingAntColonyParams.numAnts,
                pendingAntColonyParams.numIterations,
                pendingAntColonyParams.alpha,
                pendingAntColonyParams.beta,
                pendingAntColonyParams.evaporation,
                pendingAntColonyParams.Q,
                pendingAntColonyParams.startIdx,
                pendingAntColonyParams.endIdx,
                filePath,
                pendingAntColonyParams.percentage,
                pendingAntColonyParams.isTree
            );
        }
        pendingAntColonyParams.invalidate();
    }
}

void MainWindow::visualizePath(QList<int> path)
{
    if (core) core->visualizePath(path);
}


void MainWindow::startAntColonyTreeStatusPolling()
{
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this, timer]() {
        QNetworkRequest request(QUrl("http://127.0.0.1:8080/antcolony/status_tree"));
        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        QNetworkReply* reply = manager->get(request);
        connect(reply, &QNetworkReply::finished, this, [this, reply, timer]() {
            if (reply->error() == QNetworkReply::NoError) {
                QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
                QJsonObject obj = doc.object();

                // Получаем список рёбер дерева
                QJsonArray edgesArray = obj["edges"].toArray();
                QList<QList<int>> treeEdges;
                auto switches = core->getSwitches();
                for (const QJsonValue& edgeVal : edgesArray) {
                    QJsonArray edgeArr = edgeVal.toArray();
                    if (edgeArr.size() == 2) {
                        int idx0 = edgeArr[0].toInt();
                        int idx1 = edgeArr[1].toInt();
                        if (idx0 >= 0 && idx0 < switches.size() && idx1 >= 0 && idx1 < switches.size()) {
                            QList<int> edge;
                            edge << switches[idx0]->getGlobalId();
                            edge << switches[idx1]->getGlobalId();
                            treeEdges.append(edge);
                        }
                    }
                }
                // Если сервер вернул all_paths, визуализируем каждый путь своим цветом
                if (obj.contains("all_paths")) {
                    QJsonArray allPathsArray = obj["all_paths"].toArray();
                    QList<QList<int>> allPaths;
                    for (const QJsonValue& val : allPathsArray) {
                        QJsonArray arr = val.toArray();
                        QList<int> p;
                        for (const QJsonValue& v : arr) {
                            int idx = v.toInt();
                            if (idx >= 0 && idx < switches.size()) {
                                p << switches[idx]->getGlobalId();
                            }
                        }
                        if (!p.isEmpty()) allPaths.append(p);
                    }
                    QVector<QColor> colors(allPaths.size(), Qt::red);
                    if (core) core->visualizeColoredPaths(allPaths, colors);
                    // Выводить путь до каждой вершины и длину в терминал (по задержкам)
                    auto graphMatrix = core->getGraphMatrix();
                    QHash<int, Node*> idToNode;
                    for (auto* sw : switches) {
                        idToNode[sw->getGlobalId()] = sw;
                    }
                    for (int i = 0; i < allPaths.size(); ++i) {
                        const QList<int>& path = allPaths[i];
                        QStringList pathNames;
                        for (int v : path) {
                            for (auto* sw : switches) {
                                if (sw->getGlobalId() == v) {
                                    pathNames << sw->getName();
                                    break;
                                }
                            }
                        }
                        double length = 0.0;
                        for (int j = 0; j < path.size() - 1; ++j) {
                            Node* n1 = idToNode.value(path[j], nullptr);
                            Node* n2 = idToNode.value(path[j+1], nullptr);
                            if (n1 && n2) {
                                SSLink* link = graphMatrix.getLink(n1, n2);
                                if (link) length += link->getDelay();
                            }
                        }
                        if (!pathNames.isEmpty()) {
                            showMessage(QString("Путь: %1 | Длина: %2").arg(pathNames.join(" -> ")).arg(length));
                        }
                    }
                } else {
                    // Визуализируем дерево как обычно
                    if (core) core->visualizeTree(treeEdges);
                }
                if (obj["finished"].toBool()) {
                    timer->stop();
                    timer->deleteLater();
                    showMessage("Построение дерева путей завершено!");
                }
            }
            reply->deleteLater();
        });
    });
    timer->start(350);
}

void MainWindow::runAntColonyTreeViaRest(int numAnts, int numIterations, double alpha, double beta, double evaporation, double Q, int startIdx, const QString& metricFilePath, int percentage)
{
    QFile file(metricFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        showMessage("Не удалось открыть файл метрик!");
        return;
    }
    QString metricContent = file.readAll();
    file.close();

    QJsonObject json;
    json["num_ants"] = numAnts;
    json["num_iterations"] = numIterations;
    json["alpha"] = alpha;
    json["beta"] = beta;
    json["evaporation"] = evaporation;
    json["Q"] = Q;
    json["start"] = startIdx;
    json["percentage"] = percentage;
    json["metric_content"] = metricContent;

    QNetworkRequest request(QUrl("http://127.0.0.1:8080/antcolony/tree"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkReply* reply = manager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            showMessage("Построение дерева путей запущено на контроллере!");
            startAntColonyTreeStatusPolling();
        } else {
            showMessage("Ошибка запуска алгоритма дерева: " + reply->errorString());
        }
        reply->deleteLater();
    });
}
