#include "stdio.h"
#include "stdlib.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    qDebug()<<"The width of the dialog is "<< w.width()<<"\n";
    qDebug()<<"The height of the dialog is "<< w.height()<<"\n";
    w.show();
    return a.exec();
}
