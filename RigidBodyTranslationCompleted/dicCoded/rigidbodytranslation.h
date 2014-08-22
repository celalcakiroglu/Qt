#ifndef RIGIDBODYTRANSLATION_H
#define RIGIDBODYTRANSLATION_H

#include <QDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QGroupBox>
#include <QString>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class rigidBodyTranslation;
}

class rigidBodyTranslation : public QDialog
{
    Q_OBJECT
    
public:
    explicit rigidBodyTranslation(QWidget *parent = 0);
    ~rigidBodyTranslation();
    float deltaX1, deltaX2;
private slots:
    void RBTOK_clicked();
private:
    Ui::rigidBodyTranslation *ui;
    QLabel *x1, *x2, *x3, *equals1, *equals2, *equals3;
    QLabel *Plus1, *Plus2, *Plus3;
    QLabel *X1, *X2, *X3, *explanationRBT;
    QLineEdit *dX1, *dX2, *dX3;
    QString dX1Str, dX2Str;
    QGroupBox *RBTGroupBox;
    QVBoxLayout *mainVBox;
    QGridLayout *rigidBodyTransGrid;
    void setLabelsAndLineedits();
    QPushButton *OKBtn;
};

#endif // RIGIDBODYTRANSLATION_H
