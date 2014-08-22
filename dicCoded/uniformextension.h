#ifndef UNIFORMEXTENSION_H
#define UNIFORMEXTENSION_H

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
class uniformExtension;
}

class uniformExtension : public QDialog
{
    Q_OBJECT
    
public:
    explicit uniformExtension(QWidget *parent = 0);
    ~uniformExtension();
    float K1, K2;
private slots:
    void UEOK_clicked();
private:
    Ui::uniformExtension *ui;
    QLabel *x1, *x2, *x3, *equals1, *equals2, *equals3;
    QLabel *Times1, *Times2, *Times3;
    QLabel *X1, *X2, *X3, *explanationUE;
    QLineEdit *K1LnEdt, *K2LnEdt, *K3LnEdt;
    QString K1Str, K2Str;
    QGroupBox *UEGroupBox;
    QVBoxLayout *mainVBox;
    QGridLayout *uniformExtGrid;
    void setLabelsAndLineedits();
    QPushButton *OKBtn;
};

#endif // UNIFORMEXTENSION_H
