#ifndef ANTALGORITHM_H
#define ANTALGORITHM_H

#endif // ANTALGORITHM_H

#ifndef ANTALGORITHMDIALOG_H
#define ANTALGORITHMDIALOG_H

#include <QDialog>
#include <QStringList>

namespace Ui { class AntAlgorithmDialog; }

class AntAlgorithmDialog : public QDialog {
    Q_OBJECT
public:
    explicit AntAlgorithmDialog(const QStringList& switches, QWidget *parent = nullptr);
    ~AntAlgorithmDialog();

    int getNumAnts() const;
    int getNumIterations() const;
    double getAlpha() const;
    double getBeta() const;
    double getEvaporation() const;
    double getQ() const;
    QString getStartSwitch() const;
    QString getEndSwitch() const;
    int getPercentage() const;
    bool isTreeMode() const;

private:
    Ui::AntAlgorithmDialog *ui;
};

#endif // ANTALGORITHMDIALOG_H
