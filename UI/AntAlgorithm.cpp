#include "AntAlgorithm.h"
#include "ui_AntAlgorithm.h"

AntAlgorithmDialog::AntAlgorithmDialog(const QStringList& switches, QWidget *parent)
    : QDialog(parent), ui(new Ui::AntAlgorithmDialog)
{
    ui->setupUi(this);
    ui->comboStart->addItems(switches);
    ui->comboEnd->addItems(switches);
    // Можно задать значения по умолчанию
    ui->spinNumAnts->setValue(20);
    ui->spinNumIterations->setValue(50);
    ui->doubleAlpha->setValue(1.0);
    ui->doubleBeta->setValue(3.0);
    ui->doubleEvaporation->setValue(0.5);
    ui->doubleQ->setValue(100.0);
    ui->spinPercentage->setValue(40);
    connect(ui->checkTreeMode, &QCheckBox::toggled, this, [this](bool checked){
        ui->comboEnd->setEnabled(!checked);
    });
}

AntAlgorithmDialog::~AntAlgorithmDialog() {
    delete ui;
}

int AntAlgorithmDialog::getNumAnts() const { return ui->spinNumAnts->value(); }
int AntAlgorithmDialog::getNumIterations() const { return ui->spinNumIterations->value(); }
double AntAlgorithmDialog::getAlpha() const { return ui->doubleAlpha->value(); }
double AntAlgorithmDialog::getBeta() const { return ui->doubleBeta->value(); }
double AntAlgorithmDialog::getEvaporation() const { return ui->doubleEvaporation->value(); }
double AntAlgorithmDialog::getQ() const { return ui->doubleQ->value(); }
QString AntAlgorithmDialog::getStartSwitch() const { return ui->comboStart->currentText(); }
QString AntAlgorithmDialog::getEndSwitch() const { return ui->comboEnd->currentText(); }
int AntAlgorithmDialog::getPercentage() const {return ui->spinPercentage->value();}
bool AntAlgorithmDialog::isTreeMode() const {
    return ui->checkTreeMode->isChecked();
}
