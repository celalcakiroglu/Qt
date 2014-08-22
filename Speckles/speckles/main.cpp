#include "speckles.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    speckles w;
    w.show();
    
    return a.exec();
}
