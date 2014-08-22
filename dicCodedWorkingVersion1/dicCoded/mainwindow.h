#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void showDialog();

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
    QMenu *editMenu, *speckGeomMenu, *ellipticMenu;
    EllipticFixedSizeDialog *dia;
  //  void setMainLayout();
    void setMenusAndToolbars();
    void readRadii();
    //From Scribble
    void createActions();
    void createMenusAndToolbars();
    bool maybeSave();
    bool saveFile(const QByteArray &fileFormat);

    QMenu *saveAsMenu;
    QMenu *fileMenu;
    QMenu *optionMenu;
    QMenu *helpMenu;

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
    QAction *fixedSizeAct;
};

#endif // MAINWINDOW_H
