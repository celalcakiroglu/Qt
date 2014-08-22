#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QtGlobal>
#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QtGlobal>
#include <QMessageBox>
#include <QList>
#include <QImage>
#include <QDialog>
#include <QtDebug>
#include <QLinearGradient>
#include <QRadialGradient>
#include <QConicalGradient>
#include "aboutdialog.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AboutDialog * ptr;

private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
