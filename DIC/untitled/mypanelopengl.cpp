#include "mypanelopengl.h"
#include <QtGui/QMouseEvent>

MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
}

void MyPanelOpenGL::paintEvent()
{
    qreal widgetWidth=this->width();
    qreal widgetHeight=this->height();
    /*if(pWidth > pLength){
        QMessageBox::information(this, "Width of the plate can't be greater than its length.", "The values will be swapped");
        float *temp;temp=new float;
        *temp=pWidth;pWidth=pLength;pLength=*temp;delete temp;
    }
    if(pLength >= 0.8*widgetWidth){
        float coeff = pLength/(0.8*widgetWidth);
        pWidth=pWidth/coeff;
        pLength=0.8*widgetWidth;
    }
    if (pWidth>=0.8*widgetHeight){
        float coeff2 = pWidth/(0.8*widgetHeight);
        pLength=pLength/coeff2;
        pWidth=0.8*widgetHeight;
    }*/
    QPainter painter(this);
    painter.drawRect(QRect(5,5, 20, 20));
    /*QPainter painter(this);

    QPen pointPen(Qt::black);
    pointPen.setWidth(6);

    QPen linePen(Qt::red);
    linePen.setWidth(2);

    QPoint p1;
    p1.setX(10);p1.setY(10);

    QPoint p2;
    p2.setX(100);p2.setY(100);

    painter.setPen(linePen);
    painter.drawLine(p1, p2);

    painter.setPen(pointPen);
    painter.drawPoint(p1);painter.drawPoint(p2);
    qDebug()<<"Height of this widget = "<<this->height();
    qDebug()<<"Width of this widget = "<<this->width();*/
    //QRect rect(10, 10, 100, 100); //upper left corner, then side lengths
    /*QPen framepen(Qt::red);
    framepen.setWidth(6);*/

    //QBrush brush(Qt::blue, Qt::SolidPattern); //Here SolidPattern or DiagCrossPattern can be used
    /*painter.fillRect(rect, brush);
    painter.setPen(framepen);
    painter.drawRect(rect);*/
    //painter.drawEllipse(rect); //draws an ellipse inside the rectangle

    //tutorial 76

    /*QPolygon poly;
    poly << QPoint(140, 10);
    poly << QPoint(140, 100);
    poly << QPoint(230, 10);
    poly << QPoint(230, 100);

    linePen.setWidth(12);
    linePen.setColor(Qt::red);
    linePen.setStyle(Qt::DotLine);*/
    //linePen.setJoinStyle(Qt::MiterJoin); // or Qt::RoundJoin

    /*painter.setPen(linePen);
    painter.drawPolygon(poly);

    QBrush polyBrush;
    polyBrush.setColor(Qt::green);
    polyBrush.setStyle(Qt::SolidPattern);*/

    //Fill the polygon
    /*QPainterPath polyPath;
    polyPath.addPolygon(poly);
    painter.fillPath(polyPath, polyBrush);*/

    //Tutorial 77

    /*QPoint startPoint(20, 220);
    QPoint endPoint(220, 220);
    QPen thickPen(Qt::black);
    thickPen.setWidth(15);
    thickPen.setCapStyle(Qt::FlatCap); //or RoundCap or SquareCap
    painter.setPen(thickPen);
    painter.drawLine(startPoint, endPoint);*/

    //Tutorial 78

    //QLinearGradient grad1(10, 10, 110, 110);
    //(x1, y1, x2, y2) above is the interpolation area
    //grad1.setColorAt(0.0, Qt::white);
    //Creates a stop point at the given position with the given color. The given position must be in the range 0 to 1.
    /*grad1.setColorAt(0.2, Qt::green);
    grad1.setColorAt(0.9, Qt::black);
    painter.fillRect(rect, grad1);*/
}
