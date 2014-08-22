#include "window.h"
#include "ui_window.h"

const int IdRole = Qt::UserRole;

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    canvas = new Canvas(this);
    mainLayout = new QGridLayout;
    rightSideGroupBox = new QGroupBox;
    rightSideGroupBox->setLayout(createRightSide());
    mainLayout->setColumnStretch(0,3);
    mainLayout->setColumnStretch(1,1);
    mainLayout->addWidget(canvas,0,0);
    mainLayout->addWidget(rightSideGroupBox, 0,1,Qt::AlignRight);
    setLayout(mainLayout);
    setWindowTitle(tr("Basic Drawing"));
    connect(canvasBgCombo, SIGNAL(activated(int)), this, SLOT(BgColorChanged()));
    connect(canvasShapeComboC, SIGNAL(activated(int)),this,SLOT(shapeChanged()));
    connect(shapeAddBtnC, SIGNAL(clicked()),this,SLOT(openDimsWindow()));
    connect(canvas->getLineDia()->getOKBtn(), SIGNAL(clicked()), canvas->getLineDia(), SLOT(assignValues()));
    connect(canvas->getLineDia()->getOKBtn(), SIGNAL(clicked()), canvas, SLOT(drawShape()));
    connect(canvas->getLineDia()->getCancelBtn(), SIGNAL(clicked()), canvas, SLOT(clearLastLine()));
    connect(canvas->getLineDia()->getLineColorCombo(), SIGNAL(activated(int)), canvas, SLOT(assignLineColor()));
    connect(canvas->getLineDia()->getLineWidthCombo(), SIGNAL(activated(int)), canvas, SLOT(assignLineWidth()));
    connect(canvas->getPolyLineDia()->getAddBtn(), SIGNAL(clicked()), canvas->getPolyLineDia(), SLOT(assignValues()));
    connect(canvas->getPolyLineDia()->getAddBtn(), SIGNAL(clicked()), canvas, SLOT(drawShape()));
    connect(canvas->getPolyLineDia()->getDoneBtn(), SIGNAL(clicked()),canvas,SLOT(polyLineDone()));
    connect(canvas->getPolyLineDia()->getCancelBtn(), SIGNAL(clicked()),canvas,SLOT(clearLastPolyLine()));
    connect(canvas->getPolyLineDia()->getUndoAct(), SIGNAL(triggered()),canvas, SLOT(undoLastPart()));
    connect(canvas->getPolyLineDia()->getLineColorCombo(), SIGNAL(activated(int)), canvas, SLOT(assignLineColor()));
    connect(canvas->getPolyLineDia()->getLineWidthCombo(), SIGNAL(activated(int)), canvas, SLOT(assignLineWidth()));
    connect(canvas->getCsys2DDia()->getApplyBtn(),SIGNAL(clicked()),canvas->getCsys2DDia(), SLOT(assignValues()));
    connect(canvas->getCsys2DDia()->getApplyBtn(), SIGNAL(clicked()), canvas, SLOT(drawShape()));
    connect(canvas->getCsys2DDia()->getCancelBtn(), SIGNAL(clicked()), canvas, SLOT(clearCSys()));
}

Window::~Window()
{
    delete ui;
}

Canvas *Window::getCanvas()
{
    return canvas;
}

void Window::BgColorChanged()
{
    Farbe farbe=Farbe(canvasBgCombo->itemData(canvasBgCombo->currentIndex(),IdRole).toInt());
    canvas->setBgColor(farbe);
}

void Window::shapeChanged()
{
    Shape shape=Shape(canvasShapeComboC->itemData(canvasShapeComboC->currentIndex(),IdRole).toInt());
    canvas->setShape(shape);
}

void Window::openDimsWindow()
{
    switch(canvas->getShape()){
        case Line:
            if (canvas->getLineDia()->isVisible()==false){
                canvas->getLineDia()->show();
            }
            break;
        case PolyLine:
            if (canvas->getPolyLineDia()->isVisible()==false){
                canvas->getPolyLineDia()->show();
            }
            break;
        case CSys2D:
            if(canvas->getCsys2DDia()->isVisible()==false){
                canvas->getCsys2DDia()->show();
            }
    }
}

QGroupBox *Window::editGroup()
{
    editGroupBox = new QGroupBox(tr("Edit"));
    canvasBgLabel = new QLabel(tr("Background Color:"));canvasBgCombo = new QComboBox();
    canvasBgCombo->addItem(tr("White"),weiss);canvasBgCombo->addItem(tr("Green"), gruen);
    canvasBgCombo->addItem(tr("Darkblue"), darkblue);canvasBgCombo->addItem(tr("Yellow"), gelb);
    canvasBgCombo->addItem(tr("Skyblue"), skyblue);
    editGrid = new QGridLayout;
    editGrid->addWidget(canvasBgLabel,0,0);
    editGrid->addWidget(canvasBgCombo,0,1);
    editGroupBox->setLayout(editGrid);
    return editGroupBox;
}

QGroupBox *Window::coordInpGroup()
{
    coordInpGroupBox =new QGroupBox(tr("Coordinate Input"));
    shapeAddBtnC = new QPushButton("Add");
    canvasShapeLabelC = new QLabel(tr("Shape"));
    canvasShapeComboC = new QComboBox();
    canvasShapeComboC->addItem(tr("Select"), None);
    canvasShapeComboC->addItem(tr("Line"), Line);
    canvasShapeComboC->addItem(tr("PolyLine"), PolyLine);
    canvasShapeComboC->addItem(tr("CSys2D"), CSys2D);
    canvasShapeComboC->addItem(tr("Polygon"), Polygon);
    canvasShapeComboC->addItem(tr("RoundedRect"), RoundedRect);
    canvasShapeComboC->addItem(tr("Text"), Text);
    canvasShapeComboC->addItem(tr("Ellipse"), Ellipse);
    canvasShapeComboC->addItem(tr("Arc"), Arc);
    canvasShapeComboC->addItem(tr("Pixmap"), Pixmap);
    canvasShapeComboC->addItem(tr("Rect"), Rect);
    canvasShapeComboC->addItem(tr("Chord"), Chord);
    canvasShapeComboC->addItem(tr("Path"), Path);
    canvasShapeComboC->addItem(tr("Pie"), Pie);
    canvasShapeComboC->addItem(tr("Points"), Points);
    coordInpGrid = new QGridLayout;
    coordInpGrid->addWidget(canvasShapeLabelC, 1, 0);
    coordInpGrid->addWidget(canvasShapeComboC, 1, 1);
    coordInpGrid->addWidget(shapeAddBtnC, 1,2);
    coordInpGroupBox->setLayout(coordInpGrid);
    return coordInpGroupBox;
}

QGroupBox *Window::mouseInpGroup()
{
    mouseInpGroupBox =new QGroupBox(tr("Mouse Input"));
    shapeAddBtnM = new QPushButton("Add");
    canvasShapeLabelM = new QLabel(tr("Shape"));
    canvasShapeComboM = new QComboBox();
    canvasShapeComboM->addItem(tr("Select"), None);
    canvasShapeComboM->addItem(tr("Line"), Line);
    canvasShapeComboM->addItem(tr("PolyLine"), PolyLine);
    canvasShapeComboM->addItem(tr("Polygon"), Polygon);
    canvasShapeComboM->addItem(tr("RoundedRect"), RoundedRect);
    canvasShapeComboM->addItem(tr("Text"), Text);
    canvasShapeComboM->addItem(tr("Ellipse"), Ellipse);
    canvasShapeComboM->addItem(tr("Arc"), Arc);
    canvasShapeComboM->addItem(tr("Pixmap"), Pixmap);
    canvasShapeComboM->addItem(tr("Rect"), Rect);
    canvasShapeComboM->addItem(tr("Chord"), Chord);
    canvasShapeComboM->addItem(tr("Path"), Path);
    canvasShapeComboM->addItem(tr("Pie"), Pie);
    canvasShapeComboM->addItem(tr("Points"), Points);
    mouseInpGrid = new QGridLayout;
    mouseInpGrid->addWidget(canvasShapeLabelM, 1, 0);
    mouseInpGrid->addWidget(canvasShapeComboM, 1, 1);
    mouseInpGrid->addWidget(shapeAddBtnM, 1,2);
    mouseInpGroupBox->setLayout(mouseInpGrid);
    return mouseInpGroupBox;
}

QGridLayout *Window::createRightSide()
{
    rightLayout = new QGridLayout;
    rightLayout->addWidget(editGroup(), 0, 0);
    rightLayout->addWidget(coordInpGroup(),1,0);
    rightLayout->addWidget(mouseInpGroup(),2,0);
    rightLayout->addWidget(coordInpGroupBox, 1, 0);
    return rightLayout;
}
