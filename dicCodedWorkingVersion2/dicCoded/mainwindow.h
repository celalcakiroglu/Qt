#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include "canvas.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    //From Scribble
    void closeEvent(QCloseEvent *event);
private slots:
    //From Scribble
    void open();
    void save();
    void penColor();
    void penWidth();
    void brushColor();
    void about();
    void showEllipticFixedSizeDialog();
    void showPlateSizeDialog();
    void showRigidBodyTransDialog();
    void showUniformExtDialog();
    void assignCanvasProps();
    void assgnCnvsPrpsPlate();
    void assgnCnvsPrpsSpeckle();
    void assgnCnvsPrpsRBT();
    void assgnCnvsPrpsUE();
    void updateStatusBar();
    void assignDefaultCanvasValues();

private:
    Ui::MainWindow *ui;
    Canvas *canvas;
    QToolBar *mainToolBar;
    EllipticFixedSizeDialog *ellipticFixedSizeDia;
    PlateSizeDialog *plateSizeDia;
    rigidBodyTranslation *rigidBodyTransDia;
    uniformExtension *uniformExtDia;
    void setMenusAndToolbars();
    //void readRadii();
    void readPlateSize();
    //From Scribble
    void createActions();
    void createMenusAndToolbars();
    bool maybeSave();
    bool saveFile(const QByteArray &fileFormat);

    QMenu *saveAsMenu;
    QMenu *fileMenu;
    QMenu *optionMenu;
    //QMenu *helpMenu;
    QMenu *editMenu, *plateGeomMenu, *speckGeomMenu, *ellipticMenu;
    QMenu *displacementMenu;

    QAction *openAct;
    QAction *saveImageAct;
    QList<QAction *> saveAsActs;
    QAction *exitAct;
    QAction *penColorAct;
    QAction *penWidthAct;
    QAction *brushColorAct;
 // QAction *printAct;
    QAction *clearScreenAct;
    QAction *updateStatusAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *drawPlateAct;
    QAction *speckleAct;
    QAction *fixedSizeAct, *plateSizeAct;
    QAction *rigidBodyTranslationAct;
    QAction *uniformExtensionAct;
    QAction *drawRBTAct;
    QAction *drawUEAct;
    QAction *saveInitCoordsAct;
    QAction *saveInitCoordsAsAct;
    QAction *saveDispCoordsAct;
    QAction *saveDispCoordsAsAct;
    QAction *readSpeckCoordsAct;
};

#endif // MAINWINDOW_H
