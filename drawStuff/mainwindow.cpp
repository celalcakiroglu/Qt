#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    window =new Window(this);
    mainToolbar = new QToolBar;
    addToolBar(mainToolbar);
    QPixmap undoPix("undo2.png"), redoPix("redo.png");
    undoAct = mainToolbar->addAction(undoPix,tr("&Undo  CTRL+u"));
    undoAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_U));
    connect(undoAct, SIGNAL(triggered()),window->getCanvas(),SLOT(undoLastPart()));
    mainToolbar->addSeparator();
    redoAct = mainToolbar->addAction(redoPix,tr("&Redo"));
    redoAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
    connect(redoAct, SIGNAL(triggered()),window->getCanvas(),SLOT(redoLastPart()));
    setCentralWidget(window);
    setFixedHeight(750);setFixedWidth(1000);
}
