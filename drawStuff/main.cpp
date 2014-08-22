#include "mainwindow.h"
#include <QApplication>


using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mw;
    mw.showMaximized();
    
    return a.exec();
}
