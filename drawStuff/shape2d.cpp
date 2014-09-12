#include "shape2d.h"

Shape2D::Shape2D()
{
    this->farbe=Qt::black;
    //this->dicke=1.8898; //1.8898 pixels are 0.5 mm
    this->dicke=0.9449; //0.9449 pixels are 0.25 mm
    this->partOfCSys=false;
}

QLineF *Shape2D::getLine()
{
    return &ln;
}

Shape *Shape2D::getShape()
{
    return &shape;
}

QColor *Shape2D::getFarbe()
{
    return &farbe;
}

qreal *Shape2D::getDicke()
{
    return &dicke;
}

bool *Shape2D::isPartOfCSys()
{
    return &partOfCSys;
}

void Shape2D::setShape(Shape shape)
{
    this->shape=shape;
}

void Shape2D::setFarbe(QColor farbe)
{
    this->farbe=farbe;
}

void Shape2D::setDicke(qreal dicke)
{
    this->dicke=dicke;
}




