#include "canvas.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{
    setBgWhite();
    setPensAndBrushes();
    drawPlate=false;drawSpeckles=false;
    dia = new EllipticFixedSizeDialog(this);
    //------------------------------------------
    //  From Scribble
    //------------------------------------------
    setAttribute(Qt::WA_StaticContents);//indicating that the widget contents are rooted to the top-left corner and don't change when the widget is resized. This is purely an optimization and should only be used for widgets whose contents are static and rooted to the top-left corner.
    modified = false;
    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::blue;
}

bool Canvas::openImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))return false;
    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

bool Canvas::saveImage(const QString &fileName, const char *fileFormat)
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());
    if (visibleImage.save(fileName, fileFormat)) {
       modified = false;
       return true;
     }
    else{
       return false;
    }
}

void Canvas::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

void Canvas::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

void Canvas::setPensAndBrushes()
{
    redBrush.setColor(Qt::red);redBrush.setStyle(Qt::SolidPattern);
    blueBrush.setColor(Qt::blue);blueBrush.setStyle(Qt::SolidPattern);
    whiteBrush.setColor(Qt::white);
    blackPen.setColor(Qt::black);
    blackPen.setWidth(4);
    whitePen.setColor(Qt::white);
}

void Canvas::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;
    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    //We could call the update() function with no parameter, but as an easy optimization we pass a QRect that specifies the rectangle inside the scribble are needs updating, to avoid a complete repaint of the widget.
    lastPoint = endPoint;
}

void Canvas::drawThePlate()
{
    QPainter painter(&image);
    if(thereisPlate==true)drawPlate=true;
    if (drawPlate==true){
        plateOriginX=50;plateOriginY=50;
        screenHeight=this->height();
        screenLength=this->width();
        int originX, originY;
        originX=this->x(); originY=this->y();
        if(pHeight > pLength){
            QMessageBox::information(this, "Width of the plate can't be greater than its length.", "The values will be swapped");
            float *temp;temp=new float;
            *temp=pHeight;pHeight=pLength;pLength=*temp;delete temp;
        }
        if(pLength >= 0.8*screenLength){
            float coeff = pLength/(0.8*screenHeight);
            pHeight=pHeight/coeff;
            pLength=0.8*screenLength;
        }
        if (pHeight>=0.8*screenHeight){
            float coeff2 = pHeight/(0.8*screenHeight);
            pLength=pLength/coeff2;
            pHeight=0.8*screenHeight;
        }

       // painter.setPen(blackPen);

    }
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawRect(plateOriginX, plateOriginY, 550, 350);
    modified = true;
    update();
    thereisPlate=true;
    drawPlate=false;
}

void Canvas::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void Canvas::setBgWhite()
{
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(Pal);
}

void Canvas::drawPlateBtn_clicked()
{
    drawPlate=true;
    drawThePlate();
    update();
}

void Canvas::speckPlateBtn_clicked()
{
    drawSpeckles=true;
    update();
    drawSpeckles=false;
}

void Canvas::cleanPlateBtn_clicked()
{
    drawSpeckles=false;
    drawPlate=true;
    update();
    drawPlate=false;
}

void Canvas::cleanScreenBtn_clicked()
{
    drawSpeckles=false;
    drawPlate=false;
    update();
}

void Canvas::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    thereisPlate=false;drawPlate=false;
    update();
}

//void Canvas::print()
//{
    //#ifndef QT_NO_PRINTER
    //QPrinter printer(QPrinter::HighResolution);
    //QPrintDialog *printDialog = new QPrintDialog(&printer, this);
    //  if (printDialog->exec() == QDialog::Accepted) {
    //    QPainter painter(&printer);
    //    QRect rect = painter.viewport();
//        QSize size = image.size();
 //       size.scale(rect.size(), Qt::KeepAspectRatio);
 //       painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
//        painter.setWindow(image.rect());
//        painter.drawImage(0, 0, image);
 //   }
  //   #endif // QT_NO_PRINTER
//}

void Canvas::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //You need to move these things into separate functions !!
    //and paintEvent should include very little code !!
    QRect dirtyRect=event->rect();
    painter.drawImage(dirtyRect,image,dirtyRect);
    if(drawSpeckles==true){
        if (thereisPlate==false){
            QMessageBox::information(this, "There is no plate to speckle", "Please draw the plate first");
            return;
        }
        cleanPlateBtn_clicked();
        //readRadii();
        float randNum;
        float resultNum;
        float X, Y;
        randomsL.clear();randomsW.clear();
        for (int i=0; i< speckCount; i++){
            randNum=qrand();resultNum=randNum/RAND_MAX;
            randomsL.append(resultNum);
        }
        for (int i=0; i<speckCount; i++){
            randNum=qrand();resultNum=randNum/RAND_MAX;
            randomsW.append(resultNum);
        }
        //Adding circular speckles to the plate
        if(specksElliptic==false){
            for (int i=0; i<speckCount;i++){
                //Keeping the ellipses within the plate
                if(randomsL[i]*pLength-speckDiam < 0){
                    X=randomsL[i]*pLength;
                }
                else{
                    X=randomsL[i]*pLength-speckDiam;
                }
                if(randomsW[i]*pHeight-speckDiam < 0){
                    Y=randomsW[i]*pHeight;
                }
                else{
                    Y=randomsW[i]*pHeight-speckDiam;
                }
                xList.append(X);yList.append(Y);
                painter.setBrush(redBrush);
                painter.drawEllipse(X,Y,speckDiam, speckDiam);
                //speckList.append(scene->addEllipse(X, Y, speckDiam, speckDiam,
                  //          QPen(), redBrush));
            }
        }
        //Adding elliptic speckles to the plate
        if(specksElliptic==true){
            for (int i=0; i<speckCount;i++){
                //Keeping the ellipses within the plate
                //Major axis in horizontal direction case
                if(dia->directionCount>1){
                    QMessageBox::information(this, "You checked more than one speckle direction options", "Please select only one speckle direction option");
                    return;
                }
                if(dia->majorAxisHorizontal==true){
                    if(randomsL[i]*pLength-2*majorRadius < 0){
                        X=randomsL[i]*pLength;
                    }
                    else{
                        X=randomsL[i]*pLength-2*majorRadius;//most of the time this is used
                    }
                    if(randomsW[i]*pHeight-2*minorRadius < 0){
                        Y=randomsW[i]*pHeight;
                    }
                    else{
                        Y=randomsW[i]*pHeight-2*minorRadius;
                    }
                    xList.append(X);yList.append(Y);
                    painter.setBrush(redBrush);
                    painter.drawEllipse(X, Y, 2*majorRadius, 2*minorRadius);
                    //speckList.append(scene->addEllipse(X, Y, 2*majorRadius, 2*minorRadius,
                      //          QPen(), redBrush));
                }
                //Major axis invertical diection case
                else if(dia->majorAxisVertical==true){
                    if(randomsL[i]*pLength-2*minorRadius < 0){
                        X=randomsL[i]*pLength+plateOriginX;
                    }
                    else{
                        X=randomsL[i]*pLength-2*minorRadius+plateOriginX;//most of the time this is used
                    }
                    if(randomsW[i]*pHeight-2*majorRadius < 0){
                        Y=randomsW[i]*pHeight+plateOriginY;
                    }
                    else{
                        Y=randomsW[i]*pHeight-2*majorRadius+plateOriginY;
                    }
                    xList.append(X);yList.append(Y);
                    painter.setBrush(redBrush);
                    painter.drawEllipse(X, Y, 2*minorRadius, 2*majorRadius);
                    //speckList.append(scene->addEllipse(/*randomsL[i]*pLength-speckDiam*/X, /*randomsW[i]*pWidth-speckDiam*/Y, 2*minorRadius, 2*majorRadius,
                    //            QPen(), redBrush));
                }
                //Major axis random case
                else if(dia->majorAxisRandom==true){
                    float x1, y1, x2, y2, x3, y3, x4, y4, xC, yC;
                    float x1Local, y1Local, x2Local, y2Local, x3Local, y3Local, x4Local, y4Local;
                    float xR1, yR1, xR2, yR2, xR3, yR3, xR4, yR4;
                    if(randomsL[i]*pLength-2*majorRadius < 0){
                        X=randomsL[i]*pLength+plateOriginX;
                    }
                    else{
                        X=randomsL[i]*pLength-2*majorRadius+plateOriginX;//most of the time this is used
                    }
                    if(randomsW[i]*pHeight-2*minorRadius < 0){
                        Y=randomsW[i]*pHeight+plateOriginY;
                    }
                    else{
                        Y=randomsW[i]*pHeight-2*minorRadius+plateOriginY;
                    }
                    //Make sure that speckles stay within the plate
                    qreal Pi=qAcos(-1);
                    qreal tetaRad,tetaDeg;
                    tetaRad=0.5*Pi*pow(-1.0,i)*randomsL[i];
                    tetaDeg=180*tetaRad/Pi;
                    x1=X;
                    y1=Y;
                    x2=X+2*majorRadius;
                    y2=Y;
                    x3=X;
                    y3=Y+2*minorRadius;
                    x4=X+2*majorRadius;
                    y4=Y+2*minorRadius;;
                    xC=X+majorRadius;
                    yC=Y+minorRadius;
                    x1Local=x1-xC; y1Local=yC-y1;
                    x2Local=x2-xC; y2Local=yC-y2;
                    x3Local=x3-xC; y3Local=yC-y3;
                    x4Local=x4-xC; y4Local=yC-y4;
                    qDebug()<<"xC="<<xC<<" yC="<<yC;
                    xR1=(qCos(tetaRad)*x1Local-qSin(tetaRad)*y1Local)+xC;
                    yR1=(qSin(tetaRad)*x1Local+qCos(tetaRad)*y1Local)+yC;
                    xR2=(qCos(tetaRad)*x2Local-qSin(tetaRad)*y2Local)+xC;
                    yR2=(qSin(tetaRad)*x2Local+qCos(tetaRad)*y2Local)+yC;
                    xR3=(qCos(tetaRad)*x3Local-qSin(tetaRad)*y3Local)+xC;
                    yR3=(qSin(tetaRad)*x3Local+qCos(tetaRad)*y3Local)+yC;
                    xR4=(qCos(tetaRad)*x4Local-qSin(tetaRad)*y4Local)+xC;
                    yR4=(qSin(tetaRad)*x4Local+qCos(tetaRad)*y4Local)+yC;
                    QList<float> xCoordsAfterRot;QList<float> yCoordsAfterRot;
                    xCoordsAfterRot.append(xR1);xCoordsAfterRot.append(xR2);
                    xCoordsAfterRot.append(xR3);xCoordsAfterRot.append(xR4);
                    yCoordsAfterRot.append(yR1);yCoordsAfterRot.append(yR2);
                    yCoordsAfterRot.append(yR3);yCoordsAfterRot.append(yR4);
                    float maxX, maxY, minX, minY;
                    minX=xCoordsAfterRot[0]; minY=yCoordsAfterRot[0];
                    maxX=xCoordsAfterRot[0]; maxY=yCoordsAfterRot[0];
                    for(int k=1; k<4 ; k++){
                        if(xCoordsAfterRot[k]<xCoordsAfterRot[k-1]){
                            minX=xCoordsAfterRot[k];
                        }
                        if(xCoordsAfterRot[k]>xCoordsAfterRot[k-1]){
                            maxX=xCoordsAfterRot[k];
                        }
                        if(yCoordsAfterRot[k]<yCoordsAfterRot[k-1]){
                            minY=yCoordsAfterRot[k];
                        }
                        if(yCoordsAfterRot[k]>yCoordsAfterRot[k-1]){
                            maxY=yCoordsAfterRot[k];
                        }
                    }
                    float xDist, yDist;
                    if (minX <plateOriginX){
                        //shift x coordinates of the speckle to the right xDist kadar
                        xDist=qAbs(minX-plateOriginX);
                        X=X+xDist;
                    }
                    if (minY<plateOriginY){
                        //shift y coordinates down yDist kadar
                        yDist=qAbs(minY-plateOriginY);
                        Y=Y+yDist;
                    }
                    if (maxX > pLength){
                        //shift x coordinates of the speckle to the left xDist kadar
                        xDist=qAbs(maxX-pLength-plateOriginX);
                        X=X-xDist;
                    }
                    if (maxY > pHeight+plateOriginY){
                        //shift y coordinates up yDist kadar
                        yDist=qAbs(maxY-pHeight-plateOriginY);
                        Y=Y-yDist;
                    }
                    static const QPointF points[4] = {
                        QPointF(xR1, yR1),
                        QPointF(xR2, yR2),
                        QPointF(xR3, yR3),
                        QPointF(xR4, yR4)
                    };
                    painter.drawPolygon(points, 4);
                    //speckList.append(scene->addEllipse(X, Y, 2*majorRadius, 2*minorRadius,
                               // QPen(), redBrush));
                    //speckList[i]->setTransformOriginPoint(speckList[i]->boundingRect().center());
                    //speckList[i]->setRotation(-tetaDeg);
                    //-----------------------------------------------
                    qDebug()<<"max X="<<maxX;
                    qDebug()<<"max Y="<<maxY;
                    xCoordsAfterRot.clear();yCoordsAfterRot.clear();
                }
            }
        }
        speckCountLnEdtStr=QString::number(speckCount);
    }
}

void Canvas::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}


void Canvas::mousePressEvent(QMouseEvent *event)//from the scribble example
{
    if (event->button() == Qt::LeftButton){
        lastPoint = event->pos();
        scribbling = true;
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)//from the scribble example
{
    if ((event->buttons() & Qt::LeftButton) && scribbling) drawLineTo(event->pos());
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)//from the scribble example
{
    if (event->button() == Qt::LeftButton && scribbling){
        drawLineTo(event->pos());
        scribbling = false;
    }
}
