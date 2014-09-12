#include "canvas.h"

const int IdRole = Qt::UserRole;

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{
    setBgWhite();
    lineDia = new LineDialog;
    polyLineDia = new PolyLineDialog;
    csys2DDia = new Csys2Ddialog;
    lineColor = Qt::black;
    lineWidth = 1;
    polyLineSize=0;
}

Shape Canvas::getShape()
{
    return this->shape;
}

LineDialog* Canvas::getLineDia()
{
    return lineDia;
}

PolyLineDialog *Canvas::getPolyLineDia()
{
    return polyLineDia;
}

Csys2Ddialog *Canvas::getCsys2DDia()
{
    return csys2DDia;
}

void Canvas::setBgWhite()
{
    canvasPalette.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(canvasPalette);
}

void Canvas::assignLineColor()
{
    Farbe farbe;
    if(lineDia->isVisible())farbe=Farbe(lineDia->getLineColorCombo()->itemData(lineDia->getLineColorCombo()->currentIndex(), IdRole).toInt());
    else if(polyLineDia->isVisible())
    farbe=Farbe(polyLineDia->getLineColorCombo()->itemData(polyLineDia->getLineColorCombo()->currentIndex(), IdRole).toInt());
    switch(farbe)
    {
        case skyblue:
            lineColor=QColor(135, 206, 235);
            break;
        case darkblue:
            lineColor=Qt::darkBlue;
            break;
        case rot:
            lineColor=Qt::red;
            break;
        case gruen:
            lineColor=Qt::green;
            break;
    }
}

void Canvas::assignLineWidth()
{
    Dicke dicke;
    if(lineDia->isVisible())dicke=Dicke(lineDia->getLineWidthCombo()->itemData(lineDia->getLineWidthCombo()->currentIndex(), IdRole).toInt());
    else if(polyLineDia->isVisible())
    dicke=Dicke(polyLineDia->getLineWidthCombo()->itemData(polyLineDia->getLineWidthCombo()->currentIndex(), IdRole).toInt());
    switch(dicke)
    {
        case d025mm:
            lineWidth=0.9449;//0.25 mm is 0.9449 pixels
            break;
        case d05mm:
            lineWidth=1.8898;
            break;
        case d075mm:
            lineWidth=2.8346;
            break;
        case d1mm:
            lineWidth=3.7795;
            break;
        case d15mm:
            lineWidth=5.6693;
            break;
        case d3mm:
            lineWidth=11.3386;
            break;
    }
}

void Canvas::setBgColor(Farbe farbe)
{
    switch(farbe){
        case weiss:
            canvasPalette.setColor(QPalette::Background, Qt::white);
            setAutoFillBackground(true);
            setPalette(canvasPalette);break;
        case gruen:
            canvasPalette.setColor(QPalette::Background, Qt::green);
            setAutoFillBackground(true);
            setPalette(canvasPalette);break;
        case skyblue:
            canvasPalette.setColor(QPalette::Background, QColor(135, 206, 235));
            setAutoFillBackground(true);
            setPalette(canvasPalette);break;
        case darkblue:
            canvasPalette.setColor(QPalette::Background, Qt::darkBlue);
            setAutoFillBackground(true);
            setPalette(canvasPalette);break;
        case gelb:
            canvasPalette.setColor(QPalette::Background, Qt::yellow);
            setAutoFillBackground(true);
            setPalette(canvasPalette);break;
    }
}

void Canvas::setShape(Shape shape)
{
    this->shape = shape;
}

void Canvas::drawShape()
{
    switch(this->shape){
        case Line:
            {//Declaration of a variable in a 'case' without curly braces is not allowed
                Shape2D lineshape;
                lineshape.setShape(Line);
                lineshape.setFarbe(this->lineColor);
                lineshape.setDicke(this->lineWidth);
                QPointF lnStartPoint(lineDia->xStartF, lineDia->yStartF);
                QPointF lnEndPoint(lineDia->xEndF, lineDia->yEndF);
                lineshape.getLine()->setP1(lnStartPoint);
                lineshape.getLine()->setP2(lnEndPoint);
                shapeList.append(lineshape);
                break;
             }
        case PolyLine:
             {
                Shape2D lineshape;
                lineshape.setShape(Line);
                lineshape.setFarbe(this->lineColor);
                lineshape.setDicke(this->lineWidth);
                QPointF pllnNextPoint(polyLineDia->xNextF, polyLineDia->yNextF);
                if(polyLineSize ==0){
                    QPointF pllnStartPoint(polyLineDia->xStartF, polyLineDia->yStartF);
                    lineshape.getLine()->setP1(pllnStartPoint);
                }
                else{
                    QPointF prevNextPt(shapeList.last().getLine()->p2());
                    lineshape.getLine()->setP1(prevNextPt);
                }
                lineshape.getLine()->setP2(pllnNextPoint);
                shapeList.append(lineshape);
                polyLineSize +=1;
                break;
             }
        case CSys2D:
            {
                cnvsWidth=this->size().width();cnvsHeight=this->size().height();
                Shape2D xAxis;Shape2D yAxis;
                xAxis.partOfCSys=true;yAxis.partOfCSys=true;
                xAxis.setShape(Line);yAxis.setShape(Line);
                CSysOriginX = csys2DDia->originXF*cnvsWidth*0.01;
                CSysOriginY = csys2DDia->originYF*cnvsHeight*0.01;
                QPointF origin(CSysOriginX, CSysOriginY);
                numXTicks=int(csys2DDia->xLimF/csys2DDia->xStepF);
                numYTicks=int(csys2DDia->yLimF/csys2DDia->yStepF);
                QVector<Shape2D> xTickList; QVector<Shape2D> yTickList;
                xTickList.resize(numXTicks);yTickList.resize(numYTicks);
                qreal xAxisLength = abs(cnvsWidth-origin.x())-0.05*cnvsWidth;
                qreal yAxisLength = abs(origin.y())-0.05*cnvsHeight;
                qreal tickSize=cnvsHeight*0.005;
                mappedXInterval=(csys2DDia->xStepF * xAxisLength)/(csys2DDia->xLimF+csys2DDia->xStepF);
                mappedYInterval=(csys2DDia->yStepF * yAxisLength)/(csys2DDia->yLimF+csys2DDia->yStepF);
                QPointF xEnd(origin.x()+xAxisLength,origin.y());
                QPointF yEnd(origin.x(),origin.y()-yAxisLength);
                xAxis.getLine()->setP1(origin);xAxis.getLine()->setP2(xEnd);
                yAxis.getLine()->setP1(origin);yAxis.getLine()->setP2(yEnd);
                shapeList.append(xAxis);shapeList.append(yAxis);
                for(int t=0;t<numXTicks;t++){
                    xTickList[t].partOfCSys=true;
                    xTickList[t].setShape(Line);
                    QPointF tickTop(CSysOriginX + (t+1)*mappedXInterval,CSysOriginY-tickSize/2);
                    QPointF tickBottom(CSysOriginX + (t+1)*mappedXInterval,CSysOriginY+tickSize/2);
                    xTickList[t].getLine()->setP1(tickTop);xTickList[t].getLine()->setP2(tickBottom);
                    shapeList.append(xTickList[t]);
                }
                for(int t=0;t<numYTicks;t++){
                    yTickList[t].partOfCSys=true;
                    yTickList[t].setShape(Line);
                    QPointF tickLeft(CSysOriginX - tickSize/2,CSysOriginY-(t+1)*mappedYInterval);
                    QPointF tickRight(CSysOriginX + tickSize/2,CSysOriginY-(t+1)*mappedYInterval);
                    yTickList[t].getLine()->setP1(tickLeft);yTickList[t].getLine()->setP2(tickRight);
                    shapeList.append(yTickList[t]);
                }
                break;
            }
    }
    update();
}

void Canvas::clearLastLine()
{
    if(!shapeList.isEmpty() && *shapeList.last().getShape() == Line)
    {
       shapeList.removeLast();
    }
    lineDia->close();
    update();
}

void Canvas::clearLastPolyLine()
{
    if(polyLineSize >= 1)
    {
        for(int j=0;j<polyLineSize;j++)shapeList.removeLast();
    }
    polyLineSize=0;
    polyLineDia->close();
}

void Canvas::clearCSys()
{
    csys2DDia->close();
}

void Canvas::polyLineDone()
{
    polyLineSize = 0;
    polyLineDia->close();
}

void Canvas::undoLastPart()
{
    if(!shapeList.isEmpty())
    {
        if(*shapeList.last().getShape() == Line)
        {
            if(*shapeList.last().isPartOfCSys())
            {
                numCSys2DElements = numXTicks + numYTicks + 2; //2 is because of the x and y axes
                /*for(int k=0;k<numCSys2DElements;k++)
                {
                    redoShapeList.push(shapeList.last());
                    shapeList.removeLast();
                }*/
                while(numCSys2DElements-1  > 0)
                {
                    redoShapeList.push(shapeList.last());
                    shapeList.removeLast();
                    numCSys2DElements -= 1;
                }
                /*while(numCSys2DElements  > 0)
                {
                    redoShapeList.append(shapeList.pop_back(););
                    shapeList.removeLast();
                    numCSys2DElements -= 1;
                }*/
            }
            else if(polyLineSize > 0) polyLineSize -=1;
            {
                redoShapeList.push(shapeList.last());
                shapeList.removeLast();
            }
        }
    }
    update();
}

void Canvas::redoLastPart()
{
    if(!redoShapeList.isEmpty())
    {
        if(*redoShapeList.last().isPartOfCSys())
        {
            numCSys2DElements = numXTicks + numYTicks + 2;
            //for(int k=0;k<numCSys2DElements;k++)shapeList.append(redoShapeList.pop());
            while(numCSys2DElements > 0)
            {
                shapeList.append(redoShapeList.pop());
                numCSys2DElements -= 1;
            }
        }
        else shapeList.append(redoShapeList.pop());
    }
    update();
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    for(int k=0;k<shapeList.length();k++){
        switch(*shapeList[k].getShape())
        {
            case Line:
            pen.setColor(*shapeList[k].getFarbe());
            pen.setWidthF(*shapeList[k].getDicke());
            painter.setPen(pen);
            painter.drawLine(*shapeList[k].getLine());
            break;
        }
    }
   // qDebug()<<"Canvas width is:"<<this->size().width()<<" pixels and"<<float(this->size().width())*0.264583333<< "mm"<<endl;
   // qDebug()<<"Canvas height is:"<<this->size().height()<<" pixels and"<<float(this->size().height())*0.264583333<< "mm"<<endl;

}

