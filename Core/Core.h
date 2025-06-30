/* Core:
 * - monitores user operations
 */

#ifndef CORE_H
#define CORE_H

#include <QObject>
#include "NetworkMap.h"
#include "ElementEditor.h"
#include "NodeCreator.h"
#include "LinkCreator.h"
#include <QTimer>
#include <QVector>
#include <QList>
#include <QString>
#include <QHash>
#include <QColor>

class Tool;

class Core : public QObject
{
    Q_OBJECT

public:
    explicit Core(QObject *parent = 0);

    void refreshNetworkMap();

    QList<Switch*> getSwitches() const { return map.getSwitches(); }

    CommutationMatrix<SSLink> getGraphMatrix() const { return map.getGraphMatrix(); }

private:
    NetworkMap map;

    Tool *tool;
    NodeCreator nodeCreator;
    LinkCreator linkCreator;
    ElementEditor elementEditor;

    bool isAntColonyRunning = false;

    // Для анимации муравьиного алгоритма
    QTimer* antColonyTimer = nullptr;
    int antColonyCurrentIter = 0;
    int antColonyNumIterations = 0;
    int antColonyNumAnts = 0;
    double antColonyAlpha = 1.0;
    double antColonyBeta = 1.0;
    double antColonyEvaporation = 0.5;
    double antColonyQ = 100.0;
    int AntColonypercentage = 0;
    QString antColonyStartSwitch;
    QString antColonyEndSwitch;
    QList<Node*> antColonyAllNodes;
    QHash<Node*, int> antColonyNodeToIdx;
    QVector<QVector<double>> antColonyPheromone;
    QVector<QVector<double>> antColonyDistance;
    Node* antColonyStart = nullptr;
    Node* antColonyEnd = nullptr;
    int antColonyN = 0;
    QList<int> antColonyBestPath;
    double antColonyBestLength = 0.0;
    QString antColonyNodeType;
    bool antColonyAnimationActive = false;

signals:
    void signalRefreshNetworkMapView(QPixmap);
    void signalShowMessage(QString message);

public slots:
    void connectSdnController();
    void clearNetworkMap();

    void handleMouseReleaseEvent(QPoint);
    void handleMousePressEvent(QPoint);
    void handleMouseMoveEvent(QPoint);
    void handleDoubleClickEvent(QPoint);
    void handleKeyDeletePressEvent();

    void changeStateToEdit();
    void prepareSdnController();
    void prepareHost();
    void prepareSwitch();
    void prepareLink();
    void prepareTextLabel();

    void showPorts(bool);
    void showBandwidth();
    void showDelay();
    void showPacketLossRate();

    void createMininetScript(QString);
    void createWeightsMatrix(QString path);

    void saveNetworkMap(QString);
    void loadNetworkMap(QString);

    void visualizePath(QList<int> path);
    void visualizePaths(QList<QList<int> > paths);
    void visualizeTree(QList<QList<int> > tree);
    void visualizeTrees(QList<QList<QList<int> > > trees);
    void eraseMarks();

    void changeMetric(QVector<float> metricData);

    void runAntColonyAlgorithm(int numAnts, int numIterations, double alpha, double beta, double evaporation, double Q, QString startSwitch, QString endSwitch, int percentage);

    void antColonyAnimationStep();

    void visualizePath(QList<int> path, QColor color);

    void visualizeColoredPaths(const QList<QList<int>>& paths, const QVector<QColor>& colors);
};

#endif // CORE_H
