#ifndef ELLIPTICFIXEDSIZEDIALOG_H
#define ELLIPTICFIXEDSIZEDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QGroupBox>
#include <QCheckBox>
#include <QWidget>
#include <QtGlobal>
#include <QDebug>
#include <QLayout>
#include <QLabel>
#include <QtCore>
#include <qmath.h>
#include <math.h>
#include <QtGui>
#include <QtOpenGL/QGLWidget>
#include <QApplication>
#include <QGraphicsObject>
#include <QtGlobal>
#include <QMessageBox>
#include <QTextStream>
#include <QList>
#include <QFile>
#include <QPainter>
#include <QFileDialog>
#include <QImage>
#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QtDebug>
#include <QToolBar>
#include <QString>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QColorDialog>
#include <QInputDialog>

//const double PI  =3.14159265358979323846;

typedef enum{ ellipticH, ellipticV, ellipticR,
              rectangular, triangular } SHAPE;

namespace Ui {
class EllipticFixedSizeDialog;
}

class EllipticFixedSizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EllipticFixedSizeDialog(QWidget *parent = 0);
    ~EllipticFixedSizeDialog();
    QString minorRadiusStr, majorRadiusStr;
    bool majorAxisHorizontal, majorAxisVertical, majorAxisRandom;
    int directionCount;
    float radMinor, radMajor;

private slots:
    void applyBtn_clicked();
    void OKBtn_clicked();
    void majorAxisHor_clicked();
    void majorAxisVer_clicked();
    void majorAxisRan_clicked();
    
private:
    Ui::EllipticFixedSizeDialog *ui;
    bool thereIsPlate, specksElliptic;
    QLabel *radius1;
    QLabel *radius2;
    QLineEdit *lineEditRadius1;
    QLineEdit *lineEditRadius2;
    QGridLayout *radGrid;
    QVBoxLayout *tickVBox;
    QHBoxLayout *BtnHBox;
    QGroupBox *dirGroupBox;
    QGroupBox *radGroupBox;
    QGroupBox *AppOKGroupBox;
    QGroupBox *createRadiiEntryGroup();
    QGroupBox *createCheckBoxGroup();
    QGroupBox *createApplyOkBoxGroup();
    QButtonGroup *dirBtnGroup;
    QCheckBox *majorAxisHor;
    QCheckBox *majorAxisVer;
    QCheckBox *majorAxisRan;
    QPushButton *ApplyBtn;
    QPushButton *OKBtn;
};

#endif // ELLIPTICFIXEDSIZEDIALOG_H
