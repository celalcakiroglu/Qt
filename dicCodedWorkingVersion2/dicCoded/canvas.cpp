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

void Canvas::setBrushColor(const QColor &newBrushColor)
{
    myBrushColor = newBrushColor;
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
    painter.setBrush(QBrush(myBrushColor));
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
            for (int i=0; i< speckCountInit; i++){
                randNum=qrand();resultNum=randNum/RAND_MAX;
                randomsL.append(resultNum);
            }
            for (int i=0; i<speckCountInit; i++){
                randNum=qrand();resultNum=randNum/RAND_MAX;
                randomsW.append(resultNum);
            }
            //Adding circular speckles to the plate
            if(speckShape==ellipticH || speckShape==ellipticV){
                if(radH <=0) radH=10;
                if(radV <=0) radV=7;
                for (int i=numSpeckSet*speckCountInit;i<speckCountUp;i++){
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
                    xListInit.append(X);yListInit.append(Y);
                    painter.drawEllipse(X+plateOriginX,Y+plateOriginY, 2*radH, 2*radV);
                }
            }
            if(speckShape==ellipticR){
                if(radH <=0) radH=10;
                if(radV <=0) radV=7;
                qreal theta;
                theta = 360;
                int i=numSpeckSet*speckCountInit;
                qDebug()<<"i = "<<i<<" speckCountUp = "<<speckCountUp;
                qDebug()<<"i < speckCountUp is"<<(i<speckCountUp);
                while (i<(numSpeckSet+1)*speckCountInit){
                    //qDebug()<<"we go into the loop";
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
                    xListInit.append(X);yListInit.append(Y);
                    painter.translate(X+radH, Y+radV);
                    painter.rotate(theta*(randomsL[i]+randomsW[i])/2);

                    painter.drawEllipse(-radH,-radV, 2*radH, 2*radV);
                    painter.rotate(-theta*(randomsL[i]+randomsW[i])/2);
                    painter.translate(-X-radH, -Y-radV);
                    i++;
                }
            }
        }
        ///////////////////////////////////////////////////////////////
        modified = true;
        update();
        thereisPlate=true;
        drawPlate=false;
    }
    speckCountUp=speckCountUp+speckCountInit;
    numSpeckSet=numSpeckSet+1;
    totalSpeckleArea=speckCountUp*speckleArea;
    speckleDensity=totalSpeckleArea/plateArea;
}

void Canvas::drawRigidBodyTranslation()
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.setBrush(QBrush(myBrushColor));
    if(speckShape==ellipticR){
        qreal theta;
        theta = 360;
        xListDisp.clear();yListDisp.clear();
        qDebug()<<"size of ramdomsL is "<<randomsL.size();
        for (int i=0; i<speckCountUp;i++){
            xListDisp.append(xListInit[i]+rigidBodyDX1);
            yListDisp.append(yListInit[i]+rigidBodyDX2);
            painter.translate(xListDisp[i]+radH, yListDisp[i]+radV);
            painter.rotate(theta*(randomsL[i]+randomsW[i])/2);
            painter.drawEllipse(-radH,-radV, 2*radH, 2*radV);
            painter.rotate(-theta*(randomsL[i]+randomsW[i])/2);
            painter.translate(-xListDisp[i]-radH, -yListDisp[i]-radV);
        }
    }
    modified = true;
    update();
}

void Canvas::drawUniformExtension()
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.setBrush(QBrush(myBrushColor));
    if(speckShape==ellipticR){
        qreal theta;
        theta = 360;
        xListDisp.clear();yListDisp.clear();
        qDebug()<<"size of randomsL is: "<<randomsL.size();
        qDebug()<<"speckCountUp = "<<speckCountUp;
        for (int i=0; i<speckCountUp;i++){
            float temporaryX, temporaryY;
            temporaryX=plateOriginX+(xListInit[i]-plateOriginX)*uniExtK1;
            temporaryY=plateOriginY+(yListInit[i]-plateOriginY)*uniExtK2;
            xListDisp.append(temporaryX);
            yListDisp.append(temporaryY);
            painter.translate(xListDisp[i]+radH,
                              yListDisp[i]+radV);
            painter.rotate(theta*(randomsL[i]+randomsW[i])/2);
            painter.drawEllipse(-radH,-radV, 2*radH, 2*radV);
            painter.rotate(-theta*(randomsL[i]+randomsW[i])/2);
            painter.translate(-xListDisp[i]-radH,
                              -yListDisp[i]-radV);
            qDebug()<<"i="<<i;
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

void Canvas::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    thereisPlate=false;drawPlate=false;thereAreSpeckles=false, totalSpeckleArea=0;
    numSpeckSet=0;
    xListInit.clear();yListInit.clear();speckCountUp=0, speckleDensity=0;
    randomsL.clear();randomsW.clear();
    update();
}

void Canvas::drawRBT_clicked()
{
    drawRigidBodyTranslation();
    update();
}

void Canvas::drawUE_clicked()
{
    drawUniformExtension();
    update();
}

void Canvas::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //You need to move these things into separate functions !!
    //and paintEvent should include very little code !!
    QRect mainRect=event->rect();
    painter.drawImage(mainRect,image,mainRect);

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

void Canvas::saveInitCoords_clicked()
{
    QFile speckleFileInit("E://Program Files/Work/created by me/QT/dicCoded/specklesInit.txt");
    speckleFileInit.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream speckOut(&speckleFileInit);
    for (int i=0; i< randomsL.size(); i++){
        speckOut<<randomsL[i]<<"   ,   "<<randomsW[i]<<"\n";
    }
    speckOut<<"shape "<<speckShape<<"\n";
    speckOut<<speckCountUp<<" speckles in total";
    speckOut<<"radH "<<radH;
    speckOut<<"radV "<<radV;
    speckleFileInit.close();
}

void Canvas::saveInitCoordsAs_clicked()
{
    QString speckleFileInitStr = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
          tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
    if (!speckleFileInitStr.isEmpty()) {
        QFile speckleFileInit(speckleFileInitStr);
        if (!speckleFileInit.open(QIODevice::WriteOnly)) {
            // error message
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        } else {
            QTextStream speckOut(&speckleFileInit);
            //speckOut<<" randX   ,      randY   ,       X0    ,       Y0  \n";
            for (int i=0; i< speckCountUp; i++){
                speckOut<<randomsL[i]<<"   ,   "<<randomsW[i]<<"\n";
            }
            speckOut<<"shape "<<speckShape<<"\n";
            speckOut<<speckCountUp<<" speckles in total";
            speckleFileInit.close();
        }
    }
}

void Canvas::readSpeckCoords_clicked()
{
    QString speckFileOpenStr = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!speckFileOpenStr.isEmpty()) {
        QFile fileO(speckFileOpenStr);
        if (!fileO.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&fileO);
        QString line;
        QStringList splittedLine, splittedLastLine;
        speckCountInit=0;randomsL.clear();randomsW.clear();
        while(!in.atEnd()){
            line=in.readLine();
            splittedLine=line.split(",");
            splittedLastLine=line.split(" ");
            if(splittedLastLine[0]=="shape"){
                if(splittedLastLine[1].toInt()==0)speckShape=ellipticH;
                if(splittedLastLine[1].toInt()==1)speckShape=ellipticV;
                if(splittedLastLine[1].toInt()==2)speckShape=ellipticR;
                if(splittedLastLine[1].toInt()==3)speckShape=rectangular;
                if(splittedLastLine[1].toInt()==4)speckShape=triangular;
            }
            if(splittedLastLine[0]=="radH")radH=splittedLastLine[1].toFloat();
            if(splittedLastLine[0]=="radV")radV=splittedLastLine[1].toFloat();
            if(splittedLastLine.size()>=3 &&  splittedLastLine[3]=="total"){
                qDebug()<<"Last line last word: "<<splittedLastLine[3];
                break;
            }
            if(splittedLine.size()>1){
                randomsL.append(splittedLine[0].toDouble());
                randomsW.append(splittedLine[1].toDouble());
                qDebug()<<"Length random="<<randomsL[speckCountInit]<<"Width random="<<randomsW[speckCountInit];
                speckCountInit=speckCountInit+1;
            }
        }
        speckCountUp=0;
        qDebug()<<"SpeckCountInit="<<speckCountInit;
        qDebug()<<"SpeckCountUp="<<speckCountUp;
        qDebug()<<"SpeckShape is: "<<speckShape;
        fileO.close();
    }
    //SPECKLE THE PLATE
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.setBrush(QBrush(myBrushColor));
    qDebug()<<"we set the brush color";
    if (thereisPlate==false){
        QMessageBox::information(this, "There is no plate to speckle", "Please draw the plate first");
        return;
    }
    if(thereisPlate==true){
        ///////////////////////////////////////////////////////////////
        //drawSpeckles=true
        cleanPlateBtn_clicked();
        float X, Y;
        //Adding circular speckles to the plate
        if(speckShape==ellipticH || speckShape==ellipticV){
            if(radH <=0) radH=10;
            if(radV <=0) radV=7;
            for (int i=0;i<speckCountInit;i++){
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
                xListInit.append(X);yListInit.append(Y);
                painter.drawEllipse(X+plateOriginX,Y+plateOriginY, 2*radH, 2*radV);
            }
        }
        if(speckShape==ellipticR){
            if(radH <=0) radH=10;
            if(radV <=0) radV=7;
            qreal theta;
            theta = 360;
            for (int i=0; i<speckCountInit;i++){
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
                xListInit.append(X);yListInit.append(Y);
                painter.translate(X+radH, Y+radV);
                painter.rotate(theta*(randomsL[i]+randomsW[i])/2);
                painter.drawEllipse(-radH,-radV, 2*radH, 2*radV);
                painter.rotate(-theta*(randomsL[i]+randomsW[i])/2);
                painter.translate(-X-radH, -Y-radV);
            }
        }
        ///////////////////////////////////////////////////////////////
        modified = true;
        update();
        thereisPlate=true;
        drawPlate=false;
    }
    speckCountUp=speckCountUp+speckCountInit;
    totalSpeckleArea=speckCountUp*speckleArea;
    speckleDensity=totalSpeckleArea/plateArea;
    qDebug()<<"plate area = "<<plateArea;
    qDebug()<<"speckle area = "<<speckleArea;
    qDebug()<<"total speckle area = "<<totalSpeckleArea;
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
