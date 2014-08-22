#ifndef PLATESIZEDIALOG_H
#define PLATESIZEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QString>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class PlateSizeDialog;
}

class PlateSizeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PlateSizeDialog(QWidget *parent = 0);
    ~PlateSizeDialog();
    QString pLengthStr, pHeightStr;
    float plateLength, plateHeight;

private slots:
    void applyBtn_clicked();
    void OKBtn_clicked();
    
private:
    Ui::PlateSizeDialog *ui;
    bool thereIsPlate;
    QLabel *pLengthLbl;
    QLabel *pHeightLbl;
    QLineEdit *pLengthLnEdit;
    QLineEdit *pHeightLnEdit;
    QGridLayout *plateDimGrid;
    QHBoxLayout *BtnHBox;
    QGroupBox *plateDimGroupBox;
    QGroupBox *AppOKGroupBox;
    QGroupBox *createPlateDimGroup();
    QGroupBox *createApplyOkBoxGroup();
    QPushButton *ApplyBtn;
    QPushButton *OKBtn;
};

#endif // PLATESIZEDIALOG_H
