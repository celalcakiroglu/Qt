#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QtGui>
#include <QtGlobal>
#include <QDebug>
#include <QtCore>
#include <qmath.h>
#include <QtOpenGL/QGLWidget>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QTextStream>
#include <QSpinBox>
#include <QList>
#include <QFile>
#include <QFileDialog>
#include <QImage>
#include <QDialog>
#include <QtDebug>
#include <QLinearGradient>
#include <QRadialGradient>
#include <QConicalGradient>
#include <QToolBar>
#include <QString>
#include "ellipticfixedsize.h"
#include "mypanelopengl.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_spButton_clicked();
    void on_closeButton_clicked();
    void on_cleanButton_clicked();
    void on_drPlateButton_clicked();
    void on_drPlateWithPaint_clicked();
    void on_sDiamEdit_textChanged(/*const QString &arg1*/);
    void on_denseSpinBox_valueChanged(/*const QString &arg1*/);
    void on_sCountEdit_editingFinished();
    void on_sCountEdit_textEdited(/*const QString &arg1*/);
    void on_pLengthEdit_editingFinished();
    void on_pWidthEdit_editingFinished();
    void saveScene();
    void showDialog();
    void on_actionSave_Image_triggered();
    void on_actionSave_Coords_triggered();
    void on_actionSaveAs_Coords_triggered();
    void on_actionOpen_triggered();
    void on_actionFixed_size_toggled(/*bool arg1*/);
    void on_clScrButton_clicked();
private:
    Ui::MainWindow *ui;
    QVBoxLayout *mainBox;
    QHBoxLayout *bottomBox;
    QGridLayout *leftGrid;
    QGridLayout *middleGrid;
    QGridLayout *rightGrid;
    QLabel *lengthLbl, *widthLbl, *speckDiamLbl, *speckCountLbl, *finerLbl, *coarserLbl;
    QLineEdit *lengthLineEdt, *widthLineEdt, *speckDiamLineEdt, *speckCountLineEdt;
    QSpinBox *densitySpnBox;
    QPushButton *drawPlateBtn, *speckleBtn, *cleanPlateBtn, *cleanScrnBtn, *closeBtn;
    bool thereIsPlate, specksElliptic;
    int speckCount;
    float pWidth, pLength, speckDiam, minorRadius, majorRadius, screenWidth, screenHeight;
    double denseCoeff;
    QList<double> randomsW, randomsL;
    QList<QGraphicsEllipseItem*>speckList;
    QString pWidthStr, pLengthStr, speckDiamStr, denseCoeffStr, speckCountStr;    
    QBrush redBrush, blueBrush, whiteBrush;
    QPen blackPen, whitePen;
    QGraphicsScene *scene;
    QGraphicsRectItem *ellipseBoundryRect;
    QGraphicsRectItem *rectangle;
    void printSceneDim();
    void readRadii();
    void setMenusAndToolBars();
    void setTheMainGrid();
    void setPensAndBrushes();
    //Declaration of the menus
    QToolBar *mainToolBar;
    //QToolButton *saveCoordsBtn;
    QAction *saveImageAct;
    QAction *saveCoordsAct;
    QAction *saveCoordsAsAct;
    QAction *showDialogAct;
    QAction *openAct;
    QAction *fixedSizeAct;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *speckGeomMenu;
    QMenu *ellipticMenu;
    EllipticFixedSize *dia;
    MyPanelOpenGL *canvas;
};



#endif // MAINWINDOW_H
