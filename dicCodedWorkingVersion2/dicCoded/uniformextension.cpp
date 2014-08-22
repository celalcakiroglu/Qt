#include "uniformextension.h"
#include "ui_uniformextension.h"

uniformExtension::uniformExtension(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uniformExtension)
{
    ui->setupUi(this);
    setLabelsAndLineedits();
    setWindowTitle("Uniform Extension");
    resize(280, 200);
}

uniformExtension::~uniformExtension()
{
    delete ui;
}

void uniformExtension::UEOK_clicked()
{
    K1Str=K1LnEdt->text();K2Str=K2LnEdt->text();
    K1=K1Str.toFloat();K2=K2Str.toFloat();
    uniformExtension::close();
}

void uniformExtension::setLabelsAndLineedits()
{
   mainVBox=new QVBoxLayout;
   UEGroupBox=new QGroupBox(tr("Displacement field"));
   uniformExtGrid=new QGridLayout;
   x1 =new QLabel(tr("x1"));X1 =new QLabel(tr("X1"));
   x2 =new QLabel(tr("x2"));X2 =new QLabel(tr("X2"));
   x3 =new QLabel(tr("x3"));X3 =new QLabel(tr("X3"));
   equals1 = new QLabel(tr("="));
   equals2 = new QLabel(tr("="));
   equals3 = new QLabel(tr("="));
   Times1 = new QLabel(tr("*"));
   Times2 = new QLabel(tr("*"));
   Times3 = new QLabel(tr("*"));
   K1LnEdt = new QLineEdit;K1LnEdt->setFixedWidth(30);
   K2LnEdt = new QLineEdit;K2LnEdt->setFixedWidth(30);
   K3LnEdt = new QLineEdit;K3LnEdt->setFixedWidth(30);
   explanationUE = new QLabel;
   explanationUE->setWordWrap(true);
   explanationUE->setText("In case of uniform extension, only the diagonal elements of the deformation matrix are nonzero. "
   "Upper case X denots the initial "
   "configuration and the lower case x denotes the current configuration.");
   OKBtn = new QPushButton(tr("OK"));
   QObject::connect(OKBtn, SIGNAL(clicked()), this, SLOT(UEOK_clicked()));
   uniformExtGrid->addWidget(x1, 0, 0);
   uniformExtGrid->addWidget(equals1, 0, 1);
   uniformExtGrid->addWidget(x2, 1, 0);
   uniformExtGrid->addWidget(equals2, 1, 1);
   uniformExtGrid->addWidget(x3, 2, 0);
   uniformExtGrid->addWidget(equals3, 2, 1);

   uniformExtGrid->addWidget(K1LnEdt, 0, 3);
   uniformExtGrid->addWidget(Times1, 0, 4);
   uniformExtGrid->addWidget(X1, 0, 5);
   uniformExtGrid->addWidget(K2LnEdt, 1, 3);
   uniformExtGrid->addWidget(Times2, 1, 4);
   uniformExtGrid->addWidget(X2, 1, 5);
   uniformExtGrid->addWidget(K3LnEdt, 2, 3);
   uniformExtGrid->addWidget(Times3, 2, 4);
   uniformExtGrid->addWidget(X3, 2, 5);

   UEGroupBox->setLayout(uniformExtGrid);
   mainVBox->addWidget(explanationUE);
   mainVBox->addWidget(UEGroupBox);
   mainVBox->addWidget(OKBtn);
   this->setLayout(mainVBox);
}
