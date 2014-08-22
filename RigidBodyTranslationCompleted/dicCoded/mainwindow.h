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
  //  void plateHeightLnEdt_changed();
  //  void plateLengthLnEdt_changed();
    //From Scribble
    void open();
    void save();
    void penColor();
    void penWidth();
    void about();
    void showEllipticFixedSizeDialog();
    void showPlateSizeDialog();
    void showRigidBodyTransDialog();
    void assignCanvasProps();
    void assgnCnvsPrpsPlate();
    void assgnCnvsPrpsSpeckle();
    void assgnCnvsPrpsRBT();
    void updateStatusBar();

private:
    Ui::MainWindow *ui;
    Canvas *canvas;
    //QPushButton *drawPlateBtn, *speckPlateBtn, *cleanScreenBtn, *cleanPlateBtn;
    //QLabel *plateLengthLbl, *plateHeightLbl, *speckCountLbl;
    //QLineEdit *plateLengthLnEdt, *plateHeightLnEdt, *speckCountLnEdt;
    //QVBoxLayout *mainVBox;
    //QHBoxLayout *lowerSide;
    //QGridLayout *lowerGrid;
    //QGroupBox *createLowerGroup();
    //QGroupBox *lowerGroup;
    QToolBar *mainToolBar;
   // QAction *saveCoordsAct, *saveCoordsAsAct, *showDialogAct, *fixedSizeAct;
    EllipticFixedSizeDialog *ellipticFixedSizeDia;
    PlateSizeDialog *plateSizeDia;
    rigidBodyTranslation *rigidBodyTransDia;
  //  void setMainLayout();
    void setMenusAndToolbars();
    void readRadii();
    void readPlateSize();
    //From Scribble
    void createActions();
    void createMenusAndToolbars();
    bool maybeSave();
    bool saveFile(const QByteArray &fileFormat);

    QMenu *saveAsMenu;
    QMenu *fileMenu;
    QMenu *optionMenu;
    QMenu *helpMenu;
    QMenu *editMenu, *plateGeomMenu, *speckGeomMenu, *ellipticMenu;
    QMenu *displacementMenu;

    QAction *openAct;
    QAction *saveImageAct;
    QList<QAction *> saveAsActs;
    QAction *exitAct;
    QAction *penColorAct;
    QAction *penWidthAct;
  //  QAction *printAct;
    QAction *clearScreenAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *drawPlateAct;
    QAction *speckleAct;
    QAction *fixedSizeAct, *plateSizeAct;
    QAction *rigidBodyTranslationAct;
    QAction *drawRBTAct;

};

#endif // MAINWINDOW_H
