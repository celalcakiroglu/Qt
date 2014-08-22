#include "mainwindow.h"
#include "canvas.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    canvas = new Canvas(this);
    ellipticFixedSizeDia = new EllipticFixedSizeDialog(this);
    plateSizeDia=new PlateSizeDialog(this);
    rigidBodyTransDia = new rigidBodyTranslation(this);
    uniformExtDia = new uniformExtension(this);
    setCentralWidget(canvas);
    statusBar();
    createActions();
    createMenusAndToolbars();
    //readRadii();
    setWindowTitle(tr("Speckles"));
    //this->setWindowState(this->windowState() & ~Qt::WindowMinimized | Qt::WindowActive);
    assignDefaultCanvasValues();
    updateStatusBar();
    //Assigning the default plate size
    //Later define a function which assigns all the default values
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::open()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                                   tr("Open File"), QDir::currentPath());
        if (!fileName.isEmpty())
            canvas->openImage(fileName);
    }
}

void MainWindow::save()
{
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    saveFile(fileFormat);
}

void MainWindow::penColor()
{
    QColor newColor = QColorDialog::getColor(canvas->penColor());
    if (newColor.isValid())
        canvas->setPenColor(newColor);
}

void MainWindow::brushColor()
{
    QColor newColorB = QColorDialog::getColor(canvas->brushColor());
    if (newColorB.isValid())
        canvas->setBrushColor(newColorB);
}

void MainWindow::penWidth()
{
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Scribble"),
                                            tr("Select pen width:"),
                                            canvas->penWidth(),
                                            1, 50, 1, &ok);
    if (ok)
        canvas->setPenWidth(newWidth);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Scribble"),
            tr("<p>The <b>Scribble</b> example shows how to use QMainWindow as the "
               "base widget for an application, and how to reimplement some of "
               "QWidget's event handlers to receive the events generated for "
               "the application's widgets:</p><p> We reimplement the mouse event "
               "handlers to facilitate drawing, the paint event handler to "
               "update the application and the resize event handler to optimize "
               "the application's appearance. In addition we reimplement the "
               "close event handler to intercept the close events before "
               "terminating the application.</p><p> The example also demonstrates "
               "how to use QPainter to draw an image in real time, as well as "
               "to repaint widgets.</p>"));
}

void MainWindow::readPlateSize(){
    if (plateSizeDia->pLengthStr!=""){
        canvas->pLength=plateSizeDia->plateLength;
        qDebug()<<"Plate length is: "<<canvas->pLength;
    }else{canvas->pLength=0;}
    if (plateSizeDia->pHeightStr!=""){
        canvas->pHeight=plateSizeDia->plateHeight;
        qDebug()<<"Plate length is: "<<canvas->pHeight;
    }else{canvas->pHeight=0;}
}

void MainWindow::createActions()
{
    QPixmap saveImagePix("starblue.png");
    QPixmap saveCoordsPix("Save.png");
    QPixmap saveCoordsAsPix("SaveAs.png");
    QPixmap openCoordsPix("Open.png");
    QPixmap drawPlate("DrawPlate.png");

    drawPlateAct=new QAction(tr("&draw Plate"), this);
    connect(drawPlateAct, SIGNAL(triggered()), this, SLOT(assgnCnvsPrpsPlate()));
    connect(drawPlateAct, SIGNAL(triggered()), canvas, SLOT(drawPlateBtn_clicked()));
    connect(drawPlateAct, SIGNAL(triggered()), this, SLOT(updateStatusBar()));
    speckleAct=new QAction(tr("&Speckle"), this);
    connect(speckleAct, SIGNAL(triggered()), this, SLOT(assgnCnvsPrpsSpeckle()));
    connect(speckleAct, SIGNAL(triggered()), canvas, SLOT(speckPlateBtn_clicked()));
    connect(speckleAct, SIGNAL(triggered()), this, SLOT(updateStatusBar()));
    drawRBTAct = new QAction(tr("&Draw RBT"), this);
    connect(drawRBTAct, SIGNAL(triggered()), this, SLOT(assgnCnvsPrpsRBT()));
    connect(drawRBTAct, SIGNAL(triggered()), canvas, SLOT(drawRBT_clicked()));
    connect(drawPlateAct, SIGNAL(triggered()), this, SLOT(updateStatusBar()));
    drawUEAct=new QAction(tr("&Draw UE"), this);
    connect(drawUEAct, SIGNAL(triggered()), this, SLOT(assgnCnvsPrpsUE()));
    connect(drawUEAct, SIGNAL(triggered()), canvas, SLOT(drawUE_clicked()));
    connect(drawPlateAct, SIGNAL(triggered()), this, SLOT(updateStatusBar()));

    readSpeckCoordsAct = new QAction(tr("&Read Speckles"), this);
    connect(readSpeckCoordsAct, SIGNAL(triggered()), canvas, SLOT(readSpeckCoords_clicked()));
    connect(readSpeckCoordsAct, SIGNAL(triggered()), this, SLOT(updateStatusBar()));

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    foreach (QByteArray format, QImageWriter::supportedImageFormats()) {
        QString text = tr("%1...").arg(QString(format).toUpper());

        QAction *action = new QAction(text, this);
        action->setData(format);
        connect(action, SIGNAL(triggered()), this, SLOT(save()));
        saveAsActs.append(action);
    }

  //  printAct = new QAction(tr("&Print..."), this);
  //  connect(printAct, SIGNAL(triggered()), canvas, SLOT(print()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    penColorAct = new QAction(tr("&Pen Color..."), this);
    connect(penColorAct, SIGNAL(triggered()), this, SLOT(penColor()));

    penWidthAct = new QAction(tr("Pen &Width..."), this);
    connect(penWidthAct, SIGNAL(triggered()), this, SLOT(penWidth()));

    brushColorAct = new QAction(tr("&Brush Color..."), this);
    connect(brushColorAct, SIGNAL(triggered()), this, SLOT(brushColor()));

    clearScreenAct = new QAction(tr("&Clear Screen"), this);
    clearScreenAct->setShortcut(tr("Ctrl+L"));
    connect(clearScreenAct, SIGNAL(triggered()),
            canvas, SLOT(clearImage()));
    connect(clearScreenAct, SIGNAL(triggered()), this, SLOT(updateStatusBar()));

    updateStatusAct = new QAction(tr("&Update Status"), this);
    updateStatusAct->setShortcut(tr("Ctrl+U"));
    connect(updateStatusAct, SIGNAL(triggered()), this, SLOT(updateStatusBar()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    saveInitCoordsAct = new QAction(saveCoordsPix, tr("&Save Initial Speckle Positions"), this);
    connect(saveInitCoordsAct, SIGNAL(triggered()), canvas, SLOT(saveInitCoords_clicked()));

    saveInitCoordsAsAct = new QAction(saveCoordsAsPix, tr("&Save Initial Speckle Positions As"), this);
    connect(saveInitCoordsAsAct, SIGNAL(triggered()), canvas, SLOT(saveInitCoordsAs_clicked()));

    saveDispCoordsAct = new QAction(saveCoordsPix, tr("&Save Initial Speckle Positions"), this);
    connect(saveDispCoordsAct, SIGNAL(triggered()), canvas, SLOT(saveDispCoords_clicked()));

    saveDispCoordsAsAct = new QAction(saveCoordsAsPix, tr("&Save Initial Speckle Positions As"), this);
    connect(saveDispCoordsAsAct, SIGNAL(triggered()), canvas, SLOT(saveDispCoordsAs_clicked()));

    fixedSizeAct = new QAction(tr("&Fixed Size"), this);
    connect(fixedSizeAct, SIGNAL(triggered()), this, SLOT(showEllipticFixedSizeDialog()));

    plateSizeAct = new QAction(tr("&Plate Size"), this);
    connect(plateSizeAct, SIGNAL(triggered()), this, SLOT(showPlateSizeDialog()));

    rigidBodyTranslationAct = new QAction(tr("&Rigid Body Translation"), this);
    connect(rigidBodyTranslationAct, SIGNAL(triggered()), this, SLOT(showRigidBodyTransDialog()));

    uniformExtensionAct = new QAction(tr("&Uniform Extension"), this);
    connect(uniformExtensionAct, SIGNAL(triggered()), this, SLOT(showUniformExtDialog()));

    saveInitCoordsAct->setStatusTip(tr("Save the initial speckle positions in a text file"));
    saveInitCoordsAsAct->setStatusTip(tr("Save the intial speckle positions in a text file as"));

}
void MainWindow::createMenusAndToolbars()
{
    mainToolBar=addToolBar("main toolbar");
  //  mainToolBar->addAction(saveCoordsAct);
    //mainToolBar->addAction(saveImageAct);
 //   mainToolBar->addAction(saveCoordsAsAct);
    mainToolBar->addAction(openAct);mainToolBar->addSeparator();
    mainToolBar->addAction(drawPlateAct);mainToolBar->addSeparator();
    mainToolBar->addAction(speckleAct);mainToolBar->addSeparator();
    mainToolBar->addAction(drawRBTAct);mainToolBar->addSeparator();
    mainToolBar->addAction(drawUEAct);mainToolBar->addSeparator();
    //mainToolBar->addAction(speckleAct);
 //   fileMenu->addAction(saveCoordsAct);
 //   fileMenu->addAction(saveCoordsAsAct);
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveInitCoordsAct);
    fileMenu->addAction(saveInitCoordsAsAct);
    fileMenu->addAction(saveDispCoordsAct);
    fileMenu->addAction(saveDispCoordsAsAct);
    fileMenu->addAction(readSpeckCoordsAct);
    editMenu = new QMenu(tr("&Edit"), this);
    plateGeomMenu = editMenu->addMenu(tr("&Plate Geometry"));
    plateGeomMenu->addAction(plateSizeAct);
    speckGeomMenu = editMenu->addMenu(tr("&Speckle Geometry"));
    ellipticMenu = speckGeomMenu->addMenu(tr("&Elliptic"));
    ellipticMenu->addAction(fixedSizeAct);
    saveAsMenu = new QMenu(tr("&Save As"), this);
    foreach (QAction *action, saveAsActs)
        saveAsMenu->addAction(action);


    fileMenu->addAction(openAct);
    fileMenu->addMenu(saveAsMenu);
  //fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    optionMenu = new QMenu(tr("&Options"), this);
    optionMenu->addAction(penColorAct);
    optionMenu->addAction(penWidthAct);
    optionMenu->addAction(brushColorAct);
    optionMenu->addSeparator();
    optionMenu->addAction(clearScreenAct);
    optionMenu->addAction(updateStatusAct);

    displacementMenu =new QMenu(tr("&Displacement"), this);
    displacementMenu->addAction(rigidBodyTranslationAct);
    displacementMenu->addAction(uniformExtensionAct);
  //  helpMenu = new QMenu(tr("&Help"), this);
  //  helpMenu->addAction(aboutAct);
  //  helpMenu->addAction(aboutQtAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(editMenu);
    menuBar()->addMenu(optionMenu);
    menuBar()->addMenu(displacementMenu);
  //  menuBar()->addMenu(helpMenu);
}


bool MainWindow::maybeSave()
{
    if (canvas->isModified()) {
       QMessageBox::StandardButton ret;
       ret = QMessageBox::warning(this, tr("Scribble"),
                          tr("The image has been modified.\n"
                             "Do you want to save your changes?"),
                          QMessageBox::Save | QMessageBox::Discard
                          | QMessageBox::Cancel);
        if (ret == QMessageBox::Save) {
            return saveFile("png");
        } else if (ret == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}

bool MainWindow::saveFile(const QByteArray &fileFormat)
{
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                               initialPath,
                               tr("%1 Files (*.%2);;All Files (*)")
                               .arg(QString(fileFormat.toUpper()))
                               .arg(QString(fileFormat)));
    if (fileName.isEmpty()) {
        return false;
    } else {
        return canvas->saveImage(fileName, fileFormat);
    }
}
void MainWindow::showEllipticFixedSizeDialog()
{
    if (ellipticFixedSizeDia->isVisible()==false){
        ellipticFixedSizeDia->show();
    }
}

void MainWindow::showPlateSizeDialog()
{
    if (plateSizeDia->isVisible()==false){
        plateSizeDia->show();
    }
}

void MainWindow::showRigidBodyTransDialog()
{
    if (rigidBodyTransDia->isVisible()==false){
        rigidBodyTransDia->show();
    }
}

void MainWindow::showUniformExtDialog(){
    if (uniformExtDia->isVisible()==false){
        uniformExtDia->show();
    }
}

void MainWindow::assignDefaultCanvasValues()
{
    canvas->pLength=1450;canvas->pHeight=1100;
    canvas->plateArea=canvas->pLength * canvas->pHeight;
    plateSizeDia->plateLength=canvas->pLength;
    plateSizeDia->plateHeight=canvas->pHeight;
    canvas->speckCountInit=100;canvas->speckCountUp=0;
    canvas->numSpeckSet=0;
    ellipticFixedSizeDia->majorAxisRandom=true;
    ellipticFixedSizeDia->radMajor=5;
    ellipticFixedSizeDia->radMinor=3;
    canvas->radH=ellipticFixedSizeDia->radMajor;
    canvas->radV=ellipticFixedSizeDia->radMinor;
    canvas->speckleArea=M_PI*canvas->radH*canvas->radV;
    canvas->speckleDensity=0;
    canvas->speckShape=ellipticR;
}

void MainWindow::assignCanvasProps()
{
    canvas->pLength=plateSizeDia->plateLength;
    canvas->pHeight=plateSizeDia->plateHeight;
    if(canvas->pLength <= 0)canvas->pLength=1450;
    if(canvas->pHeight <= 0)canvas->pHeight=1100;
    canvas->plateArea=canvas->pLength*canvas->pHeight;
    canvas->rigidBodyDX1=rigidBodyTransDia->deltaX1;
    canvas->rigidBodyDX2=rigidBodyTransDia->deltaX2;
    if(canvas->pHeight > canvas->pLength){
        QMessageBox::information(this, "Width of the plate can't be greater than its length.", "The values will be swapped");
        float *temp;temp=new float;
        *temp=canvas->pHeight;canvas->pHeight=canvas->pLength;canvas->pLength=*temp;delete temp;
    }
    if(canvas->pLength >= 0.8*canvas->width() /*&& canvas->thereisPlate==false*/){
        float coeff = canvas->pLength/(0.8*canvas->height());
        canvas->pHeight=canvas->pHeight/coeff;
        canvas->pLength=0.8*canvas->width();
    }
    if (canvas->pHeight>=0.8*canvas->height() /*&& canvas->thereisPlate==false*/){
        float coeff2 = canvas->pHeight/(0.8*canvas->height());
        canvas->pLength=canvas->pLength/coeff2;
        canvas->pHeight=0.8*canvas->height();
    }
    if (ellipticFixedSizeDia->majorAxisHorizontal==true){
        canvas->radH=ellipticFixedSizeDia->radMajor;
        canvas->radV=ellipticFixedSizeDia->radMinor;
        canvas->speckShape=ellipticH;
    }
    if (ellipticFixedSizeDia->majorAxisVertical==true){
        canvas->radH=ellipticFixedSizeDia->radMinor;
        canvas->radV=ellipticFixedSizeDia->radMajor;
        canvas->speckShape=ellipticV;
    }
    if (ellipticFixedSizeDia->majorAxisRandom==true){
        canvas->radH=ellipticFixedSizeDia->radMajor;
        canvas->radV=ellipticFixedSizeDia->radMinor;
        canvas->speckShape=ellipticR;
    }
}

void MainWindow::assgnCnvsPrpsPlate()
{
    canvas->pLength=plateSizeDia->plateLength;
    canvas->pHeight=plateSizeDia->plateHeight;
    if(canvas->pLength <= 0)canvas->pLength=1450;
    if(canvas->pHeight <= 0)canvas->pHeight=1100;
    if(canvas->pHeight > canvas->pLength){
        QMessageBox::information(this, "Width of the plate can't be greater than its length.", "The values will be swapped");
        float *temp;temp=new float;
        *temp=canvas->pHeight;canvas->pHeight=canvas->pLength;canvas->pLength=*temp;delete temp;
    }
    if(canvas->pLength >= 0.8*canvas->width()){
        float coeff = canvas->pLength/(0.8*canvas->height());
        canvas->pHeight=canvas->pHeight/coeff;
        canvas->pLength=0.8*canvas->width();
    }
    if (canvas->pHeight>=0.8*canvas->height()){
        float coeff2 = canvas->pHeight/(0.8*canvas->height());
        canvas->pLength=canvas->pLength/coeff2;
        canvas->pHeight=0.8*canvas->height();
    }
    canvas->plateOriginX=canvas->width()/2-canvas->pLength/2;
    canvas->plateOriginY=canvas->height()/2-canvas->pHeight/2;
    canvas->plateArea=canvas->pLength*canvas->pHeight;
}

void MainWindow::assgnCnvsPrpsSpeckle()
{
    if (ellipticFixedSizeDia->majorAxisHorizontal==true){
        canvas->radH=ellipticFixedSizeDia->radMajor;
        canvas->radV=ellipticFixedSizeDia->radMinor;
        canvas->speckShape=ellipticH;
    }
    if (ellipticFixedSizeDia->majorAxisVertical==true){
        canvas->radH=ellipticFixedSizeDia->radMinor;
        canvas->radV=ellipticFixedSizeDia->radMajor;
        canvas->speckShape=ellipticV;
    }
    if (ellipticFixedSizeDia->majorAxisRandom==true){
        canvas->radH=ellipticFixedSizeDia->radMajor;
        canvas->radV=ellipticFixedSizeDia->radMinor;
        canvas->speckShape=ellipticR;
    }
    canvas->speckleArea=M_PI*canvas->radH*canvas->radV;
}

void MainWindow::assgnCnvsPrpsRBT()
{
    canvas->rigidBodyDX1=rigidBodyTransDia->deltaX1;
    canvas->rigidBodyDX2=rigidBodyTransDia->deltaX2;
}

void MainWindow::assgnCnvsPrpsUE()
{
    canvas->uniExtK1=uniformExtDia->K1;
    canvas->uniExtK2=uniformExtDia->K2;
}

void MainWindow::updateStatusBar()
{
    QString length, width, speckCountUpStr, statusText, speckleDensityStr;
    length =  QString::number(canvas->pLength);
    width=QString::number(canvas->pHeight);
    qDebug()<<"number of speckles="<<canvas->speckCountUp;
    speckCountUpStr=QString::number(canvas->speckCountUp);
    speckleDensityStr=QString::number(canvas->speckleDensity);
    statusText="Plate dimensions: "+length+" X "+width+
            "  number of speckles: " + speckCountUpStr+
            "  speckle density: " + speckleDensityStr;
    this->statusBar()->showMessage(statusText);
}


