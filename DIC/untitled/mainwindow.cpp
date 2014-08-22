#include "mainwindow.h"
#include "ui_mainwindow.h"

//All the things drawn are centered on the Graphicsview
//Care should be taken that the drawing size isn't greater than the the size of the graphicsView

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    thereIsPlate=false, specksElliptic=false;
    qsrand(QTime::currentTime().msec());
    screenWidth=ui->graphicsView->width();
    screenHeight=ui->graphicsView->height();
    //Default values for plate and speckle size
    pLength=500; pWidth=250, speckDiam=10;
    ui->pLengthEdit->setText("500");ui->pWidthEdit->setText("250");ui->sDiamEdit->setText("10");
    denseCoeff=1.0;
    speckCount=1000;
    //Creating the menus
    setMenusAndToolBars();
    //Setting pen and brush properties
    setPensAndBrushes();
    dia = new EllipticFixedSize(this);
    //canvas = new MyPanelOpenGL(this);
    QObject::connect(ui->drPlateWithPaintBtn, SIGNAL(clicked()), this, SLOT(on_drPlateWithPaint_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
    QMainWindow::close();
}
void MainWindow::on_pLengthEdit_editingFinished()
{
    pLengthStr = ui->pLengthEdit->text();
    pLength=pLengthStr.toFloat();
    qDebug() << "Length of the plate is: "<< pLength;
}

void MainWindow::on_pWidthEdit_editingFinished()
{
    pWidthStr = ui->pWidthEdit->text();
    this->pWidth=pWidthStr.toFloat();
    qDebug() << "Width of the plate is: "<< this->pWidth;
}

void MainWindow::on_sDiamEdit_textChanged(/*const QString &arg1*/)
{
    speckDiamStr = ui->sDiamEdit->text();
    this->speckDiam=speckDiamStr.toFloat();
    //qDebug() << "Speckle diameter is: "<< this->speckDiam;
}

void MainWindow::on_denseSpinBox_valueChanged(/*const QString &arg1*/)
{
    if((ui->denseSpinBox->value()-0)>0.000001){
        denseCoeffStr = ui->denseSpinBox->text();
        this->denseCoeff=denseCoeffStr.toDouble();
        speckCount=speckCount*denseCoeff;
        qDebug()<<"The new speckCount is "<<speckCount;
        speckCountStr=QString::number(speckCount);
        ui->sCountEdit->setText(speckCountStr);
    }
}

void MainWindow::on_sCountEdit_editingFinished()
{
    speckCountStr=ui->sCountEdit->text();
    speckCount=speckCountStr.toInt();
}
void MainWindow::on_sCountEdit_textEdited(/*const QString &arg1*/)
{
    speckCountStr=ui->sCountEdit->text();
    speckCount=speckCountStr.toInt();
}

void MainWindow::on_cleanButton_clicked()
{
    scene->clear();
    ui->sCountEdit->clear();
    on_drPlateButton_clicked();
}
void MainWindow::on_clScrButton_clicked()
{
    scene->clear();
    ui->sCountEdit->clear();
    thereIsPlate=false;
}

void MainWindow::on_drPlateButton_clicked()
{
    scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    if(pWidth > pLength){
        QMessageBox::information(this, "Width of the plate can't be greater than its length.", "The values will be swapped");
        float *temp;temp=new float;
        *temp=pWidth;pWidth=pLength;pLength=*temp;delete temp;
    }
    if(pLength >= 0.8*screenWidth){
        float coeff = pLength/(0.8*screenWidth);
        pWidth=pWidth/coeff;
        pLength=0.8*screenWidth;
    }
    if (pWidth>=0.8*screenHeight){
        float coeff2 = pWidth/(0.8*screenHeight);
        pLength=pLength/coeff2;
        pWidth=0.8*screenHeight;
    }
    rectangle=scene->addRect(0, 0, pLength, pWidth, blackPen, whiteBrush);
    //ui->graphicsView->centerOn(speckList[0]);
    thereIsPlate=true;
    pLengthStr = ui->pLengthEdit->text();
    this->pLength=pLengthStr.toFloat();
    pWidthStr = ui->pWidthEdit->text();
    this->pWidth=pWidthStr.toFloat();
}

void MainWindow::on_drPlateWithPaint_clicked()
{
   // qreal widgetWidth=canvas/*ui->panelGL*/->width();
   // qreal widgetHeight=canvas/*ui->panelGL*/->height();
   // if(pWidth > pLength){
   //     QMessageBox::information(this, "Width of the plate can't be greater than its length.", "The values will be swapped");
   //     float *temp;temp=new float;
   //     *temp=pWidth;pWidth=pLength;pLength=*temp;delete temp;
   // }
   // if(pLength >= 0.8*widgetWidth){
   //     float coeff = pLength/(0.8*widgetWidth);
   //     pWidth=pWidth/coeff;
     //   pLength=0.8*widgetWidth;
   // }
  //  if (pWidth>=0.8*widgetHeight){
  //      float coeff2 = pWidth/(0.8*widgetHeight);
    //    pLength=pLength/coeff2;
    //    pWidth=0.8*widgetHeight;
    //}
    //QPainter painter(canvas);
    //painter.drawRect(QRect(5,5, 20, 20));
}

void MainWindow::on_spButton_clicked()
{
    if (thereIsPlate==false){
        QMessageBox::information(this, "There is no plate to speckle", "Please draw the plate first");
        return;
    }
    on_cleanButton_clicked();
    readRadii();
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
            if(randomsW[i]*pWidth-speckDiam < 0){
                Y=randomsW[i]*pWidth;
            }
            else{
                Y=randomsW[i]*pWidth-speckDiam;
            }
            speckList.append(scene->addEllipse(X, Y, speckDiam, speckDiam,
                        QPen(), redBrush));
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
                if(randomsW[i]*pWidth-2*minorRadius < 0){
                    Y=randomsW[i]*pWidth;
                }
                else{
                    Y=randomsW[i]*pWidth-2*minorRadius;
                }
                speckList.append(scene->addEllipse(X, Y, 2*majorRadius, 2*minorRadius,
                            QPen(), redBrush));
            }
            //Major axis invertical diection case
            else if(dia->majorAxisVertical==true){
                if(randomsL[i]*pLength-2*minorRadius < 0){
                    X=randomsL[i]*pLength;
                }
                else{
                    X=randomsL[i]*pLength-2*minorRadius;//most of the time this is used
                }
                if(randomsW[i]*pWidth-2*majorRadius < 0){
                    Y=randomsW[i]*pWidth;
                }
                else{
                    Y=randomsW[i]*pWidth-2*majorRadius;
                }
                speckList.append(scene->addEllipse(/*randomsL[i]*pLength-speckDiam*/X, /*randomsW[i]*pWidth-speckDiam*/Y, 2*minorRadius, 2*majorRadius,
                            QPen(), redBrush));
            }
            //Major axis random case
            else if(dia->majorAxisRandom==true){
                float x1, y1, x2, y2, x3, y3, x4, y4, xC, yC;
                float x1Local, y1Local, x2Local, y2Local, x3Local, y3Local, x4Local, y4Local;
                float xR1, yR1, xR2, yR2, xR3, yR3, xR4, yR4;
                if(randomsL[i]*pLength-2*majorRadius < 0){
                    X=randomsL[i]*pLength;
                }
                else{
                    X=randomsL[i]*pLength-2*majorRadius;//most of the time this is used
                }
                if(randomsW[i]*pWidth-2*minorRadius < 0){
                    Y=randomsW[i]*pWidth;
                }
                else{
                    Y=randomsW[i]*pWidth-2*minorRadius;
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
                if (minX <0){
                    //shift x coordinates of the speckle to the right xDist kadar
                    xDist=qAbs(minX-0);
                    X=X+xDist;
                }
                if (minY<0){
                    //shift y coordinates down yDist kadar
                    yDist=qAbs(minY-0);
                    Y=Y+yDist;
                }
                if (maxX > pLength){
                    //shift x coordinates of the speckle to the left xDist kadar
                    xDist=qAbs(maxX-pLength);
                    //X=X-xDist;
                }
                if ((maxY+minorRadius)>pWidth){
                    //shift y coordinates up yDist kadar
                    yDist=qAbs(maxY-pWidth);
                    Y=Y-minorRadius-yDist;
                }
                //ellipseBoundryRect=new QGraphicsRectItem()
                speckList.append(scene->addEllipse(X, Y, 2*majorRadius, 2*minorRadius,
                            QPen(), redBrush));
                speckList[i]->setTransformOriginPoint(speckList[i]->boundingRect().center());
                speckList[i]->setRotation(-tetaDeg);
                //-----------------------------------------------
                qDebug()<<"max X="<<maxX;
                qDebug()<<"max Y="<<maxY;
                //qDebug()<<"Corners of the speckle:";
                //qDebug()<<"X1: "<<xR1<<"Y1: "<<yR1;
                //qDebug()<<"X2: "<<xR2<<"Y2: "<<yR2;
                //qDebug()<<"X3: "<<xR3<<"Y3: "<<yR3;
                //qDebug()<<"X4: "<<xR4<<"Y4: "<<yR4;
                xCoordsAfterRot.clear();yCoordsAfterRot.clear();
            }
        }
    }
    speckList.clear();
    qDebug()<<"The number of speckles: "<<speckCount;
    speckCountStr=QString::number(speckCount);
    ui->sCountEdit->setText(speckCountStr);
    //qDebug()<<"The width of the graphicsView is: "<<screenWidth;
    //qDebug()<<"The height of the graphicsView is: "<<screenHeight;
}
void MainWindow::printSceneDim()
{
    qDebug()<<"The width of the scene is: "<<scene->width();
    qDebug()<<"The height of the scene is: "<<scene->height();
}

void MainWindow::readRadii()
{
    if (dia->minorRadiusStr!=""){
        minorRadius=dia->minorRadiusStr.toFloat();
        qDebug()<<"the minor radius is: "<<minorRadius;
        ui->sDiamEdit->setText("");
    }
    if (dia->majorRadiusStr!=""){
        majorRadius=dia->majorRadiusStr.toFloat();
        qDebug()<<"the major radius is: "<<majorRadius;
        ui->sDiamEdit->setText("r1="+dia->minorRadiusStr+", r2="+dia->majorRadiusStr);
        specksElliptic=true;
    }
}

void MainWindow::setMenusAndToolBars()
{
    QPixmap saveImagePix("starblue.png");
    QPixmap saveCoordsPix("Save.png");
    QPixmap saveCoordsAsPix("SaveAs.png");
    QPixmap openCoordsPix("Open.png");
    mainToolBar=addToolBar("main toolbar");
    saveCoordsAct = new QAction(saveCoordsPix, tr("&Save Speckle Positions"), this);
    saveCoordsAsAct = new QAction(saveCoordsAsPix, tr("&Save Speckle Positions As"), this);
    saveImageAct = new QAction(saveImagePix, tr("&Save PNG"), this);
    fixedSizeAct = new QAction(tr("&Fixed Size"), this);
    openAct = new QAction(openCoordsPix, tr("&Open speckle configuration"), this);
    saveCoordsAct->setStatusTip(tr("Save the speckle positions in a text file"));
    saveCoordsAsAct->setStatusTip(tr("Save the speckle positions in a text file as"));
    saveImageAct->setStatusTip(tr("Save the scene as a PNG file"));
    QObject::connect(saveCoordsAct, SIGNAL(triggered()), this, SLOT(on_actionSave_Coords_triggered()));
    QObject::connect(saveCoordsAsAct, SIGNAL(triggered()), this, SLOT(on_actionSaveAs_Coords_triggered()));
    QObject::connect(saveImageAct, SIGNAL(triggered()), this, SLOT(on_actionSave_Image_triggered()));
    QObject::connect(fixedSizeAct, SIGNAL(triggered()), this, SLOT(showDialog()));
    QObject::connect(openAct, SIGNAL(triggered()), this, SLOT(on_actionOpen_triggered()));
    mainToolBar->addAction(saveCoordsAct);
    mainToolBar->addAction(saveImageAct);
    mainToolBar->addAction(saveCoordsAsAct);
    mainToolBar->addAction(openAct);
    fileMenu = menuBar()->addMenu(tr("&File"));
    editMenu = menuBar()->addMenu(tr("&Edit"));
    fileMenu->addAction(saveCoordsAct);
    fileMenu->addAction(saveCoordsAsAct);
    fileMenu->addAction(saveImageAct);
    fileMenu->addAction(openAct);
    speckGeomMenu = editMenu->addMenu(tr("&Speckle Geometry"));
    ellipticMenu = speckGeomMenu->addMenu(tr("&Elliptic"));
    ellipticMenu->addAction(fixedSizeAct);
    //saveAct->setShortcuts(QKeySequence::Save);
    //showDialogAct = new QAction(tr("&Show Dialog"), this);
    //showDialogAct->setStatusTip(tr("Show the dialog"));
    //loadAct = new QAction(tr("&Load"), this);
    //connect(saveAct, SIGNAL(triggered()), this, SLOT(saveScene()));
    //connect(showDialogAct, SIGNAL(triggered()), this, SLOT(showDialog()));
}

void MainWindow::setPensAndBrushes()
{
    redBrush.setColor(Qt::red);redBrush.setStyle(Qt::SolidPattern);
    blueBrush.setColor(Qt::blue);blueBrush.setStyle(Qt::SolidPattern);
    whiteBrush.setColor(Qt::white);
    blackPen.setColor(Qt::black);
    blackPen.setWidth(4);
    whitePen.setColor(Qt::white);
}
void MainWindow::saveScene(){
    QImage img(1024,768,QImage::Format_ARGB32_Premultiplied);
    QPainter p(&img);
    scene->render(&p);
    p.end();
    img.save("XXX.png");
    }

void MainWindow::showDialog()
{
    if (dia->isVisible()==false){
        dia->show();
    }
    //MyDialog mD;
    //mD.setModal(true); Background is deactivated
    //mD.exec();
}

void MainWindow::on_actionSave_Image_triggered()
{
    QImage img(1024,768,QImage::Format_ARGB32_Premultiplied);
    QPainter p(&img);
    scene->render(&p);
    p.end();
    img.save("XXX.png");
}

void MainWindow::on_actionSave_Coords_triggered()
{
    QFile speckleFile("E://Program Files/Work/created by me/QT/DIC/untitled/speckles.txt");
    speckleFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream speckOut(&speckleFile);
    for (int i=0; i< speckCount; i++){
        speckOut<<randomsL[i]<<"  ,  "<<randomsW[i]<<"\n";
    }
    speckOut<<speckCount<<" speckles in total";
    speckleFile.close();
}

void MainWindow::on_actionSaveAs_Coords_triggered()
{
    QString speckleFileStr = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
          tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
    if (!speckleFileStr.isEmpty()) {
        QFile speckleFile(speckleFileStr);
        if (!speckleFile.open(QIODevice::WriteOnly)) {
            // error message
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        } else {
            QTextStream speckOut(&speckleFile);
            for (int i=0; i< speckCount; i++){
                speckOut<<randomsL[i]<<"  ,  "<<randomsW[i]<<"\n";
            }
            speckOut<<speckCount<<" speckles in total";
            speckleFile.close();
        }
    }
}

void MainWindow::on_actionOpen_triggered()
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
        //int i;
        QString line;
        QStringList splittedLine, splittedLastLine;
        //i=0;
        speckCount=0;randomsL.clear();randomsW.clear();
        while(!in.atEnd()){
            line=in.readLine();
            splittedLine=line.split(",");
            splittedLastLine=line.split(" ");
            if(splittedLastLine[3]=="total"){
                qDebug()<<"Last line last word: "<<splittedLastLine[3];
                break;
            }
            randomsL.append(splittedLine[0].toDouble());
            randomsW.append(splittedLine[1].toDouble());
            qDebug()<<"Length random="<<randomsL[speckCount]<<"Width random="<<randomsW[speckCount];
            speckCount=speckCount+1;
        }
        fileO.close();
    }
    //Speckle the plate
    if (thereIsPlate==false){
        QMessageBox::information(this, "There is no plate to speckle", "Please draw the plate first");
        return;
    }
    on_cleanButton_clicked();
    readRadii();
    float X, Y;
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
            if(randomsW[i]*pWidth-speckDiam < 0){
                Y=randomsW[i]*pWidth;
            }
            else{
                Y=randomsW[i]*pWidth-speckDiam;
            }
            speckList.append(scene->addEllipse(/*randomsL[i]*pLength-speckDiam*/X, /*randomsW[i]*pWidth-speckDiam*/Y, speckDiam, speckDiam,
                        QPen(), redBrush));
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
            qDebug()<<"majorAxisHorizontal is "<<dia->majorAxisHorizontal;
            if(dia->majorAxisHorizontal==true){
                if(randomsL[i]*pLength-2*majorRadius < 0){
                    X=randomsL[i]*pLength;
                }
                else{
                    X=randomsL[i]*pLength-2*majorRadius;//most of the time this is used
                }
                if(randomsW[i]*pWidth-2*minorRadius < 0){
                    Y=randomsW[i]*pWidth;
                }
                else{
                    Y=randomsW[i]*pWidth-2*minorRadius;
                }
                speckList.append(scene->addEllipse(/*randomsL[i]*pLength-speckDiam*/X, /*randomsW[i]*pWidth-speckDiam*/Y, 2*majorRadius, 2*minorRadius,
                            QPen(), redBrush));
            }
            else if(dia->majorAxisVertical==true){
                if(randomsL[i]*pLength-2*minorRadius < 0){
                    X=randomsL[i]*pLength;
                }
                else{
                    X=randomsL[i]*pLength-2*minorRadius;//most of the time this is used
                }
                if(randomsW[i]*pWidth-2*majorRadius < 0){
                    Y=randomsW[i]*pWidth;
                }
                else{
                    Y=randomsW[i]*pWidth-2*majorRadius;
                }
                speckList.append(scene->addEllipse(/*randomsL[i]*pLength-speckDiam*/X, /*randomsW[i]*pWidth-speckDiam*/Y, 2*minorRadius, 2*majorRadius,
                            QPen(), redBrush));
            }
            //Major axis in vertical direction case
        }
    }
    speckList.clear();
    qDebug()<<"The number of speckles: "<<speckCount;
    speckCountStr=QString::number(speckCount);
    ui->sCountEdit->setText(speckCountStr);
}

void MainWindow::on_actionFixed_size_toggled(/*bool arg1*/)
{
    if (dia->isVisible()==false){
        dia->show();
    }
}
