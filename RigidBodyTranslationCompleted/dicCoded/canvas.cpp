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
    setAttribute(Qt::WA_StaticContents);//indicating that the widget contents are rooted to the
    //top-left corner and don't change when the widget is resized.
    //This is purely an optimization and should only be used
    //for widgets whose contents are static and rooted to the top-left corner.
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

    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawRect(plateOriginX, plateOriginY, pLength, pHeight);
    qDebug()<<"plate length is: "<<pLength;
    qDebug()<<"plate height is: "<<pHeight;
    modified = true;
    update();
    thereisPlate=true;
    drawPlate=false;
}

void Canvas::speckleThePlate()
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.setBrush(redBrush);
    if (thereisPlate==false){
        QMessageBox::information(this, "There is no plate to speckle", "Please draw the plate first");
        return;
    }
    if(thereisPlate==true){
        ///////////////////////////////////////////////////////////////
        if(drawSpeckles==true){
            cleanPlateBtn_clicked();
            float randNum;
            float resultNum;
            float X, Y;
            xList.clear();yList.clear();
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
            if(speckShape==ellipticH || speckShape==ellipticV){
                if(radH <=0) radH=10;
                if(radV <=0) radV=7;
                for (int i=0;i<speckCount;i++){
                    //Keeping the ellipses within the plate
                    if(randomsL[i]*pLength-2*radH < 0){
                        X=randomsL[i]*pLength;
                    }
                    else{
                        X=randomsL[i]*pLength-2*radH;
                    }
                    if(randomsW[i]*pHeight-2*radV < 0){
                        Y=randomsW[i]*pHeight;
                    }
                    else{
                        Y=randomsW[i]*pHeight-2*radV;
                    }
                    xList.append(X);yList.append(Y);
                    painter.drawEllipse(X+plateOriginX,Y+plateOriginY, 2*radH, 2*radV);
                }
            }
            if(speckShape==ellipticR){
                if(radH <=0) radH=10;
                if(radV <=0) radV=7;
                qreal theta;
                theta = 45;
                for (int i=0; i<speckCount;i++){             
                    if(plateOriginX+randomsL[i]*pLength-2*radH < plateOriginX){
                        X=plateOriginX+randomsL[i]*pLength;
                    }
                    else{
                        X=plateOriginX+randomsL[i]*pLength-2*radH;
                    }
                    if(plateOriginY+randomsW[i]*pHeight-2*radV < plateOriginY){
                        Y=plateOriginY+randomsW[i]*pHeight;
                    }
                    else{
                        Y=plateOriginY+randomsW[i]*pHeight-2*radV;
                    }
                    xList.append(X);yList.append(Y);
                    painter.translate(X+radH, Y+radV);
                    painter.rotate(45);

                    painter.drawEllipse(-radH,-radV, 2*radH, 2*radV);
                    painter.rotate(-45);
                    painter.translate(-X-radH, -Y-radV);

                    //Make sure that speckles stay within the plate


                }
            }
        }
        ///////////////////////////////////////////////////////////////
        modified = true;
        update();
        thereisPlate=true;
        drawPlate=false;
    }
}

void Canvas::drawRigidBodyTranslation()
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.setBrush(blueBrush);
    if(speckShape==ellipticR){
        qreal theta;
        theta = 45;
        for (int i=0; i<speckCount;i++){
            if(i==5)qDebug()<<"radH: "<<radH;
            painter.translate(xList.at(i)+rigidBodyDX1+radH, yList.at(i)+rigidBodyDX2+radV);
            painter.rotate(45);
            painter.drawEllipse(-radH,-radV, 2*radH, 2*radV);
            painter.rotate(-45);
            painter.translate(-xList.at(i)-rigidBodyDX1-radH, -yList.at(i)-rigidBodyDX2-radV);
        }
    }
    modified = true;
    update();
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
    speckleThePlate();
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

void Canvas::drawRBT_clicked()
{
    drawRigidBodyTranslation();
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
