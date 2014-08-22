#ifndef ELLIPTICFIXEDSIZE_H
#define ELLIPTICFIXEDSIZE_H

#include <QDialog>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QButtonGroup>


namespace Ui {
class EllipticFixedSize;
}

class EllipticFixedSize : public QDialog
{
    Q_OBJECT
    
public:
    explicit EllipticFixedSize(QWidget *parent = 0);
    ~EllipticFixedSize();
    QString minorRadiusStr, majorRadiusStr;
    bool majorAxisHorizontal, majorAxisVertical, majorAxisRandom;
    int directionCount;
private slots:
    void on_ApplyBtn_clicked();
    void on_OKBtn_clicked();
    void on_majorAxisHor_clicked();
    void on_majorAxisVer_clicked();
    void on_majorAxisRan_clicked();
private:
    Ui::EllipticFixedSize *ui;
    QLabel *radius1;
    QLabel *radius2;
    QLineEdit *lineEditRadius1;
    QLineEdit *lineEditRadius2;
    QGroupBox *createRadiiEntryGroup();
    QGroupBox *createCheckBoxGroup();
    QGroupBox *createApplyOkBoxGroup();
    QGridLayout *radGrid;
    QVBoxLayout *tickVBox;
    QHBoxLayout *BtnHBox;
    QGroupBox *dirGroupBox;
    QGroupBox *radGroupBox;
    QGroupBox *AppOKGroupBox;
    QButtonGroup *dirBtnGroup;
    QCheckBox *majorAxisHor;
    QCheckBox *majorAxisVer;
    QCheckBox *majorAxisRan;
    QPushButton *ApplyBtn;
    QPushButton *OKBtn;
};

#endif // ELLIPTICFIXEDSIZE_H
