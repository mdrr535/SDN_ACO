#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include "NetworkMapView.h"
#include <QActionGroup>
#include "Core.h"
#include <QString>

namespace Ui
{
class MainWindow;
}

struct PendingAntColonyParams {
    int numAnts = 0;
    int numIterations = 0;
    double alpha = 1.0;
    double beta = 1.0;
    double evaporation = 0.5;
    double Q = 100.0;
    int startIdx = 0;
    int endIdx = 0;
    int percentage = 0;
    bool valid = false;
    void invalidate() { valid = false; }
    bool isValid() const { return valid; }
    bool isTree = false;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setCore(Core* coreInstance);
    void runAntColonyViaRest(int numAnts, int numIterations, double alpha, double beta, double evaporation, double Q, int startIdx, int endIdx, const QString& metricFilePath, int percentage, bool treeMode);
    void startAntColonyStatusPolling();
    void runAntColonyTreeViaRest(int numAnts, int numIterations, double alpha, double beta, double evaporation, double Q, int startIdx, const QString& metricFilePath, int percentage);
    void startAntColonyTreeStatusPolling();

private slots:
    void on_actionNew_triggered();
    void on_actionMake_Full_Connection_triggered();
    void on_actionSdnController_triggered();
    void on_actionHost_triggered();
    void on_actionSwitch_triggered();
    void on_actionLink_triggered();
    void on_actionText_triggered();
    void on_actionEdit_triggered();
    void mouseLeftButtonReleaseEventOccured(QPoint cursorPosition);
    void mouseLeftButtonPressEventOccured(QPoint cursorPosition);
    void mouseMoveEventOccured(QPoint cursorPosition);
    void mouseDoubleClickEventOccured(QPoint cursorPosition);
    void on_actionShowPorts_triggered(bool checked);
    void on_actionDisplayDelay_triggered();
    void on_actionDisplayBandwidth_triggered();
    void on_actionDisplayPacketLoss_triggered();
    void on_actionSaveAs_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionCreateMnDataFile_triggered();
    void on_actionExit_triggered();
    void on_actionWeights_Matrix_triggered();
    void on_actionRun_Ant_Colony_triggered();

signals:
    void signalConnectSdnController();
    void signalClearNetworkMap();

    void signalHandleMouseReleaseEvent(QPoint);
    void signalHandleMousePressEvent(QPoint);
    void signalHandleMouseMoveEvent(QPoint);
    void signalHandleDoubleClickEvent(QPoint);
    void signalHandleKeyDeletePressEvent();

    void signalChangeStateToEdit();
    void signalPrepareSdnController();
    void signalPrepareHost();
    void signalPrepareSwitch();
    void signalPrepareLink();
    void signalPrepareTextLabel();

    void signalShowPorts(bool);
    void signalShowBandwidth();
    void signalShowDelay();
    void signalShowPacketLossRate();

    void signalCreateMininetScript(QString);
    void signalCreateWeightMatrix(QString);

    void loadRoutes(QString);
    void showRoute(int);
    void hideRoute(int);

    void signalSaveNetworkMap(QString);
    void signalLoadNetworkMap(QString);

public slots:
    void visualizePath(QList<int> path);
    void refreshNetworkMapView(QPixmap);
    void showMessage(QString message);
    void onWeightMatrixCreated(const QString& filePath);

private:
    Ui::MainWindow *ui;
    QActionGroup *metricGroupInMenu;
    QActionGroup *toolsGroupInMenu;
    QActionGroup *instrumentGroupInMenu;
    QActionGroup *toolsGroup;
    QAction *actionSdnController;
    QAction *actionHost;
    QAction *actionSwitch;
    QAction *actionLink;
    QAction *actionEdit;
    QAction *actionText;
    QString openedFilePath;

    QToolBar *toolsToolBar;
    QToolBar *utilitiesToolBar;
    Core *core;

    PendingAntColonyParams pendingAntColonyParams;

private:
    void setupComponents();
    void setupInstrumentsToolBar();
    void setupUtilitiesToolBar();
    void prepareTerminal();
    QString getFileNameFromOpenedFilePath();
    void updateWindowTitle();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
