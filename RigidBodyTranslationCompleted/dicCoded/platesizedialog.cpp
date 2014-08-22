#include "platesizedialog.h"
#include "ui_platesizedialog.h"

PlateSizeDialog::PlateSizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlateSizeDialog)
{
    ui->setupUi(this);
    QVBoxLayout *vBox=new QVBoxLayout();
    vBox->addWidget(createPlateDimGroup());
    vBox->addWidget(createApplyOkBoxGroup());
    setLayout(vBox);
    setWindowTitle("Plate Dimensions");
    resize(280, 200);
}

PlateSizeDialog::~PlateSizeDialog()
{
    delete ui;
}

void PlateSizeDialog::applyBtn_clicked()
{
    pLengthStr=pLengthLnEdit->text();
    pHeightStr=pHeightLnEdit->text();
    float pLength=pLengthStr.toFloat();
    float pHeight=pHeightStr.toFloat();
    if (pLength < pHeight){
        QMessageBox::information(this, "Width of the plate can't be greater than its length.", "The values will be swapped");
        float *temp;temp=new float;
        *temp=pHeight;pHeight=pLength;pLength=*temp;delete temp;
    }
    else{
        plateLength=pLength;
        plateHeight=pHeight;
    }
}

void PlateSizeDialog::OKBtn_clicked()
{
    if(pLengthStr!= "" && pHeightStr == ""){
        QMessageBox::information(this, "Plate height is missing", "Please enter the plate height");
    }
    if(pHeightStr != "" && pLengthStr == ""){
        QMessageBox::information(this, "Plate length is missing", "Please enter the plate length");
    }
    if(pHeightStr == "" && pLengthStr == ""){
        QMessageBox::information(this, "Plate dimensions are missing", "Please enter the plate dimensions");
    }
    if(pHeightStr != "" && pLengthStr != "")
    PlateSizeDialog::close();   
}

QGroupBox *PlateSizeDialog::createPlateDimGroup()
{
    plateDimGroupBox = new QGroupBox(tr("Plate dimensions"));
    pLengthLbl =new QLabel(tr("Length:"));
    pHeightLbl = new QLabel(tr("Height:"));
    pLengthLnEdit= new QLineEdit;
    pHeightLnEdit = new QLineEdit;
    plateDimGrid=new QGridLayout;
    plateDimGrid->addWidget(pLengthLbl, 0, 0);
    plateDimGrid->addWidget(pLengthLnEdit, 0, 1);
    plateDimGrid->addWidget(pHeightLbl, 1, 0);
    plateDimGrid->addWidget(pHeightLnEdit, 1, 1);
    plateDimGroupBox->setLayout(plateDimGrid);
    return plateDimGroupBox;
}

QGroupBox *PlateSizeDialog::createApplyOkBoxGroup()
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
