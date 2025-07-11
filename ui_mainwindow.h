/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "NetworkMapView.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionCreateMnDataFile;
    QAction *actionShowPorts;
    QAction *actionCreateNetworkMap;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionDisplayDelay;
    QAction *actionDisplayBandwidth;
    QAction *actionDisplayPacketLoss;
    QAction *actionHost;
    QAction *actionSwitch;
    QAction *actionCreate;
    QAction *actionDelete;
    QAction *actionMove;
    QAction *actionEdit;
    QAction *actionSdnController;
    QAction *actionNew;
    QAction *actionText;
    QAction *actionWeights_Matrix;
    QAction *actionLink;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollContents;
    QGridLayout *gridLayout_2;
    NetworkMapView *networkMapView;
    QTextBrowser *terminal;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuConverter;
    QMenu *menuOptions;
    QMenu *menuShow_metric;
    QMenu *menuInstruments;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModality::NonModal);
        MainWindow->resize(1000, 726);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/controller.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionCreateMnDataFile = new QAction(MainWindow);
        actionCreateMnDataFile->setObjectName(QString::fromUtf8("actionCreateMnDataFile"));
        actionShowPorts = new QAction(MainWindow);
        actionShowPorts->setObjectName(QString::fromUtf8("actionShowPorts"));
        actionShowPorts->setCheckable(true);
        actionCreateNetworkMap = new QAction(MainWindow);
        actionCreateNetworkMap->setObjectName(QString::fromUtf8("actionCreateNetworkMap"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionDisplayDelay = new QAction(MainWindow);
        actionDisplayDelay->setObjectName(QString::fromUtf8("actionDisplayDelay"));
        actionDisplayDelay->setCheckable(true);
        actionDisplayDelay->setChecked(true);
        actionDisplayBandwidth = new QAction(MainWindow);
        actionDisplayBandwidth->setObjectName(QString::fromUtf8("actionDisplayBandwidth"));
        actionDisplayBandwidth->setCheckable(true);
        actionDisplayPacketLoss = new QAction(MainWindow);
        actionDisplayPacketLoss->setObjectName(QString::fromUtf8("actionDisplayPacketLoss"));
        actionDisplayPacketLoss->setCheckable(true);
        actionHost = new QAction(MainWindow);
        actionHost->setObjectName(QString::fromUtf8("actionHost"));
        actionHost->setCheckable(true);
        actionHost->setChecked(false);
        actionSwitch = new QAction(MainWindow);
        actionSwitch->setObjectName(QString::fromUtf8("actionSwitch"));
        actionSwitch->setCheckable(true);
        actionCreate = new QAction(MainWindow);
        actionCreate->setObjectName(QString::fromUtf8("actionCreate"));
        actionCreate->setCheckable(true);
        actionCreate->setChecked(true);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionDelete->setCheckable(true);
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName(QString::fromUtf8("actionMove"));
        actionMove->setCheckable(true);
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        actionEdit->setCheckable(true);
        actionEdit->setChecked(true);
        actionSdnController = new QAction(MainWindow);
        actionSdnController->setObjectName(QString::fromUtf8("actionSdnController"));
        actionSdnController->setCheckable(true);
        actionSdnController->setChecked(false);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionText = new QAction(MainWindow);
        actionText->setObjectName(QString::fromUtf8("actionText"));
        actionWeights_Matrix = new QAction(MainWindow);
        actionWeights_Matrix->setObjectName(QString::fromUtf8("actionWeights_Matrix"));
        actionLink = new QAction(MainWindow);
        actionLink->setObjectName(QString::fromUtf8("actionLink"));
        actionLink->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setWidgetResizable(true);
        scrollContents = new QWidget();
        scrollContents->setObjectName(QString::fromUtf8("scrollContents"));
        scrollContents->setGeometry(QRect(0, 0, 1366, 1024));
        gridLayout_2 = new QGridLayout(scrollContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        networkMapView = new NetworkMapView(scrollContents);
        networkMapView->setObjectName(QString::fromUtf8("networkMapView"));
        sizePolicy1.setHeightForWidth(networkMapView->sizePolicy().hasHeightForWidth());
        networkMapView->setSizePolicy(sizePolicy1);
        networkMapView->setMinimumSize(QSize(1366, 1024));
        networkMapView->setMouseTracking(false);
        networkMapView->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        networkMapView->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);

        gridLayout_2->addWidget(networkMapView, 0, 0, 1, 1);

        scrollArea->setWidget(scrollContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        terminal = new QTextBrowser(centralWidget);
        terminal->setObjectName(QString::fromUtf8("terminal"));
        terminal->setMaximumSize(QSize(16777215, 200));

        gridLayout->addWidget(terminal, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuConverter = new QMenu(menuBar);
        menuConverter->setObjectName(QString::fromUtf8("menuConverter"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuShow_metric = new QMenu(menuOptions);
        menuShow_metric->setObjectName(QString::fromUtf8("menuShow_metric"));
        menuInstruments = new QMenu(menuBar);
        menuInstruments->setObjectName(QString::fromUtf8("menuInstruments"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuConverter->menuAction());
        menuBar->addAction(menuInstruments->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuConverter->addAction(actionCreateMnDataFile);
        menuConverter->addAction(actionWeights_Matrix);
        menuOptions->addAction(actionShowPorts);
        menuOptions->addAction(menuShow_metric->menuAction());
        menuShow_metric->addAction(actionDisplayDelay);
        menuShow_metric->addAction(actionDisplayBandwidth);
        menuShow_metric->addAction(actionDisplayPacketLoss);
        menuInstruments->addAction(actionSdnController);
        menuInstruments->addAction(actionSwitch);
        menuInstruments->addAction(actionHost);
        menuInstruments->addAction(actionLink);
        menuInstruments->addAction(actionText);
        menuInstruments->addAction(actionEdit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SDN Topology", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open ...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionCreateMnDataFile->setText(QApplication::translate("MainWindow", "Mininet Script ...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCreateMnDataFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowPorts->setText(QApplication::translate("MainWindow", "Show ports", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShowPorts->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionCreateNetworkMap->setText(QApplication::translate("MainWindow", "Network Map ...", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSaveAs->setText(QApplication::translate("MainWindow", "Save as ...", nullptr));
        actionDisplayDelay->setText(QApplication::translate("MainWindow", "Delay", nullptr));
#ifndef QT_NO_SHORTCUT
        actionDisplayDelay->setShortcut(QApplication::translate("MainWindow", "Shift+D", nullptr));
#endif // QT_NO_SHORTCUT
        actionDisplayBandwidth->setText(QApplication::translate("MainWindow", "Bandwidth", nullptr));
#ifndef QT_NO_SHORTCUT
        actionDisplayBandwidth->setShortcut(QApplication::translate("MainWindow", "Shift+B", nullptr));
#endif // QT_NO_SHORTCUT
        actionDisplayPacketLoss->setText(QApplication::translate("MainWindow", "Packet Loss Rate", nullptr));
#ifndef QT_NO_SHORTCUT
        actionDisplayPacketLoss->setShortcut(QApplication::translate("MainWindow", "Shift+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionHost->setText(QApplication::translate("MainWindow", "Host", nullptr));
#ifndef QT_NO_SHORTCUT
        actionHost->setShortcut(QApplication::translate("MainWindow", "H", nullptr));
#endif // QT_NO_SHORTCUT
        actionSwitch->setText(QApplication::translate("MainWindow", "Switch", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSwitch->setShortcut(QApplication::translate("MainWindow", "S", nullptr));
#endif // QT_NO_SHORTCUT
        actionCreate->setText(QApplication::translate("MainWindow", "Create", nullptr));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        actionMove->setText(QApplication::translate("MainWindow", "Move", nullptr));
        actionEdit->setText(QApplication::translate("MainWindow", "Edit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionEdit->setShortcut(QApplication::translate("MainWindow", "E", nullptr));
#endif // QT_NO_SHORTCUT
        actionSdnController->setText(QApplication::translate("MainWindow", "Controller", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSdnController->setShortcut(QApplication::translate("MainWindow", "C", nullptr));
#endif // QT_NO_SHORTCUT
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionText->setText(QApplication::translate("MainWindow", "Text", nullptr));
#ifndef QT_NO_SHORTCUT
        actionText->setShortcut(QApplication::translate("MainWindow", "T", nullptr));
#endif // QT_NO_SHORTCUT
        actionWeights_Matrix->setText(QApplication::translate("MainWindow", "Metric Data ...", nullptr));
        actionLink->setText(QApplication::translate("MainWindow", "Link", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLink->setShortcut(QApplication::translate("MainWindow", "L", nullptr));
#endif // QT_NO_SHORTCUT
        networkMapView->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuConverter->setTitle(QApplication::translate("MainWindow", "Export", nullptr));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", nullptr));
        menuShow_metric->setTitle(QApplication::translate("MainWindow", "Show metric", nullptr));
        menuInstruments->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
