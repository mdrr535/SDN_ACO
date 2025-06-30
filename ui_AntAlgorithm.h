/********************************************************************************
** Form generated from reading UI file 'AntAlgorithm.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANTALGORITHM_H
#define UI_ANTALGORITHM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AntAlgorithmDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *labelNumAnts;
    QLabel *labelEvaporation;
    QDoubleSpinBox *doubleEvaporation;
    QDoubleSpinBox *doubleQ;
    QDialogButtonBox *buttonBox;
    QComboBox *comboEnd;
    QLabel *labelEnd;
    QDoubleSpinBox *doubleBeta;
    QComboBox *comboStart;
    QLabel *labelAlpha;
    QSpinBox *spinNumAnts;
    QLabel *labelStart;
    QDoubleSpinBox *doubleAlpha;
    QLabel *labelBeta;
    QLabel *labelQ;
    QLabel *labelNumIterations;
    QSpinBox *spinNumIterations;
    QLabel *labelPercentage;
    QSpinBox *spinPercentage;
    QCheckBox *checkTreeMode;

    void setupUi(QDialog *AntAlgorithmDialog)
    {
        if (AntAlgorithmDialog->objectName().isEmpty())
            AntAlgorithmDialog->setObjectName("AntAlgorithmDialog");
        AntAlgorithmDialog->resize(684, 480);
        gridLayout = new QGridLayout(AntAlgorithmDialog);
        gridLayout->setObjectName("gridLayout");
        labelNumAnts = new QLabel(AntAlgorithmDialog);
        labelNumAnts->setObjectName("labelNumAnts");

        gridLayout->addWidget(labelNumAnts, 0, 0, 1, 1);

        labelEvaporation = new QLabel(AntAlgorithmDialog);
        labelEvaporation->setObjectName("labelEvaporation");

        gridLayout->addWidget(labelEvaporation, 4, 0, 1, 1);

        doubleEvaporation = new QDoubleSpinBox(AntAlgorithmDialog);
        doubleEvaporation->setObjectName("doubleEvaporation");
        doubleEvaporation->setDecimals(2);
        doubleEvaporation->setMinimum(0.010000000000000);
        doubleEvaporation->setMaximum(1.000000000000000);
        doubleEvaporation->setSingleStep(0.010000000000000);

        gridLayout->addWidget(doubleEvaporation, 4, 1, 1, 1);

        doubleQ = new QDoubleSpinBox(AntAlgorithmDialog);
        doubleQ->setObjectName("doubleQ");
        doubleQ->setDecimals(2);
        doubleQ->setMinimum(0.010000000000000);
        doubleQ->setMaximum(10000.000000000000000);
        doubleQ->setSingleStep(0.010000000000000);

        gridLayout->addWidget(doubleQ, 5, 1, 1, 1);

        buttonBox = new QDialogButtonBox(AntAlgorithmDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);

        gridLayout->addWidget(buttonBox, 10, 1, 1, 1);

        comboEnd = new QComboBox(AntAlgorithmDialog);
        comboEnd->setObjectName("comboEnd");

        gridLayout->addWidget(comboEnd, 7, 1, 1, 1);

        labelEnd = new QLabel(AntAlgorithmDialog);
        labelEnd->setObjectName("labelEnd");

        gridLayout->addWidget(labelEnd, 7, 0, 1, 1);

        doubleBeta = new QDoubleSpinBox(AntAlgorithmDialog);
        doubleBeta->setObjectName("doubleBeta");
        doubleBeta->setDecimals(2);
        doubleBeta->setMinimum(0.010000000000000);
        doubleBeta->setMaximum(10.000000000000000);
        doubleBeta->setSingleStep(0.010000000000000);

        gridLayout->addWidget(doubleBeta, 3, 1, 1, 1);

        comboStart = new QComboBox(AntAlgorithmDialog);
        comboStart->setObjectName("comboStart");

        gridLayout->addWidget(comboStart, 6, 1, 1, 1);

        labelAlpha = new QLabel(AntAlgorithmDialog);
        labelAlpha->setObjectName("labelAlpha");

        gridLayout->addWidget(labelAlpha, 2, 0, 1, 1);

        spinNumAnts = new QSpinBox(AntAlgorithmDialog);
        spinNumAnts->setObjectName("spinNumAnts");
        spinNumAnts->setMinimum(1);
        spinNumAnts->setMaximum(1000);

        gridLayout->addWidget(spinNumAnts, 0, 1, 1, 1);

        labelStart = new QLabel(AntAlgorithmDialog);
        labelStart->setObjectName("labelStart");

        gridLayout->addWidget(labelStart, 6, 0, 1, 1);

        doubleAlpha = new QDoubleSpinBox(AntAlgorithmDialog);
        doubleAlpha->setObjectName("doubleAlpha");
        doubleAlpha->setDecimals(2);
        doubleAlpha->setMinimum(0.010000000000000);
        doubleAlpha->setMaximum(10.000000000000000);
        doubleAlpha->setSingleStep(0.010000000000000);

        gridLayout->addWidget(doubleAlpha, 2, 1, 1, 1);

        labelBeta = new QLabel(AntAlgorithmDialog);
        labelBeta->setObjectName("labelBeta");

        gridLayout->addWidget(labelBeta, 3, 0, 1, 1);

        labelQ = new QLabel(AntAlgorithmDialog);
        labelQ->setObjectName("labelQ");

        gridLayout->addWidget(labelQ, 5, 0, 1, 1);

        labelNumIterations = new QLabel(AntAlgorithmDialog);
        labelNumIterations->setObjectName("labelNumIterations");

        gridLayout->addWidget(labelNumIterations, 1, 0, 1, 1);

        spinNumIterations = new QSpinBox(AntAlgorithmDialog);
        spinNumIterations->setObjectName("spinNumIterations");
        spinNumIterations->setMinimum(1);
        spinNumIterations->setMaximum(1000);

        gridLayout->addWidget(spinNumIterations, 1, 1, 1, 1);

        labelPercentage = new QLabel(AntAlgorithmDialog);
        labelPercentage->setObjectName("labelPercentage");

        gridLayout->addWidget(labelPercentage, 8, 0, 1, 1);

        spinPercentage = new QSpinBox(AntAlgorithmDialog);
        spinPercentage->setObjectName("spinPercentage");
        spinPercentage->setMinimum(1);
        spinPercentage->setMaximum(100);
        spinPercentage->setValue(40);

        gridLayout->addWidget(spinPercentage, 8, 1, 1, 1);

        checkTreeMode = new QCheckBox(AntAlgorithmDialog);
        checkTreeMode->setObjectName("checkTreeMode");
        checkTreeMode->setText(QCoreApplication::translate("AntAlgorithmDialog", "Дерево путей (от одной точки до всех коммутаторов)", nullptr));

        gridLayout->addWidget(checkTreeMode, 9, 1, 1, 1);


        retranslateUi(AntAlgorithmDialog);
        // Исправленная часть файла ui_AntAlgorithm.h
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AntAlgorithmDialog, static_cast<void (QDialog::*)()>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AntAlgorithmDialog, static_cast<void (QDialog::*)()>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AntAlgorithmDialog);
    } // setupUi

    void retranslateUi(QDialog *AntAlgorithmDialog)
    {
        AntAlgorithmDialog->setWindowTitle(QCoreApplication::translate("AntAlgorithmDialog", "Ant Colony Algorithm Parameters", nullptr));
        labelNumAnts->setText(QCoreApplication::translate("AntAlgorithmDialog", "\320\247\320\270\321\201\320\273\320\276 \320\274\321\203\321\200\320\260\320\262\321\214\320\265\320\262", nullptr));
        labelEvaporation->setText(QCoreApplication::translate("AntAlgorithmDialog", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\270\321\201\320\277\320\260\321\200\320\265\320\275\320\270\321\217 \321\204\320\265\321\200\320\276\320\274\320\276\320\275\320\260", nullptr));
        labelEnd->setText(QCoreApplication::translate("AntAlgorithmDialog", "\320\272\320\276\320\275\320\265\321\207\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", nullptr));
        labelAlpha->setText(QCoreApplication::translate("AntAlgorithmDialog", "\320\222\320\273\320\270\321\217\320\275\320\270\320\265 \321\204\320\265\321\200\320\276\320\274\320\276\320\275\320\260", nullptr));
        labelStart->setText(QCoreApplication::translate("AntAlgorithmDialog", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", nullptr));
        labelBeta->setText(QCoreApplication::translate("AntAlgorithmDialog", "\320\222\320\273\320\270\321\217\320\275\320\270\320\265 \321\215\320\262\321\200\320\270\321\201\321\202\320\270\320\272\320\270", nullptr));
        labelQ->setText(QCoreApplication::translate("AntAlgorithmDialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\204\320\265\321\200\320\276\320\274\320\276\320\275\320\260", nullptr));
        labelNumIterations->setText(QCoreApplication::translate("AntAlgorithmDialog", "\320\247\320\270\321\201\320\273\320\276 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271", nullptr));
        labelPercentage->setText(QCoreApplication::translate("AntAlgorithmDialog", "\320\277\321\200\320\276\321\206\320\265\320\275\321\202 \321\201\321\205\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        checkTreeMode->setText(QCoreApplication::translate("AntAlgorithmDialog", "Дерево путей (от одной точки до всех коммутаторов)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AntAlgorithmDialog: public Ui_AntAlgorithmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANTALGORITHM_H
