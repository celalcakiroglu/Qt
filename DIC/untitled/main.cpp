#include "mainwindow.h"
//RAND_MAX=32767

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
