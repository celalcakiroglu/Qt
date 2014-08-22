#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "window.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    Window *window;
signals:
    
public slots:

private:
    QToolBar *mainToolbar;
    QAction *undoAct;
    QAction *redoAct;
    
};

#endif // MAINWINDOW_H
