#include "ellipticfixedsizedialog.h"
#include "ui_ellipticfixedsizedialog.h"

EllipticFixedSizeDialog::EllipticFixedSizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EllipticFixedSizeDialog)
{
    ui->setupUi(this);
    directionCount=0; //exclusive ler yerlesince buna gerek kalmayacak
    QVBoxLayout *vBox = new QVBoxLayout();
    vBox->addWidget(createRadiiEntryGroup());
    vBox->addWidget(createCheckBoxGroup());
    vBox->addWidget(createApplyOkBoxGroup());
    setLayout(vBox);
    setWindowTitle("Elliptic Speckle Properties");
    resize(280, 200);
}

EllipticFixedSizeDialog::~EllipticFixedSizeDialog()
{
    delete ui;
}

void EllipticFixedSizeDialog::applyBtn_clicked()
{
    QString radiusStr1=lineEditRadius1->text();
    QString radiusStr2=lineEditRadius2->text();
    float radius1=radiusStr1.toFloat();
    float radius2=radiusStr2.toFloat();
    if (radius1 <=radius2){
        minorRadiusStr=lineEditRadius1->text();
        majorRadiusStr=lineEditRadius2->text();
    }
    else{
        majorRadiusStr=lineEditRadius1->text();
        minorRadiusStr=lineEditRadius2->text();
    }
    radMinor=minorRadiusStr.toFloat();
    radMajor=majorRadiusStr.toFloat();
}

void EllipticFixedSizeDialog::OKBtn_clicked()
{
    EllipticFixedSizeDialog::close();
    if(minorRadiusStr!="" && majorRadiusStr ==""){
        QMessageBox::information(this, "Major radius missing", "Please enter the major radius");
    }
    if(majorRadiusStr!="" && minorRadiusStr ==""){
        QMessageBox::information(this, "Minor radius missing", "Please enter the minor radius");
    }
}

void EllipticFixedSizeDialog::majorAxisHor_clicked()
{
    majorAxisHorizontal=true;
    majorAxisVertical=false;
    majorAxisRandom=false;
}

void EllipticFixedSizeDialog::majorAxisVer_clicked()
{
    majorAxisHorizontal=false;
    majorAxisVertical=true;
    majorAxisRandom=false;
}

void EllipticFixedSizeDialog::majorAxisRan_clicked()
{
    majorAxisHorizontal=false;
    majorAxisVertical=false;
    majorAxisRandom=true;
}

QGroupBox *EllipticFixedSizeDialog::createRadiiEntryGroup()
{
    radGroupBox=new QGroupBox(tr("Major and minor radii"));
    radius1 =new QLabel(tr("radius1:"));
    radius2 = new QLabel(tr("radius2:"));
    lineEditRadius1 = new QLineEdit;
    lineEditRadius2 = new QLineEdit;
    radGrid=new QGridLayout;
    radGrid->addWidget(radius1, 0, 0);
    radGrid->addWidget(lineEditRadius1, 0, 1);
    radGrid->addWidget(radius2, 1, 0);
    radGrid->addWidget(lineEditRadius2, 1, 1);
    radGroupBox->setLayout(radGrid);
    return radGroupBox;
}

QGroupBox *EllipticFixedSizeDialog::createCheckBoxGroup()
{
    dirGroupBox = new QGroupBox();
    dirBtnGroup=new QButtonGroup();
    majorAxisHor =new QCheckBox(tr("major axis horizontal"));
    majorAxisVer = new QCheckBox(tr("major axis vertical"));
    majorAxisRan = new QCheckBox(tr("major axis random"));
    QObject::connect(majorAxisHor, SIGNAL(clicked()), this, SLOT(majorAxisHor_clicked()));
    QObject::connect(majorAxisVer, SIGNAL(clicked()), this, SLOT(majorAxisVer_clicked()));
    QObject::connect(majorAxisRan, SIGNAL(clicked()), this, SLOT(majorAxisRan_clicked()));
    //Checkboxes in a button group are by default exclusive
    dirBtnGroup->addButton(majorAxisHor);
    dirBtnGroup->addButton(majorAxisVer);
    dirBtnGroup->addButton(majorAxisRan);
    tickVBox=new QVBoxLayout;
    tickVBox->addWidget(majorAxisHor);
    tickVBox->addWidget(majorAxisVer);
    tickVBox->addWidget(majorAxisRan);
    dirGroupBox->setLayout(tickVBox);
    return dirGroupBox;
}

QGroupBox *EllipticFixedSizeDialog::createApplyOkBoxGroup()
{
    AppOKGroupBox = new QGroupBox();
    ApplyBtn =new QPushButton(tr("Apply"));
    OKBtn = new QPushButton(tr("OK"));
    QObject::connect(ApplyBtn, SIGNAL(clicked()), this, SLOT(applyBtn_clicked()));
    QObject::connect(OKBtn, SIGNAL(clicked()), this, SLOT(OKBtn_clicked()));
    BtnHBox = new QHBoxLayout;
    BtnHBox->addWidget(ApplyBtn);
    BtnHBox->addWidget(OKBtn);
    AppOKGroupBox->setLayout(BtnHBox);
    return AppOKGroupBox;
}
