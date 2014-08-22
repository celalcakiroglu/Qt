#include "speckles.h"
#include "ui_speckles.h"

speckles::speckles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::speckles)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackPen(Qt::black);
    blackPen.setWidth(6);
    ellipse=scene->addEllipse(10, 10, 100, 500, blackPen, redBrush);
    rectangle=scene->addRect(-10, -10, 100, 50, blackPen, blueBrush);
    qDebug()<<"The width of the scene is: "<<scene->width();
    qDebug()<<"The height of the scene is: "<<scene->height();
}

speckles::~speckles()
{
    delete ui;
}
