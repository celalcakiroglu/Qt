#include "mainwindow.h"
#include "canvas.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    canvas = new Canvas(this);
    dia = new EllipticFixedSizeDialog(this);
    setCentralWidget(canvas);
    createActions();
    createMenusAndToolbars();
    readRadii();
    setWindowTitle(tr("Speckles"));
    resize(500,500);
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

//void MainWindow::plateHeightLnEdt_changed()
//{
//    QString pHeightStr=plateHeightLnEdt->text();
//    canvas->pHeight=pHeightStr.toFloat();
//    qDebug()<<"Plate height changed to"<<canvas->pHeight;
//}

//void MainWindow::plateLengthLnEdt_changed()
//{
//    QString pLengthStr=plateLengthLnEdt->text();
 //   canvas->pLength=pLengthStr.toFloat();
 //   qDebug()<<"Plate length changed to"<<canvas->pLength;
//}

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

//QGroupBox *MainWindow::createLowerGroup()
//{
 //   lowerGroup=new QGroupBox(tr(""));
 //   plateLengthLbl =new QLabel(tr("Long side of the plate:"));
 //   plateHeightLbl = new QLabel(tr("Short side of the plate:"));
 //   speckCountLbl = new QLabel(tr("Number of speckles:"));
 //   plateLengthLnEdt = new QLineEdit;plateLengthLnEdt->setMaximumWidth((int)(this->width())/4);
 //   plateHeightLnEdt = new QLineEdit;plateHeightLnEdt->setMaximumWidth((int)(this->width())/4);
 //   speckCountLnEdt = new QLineEdit;speckCountLnEdt->setMaximumWidth((int)(this->width())/4);
 //   drawPlateBtn=new QPushButton("Draw the plate");
 //   QObject::connect(drawPlateBtn, SIGNAL(clicked()), canvas, SLOT(drawPlateBtn_clicked()));
 //   QObject::connect(plateHeightLnEdt, SIGNAL(editingFinished()), this, SLOT(plateHeightLnEdt_changed()));
 //   QObject::connect(plateLengthLnEdt, SIGNAL(editingFinished()), this, SLOT(plateLengthLnEdt_changed()));
 //   speckPlateBtn=new QPushButton("Speckle the Plate");
 //   cleanScreenBtn=new QPushButton("Clean the Screen");
 //   cleanPlateBtn=new QPushButton("Clean the Plate");
 //   lowerGrid=new QGridLayout;
 //   QWidget w1, w2;
 //   lowerGrid->addWidget(plateLengthLbl, 0, 0);
 //   lowerGrid->addWidget(plateLengthLnEdt, 0, 1);
 //   lowerGrid->addWidget(plateHeightLbl, 1, 0);
 //   lowerGrid->addWidget(plateHeightLnEdt, 1, 1);
 //   lowerGrid->addWidget(speckCountLbl, 2, 0);
 //   lowerGrid->addWidget(speckCountLnEdt, 2, 1);
 //   lowerGrid->addWidget(&w1 , 3, 0);
 //   lowerGrid->addWidget(&w2, 3, 1);
 //   lowerGrid->addWidget(drawPlateBtn, 0, 2);
 //   lowerGrid->addWidget(speckPlateBtn, 1, 2);
 //   lowerGrid->addWidget(cleanScreenBtn, 2, 2);
 //   lowerGrid->addWidget(cleanPlateBtn, 3, 2);
 //   lowerGroup->setLayout(lowerGrid);
 //   return lowerGroup;
//}

//void MainWindow::setMainLayout()
//{
//    mainVBox = new QVBoxLayout;
//    mainVBox->addWidget(canvas);
//    mainVBox->addWidget(createLowerGroup());
//    this->setCentralWidget(new QWidget);
//    this->centralWidget()->setLayout(mainVBox);
//}

void MainWindow::readRadii()
{
    if (dia->minorRadiusStr!=""){
        canvas->minorRadius=dia->minorRadiusStr.toFloat();
        qDebug()<<"the minor radius is: "<<canvas->minorRadius;
    }else{canvas->minorRadius=0;}
    if (dia->majorRadiusStr!=""){
        canvas->majorRadius=dia->majorRadiusStr.toFloat();
        qDebug()<<"the major radius is: "<<canvas->majorRadius;
        canvas->specksElliptic=true;
    }else{canvas->majorRadius=0;}
}

void MainWindow::createActions()
{
    qDebug()<<"We entered createActions";
    QPixmap saveImagePix("starblue.png");
    QPixmap saveCoordsPix("Save.png");
    QPixmap saveCoordsAsPix("SaveAs.png");
    QPixmap openCoordsPix("Open.png");
    QPixmap drawPlate("DrawPlate.png");

    drawPlateAct=new QAction(tr("&draw Plate"), this);
    connect(drawPlateAct, SIGNAL(triggered()), canvas, SLOT(drawPlateBtn_clicked()));
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

    clearScreenAct = new QAction(tr("&Clear Screen"), this);
    clearScreenAct->setShortcut(tr("Ctrl+L"));
    connect(clearScreenAct, SIGNAL(triggered()),
            canvas, SLOT(clearImage()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    //saveCoordsAct = new QAction(saveCoordsPix, tr("&Save Speckle Positions"), this);
    //connect(saveCoordsAct, SIGNAL(triggered()), this, SLOT(on_actionSave_Coords_triggered()));

    //saveCoordsAsAct = new QAction(saveCoordsAsPix, tr("&Save Speckle Positions As"), this);
   // connect(saveCoordsAsAct, SIGNAL(triggered()), this, SLOT(on_actionSaveAs_Coords_triggered()));

   // saveImageAct = new QAction(saveImagePix, tr("&Save PNG"), this);
   // connect(saveImageAct, SIGNAL(triggered()), this, SLOT(on_actionSave_Image_triggered()));

    fixedSizeAct = new QAction(tr("&Fixed Size"), this);
    connect(fixedSizeAct, SIGNAL(triggered()), this, SLOT(showDialog()));

   // saveCoordsAct->setStatusTip(tr("Save the speckle positions in a text file"));
  //  saveCoordsAsAct->setStatusTip(tr("Save the speckle positions in a text file as"));
  //  saveImageAct->setStatusTip(tr("Save the scene as a PNG file"));
    qDebug()<<"We came to the end of createActions";
}
void MainWindow::createMenusAndToolbars()
{
    qDebug()<<"We entered createMenusAndToolbars";
    mainToolBar=addToolBar("main toolbar");
  //  mainToolBar->addAction(saveCoordsAct);
    //mainToolBar->addAction(saveImageAct);
 //   mainToolBar->addAction(saveCoordsAsAct);
    mainToolBar->addAction(openAct);
    mainToolBar->addAction(drawPlateAct);
    //mainToolBar->addAction(speckleAct);
 //   fileMenu->addAction(saveCoordsAct);
 //   fileMenu->addAction(saveCoordsAsAct);
    fileMenu = new QMenu(tr("&File"), this);
    qDebug()<<"We created the filemenu";
    //fileMenu->addAction(saveImageAct);
    fileMenu->addAction(openAct);
    editMenu = new QMenu(tr("&Edit"), this);
    speckGeomMenu = editMenu->addMenu(tr("&Speckle Geometry"));
    ellipticMenu = speckGeomMenu->addMenu(tr("&Elliptic"));
    ellipticMenu->addAction(fixedSizeAct);
    saveAsMenu = new QMenu(tr("&Save As"), this);
    foreach (QAction *action, saveAsActs)
        saveAsMenu->addAction(action);


    fileMenu->addAction(openAct);
    fileMenu->addMenu(saveAsMenu);
 //   fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    optionMenu = new QMenu(tr("&Options"), this);
    optionMenu->addAction(penColorAct);
    optionMenu->addAction(penWidthAct);
    optionMenu->addSeparator();
    optionMenu->addAction(clearScreenAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(optionMenu);
    menuBar()->addMenu(helpMenu);
    menuBar()->addMenu(editMenu);
    qDebug()<<"We came to the end of createMenusAndToolbars";
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
void MainWindow::showDialog()
{
    if (dia->isVisible()==false){
        dia->show();
    }
    //MyDialog mD;
    //mD.setModal(true); Background is deactivated
    //mD.exec();
}
