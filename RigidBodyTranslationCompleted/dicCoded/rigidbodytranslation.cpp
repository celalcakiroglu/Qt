#include "rigidbodytranslation.h"
#include "ui_rigidbodytranslation.h"

rigidBodyTranslation::rigidBodyTranslation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rigidBodyTranslation)
{
    ui->setupUi(this);
    setLabelsAndLineedits();
    setWindowTitle(
    "Rigid Body translation");
    resize(280, 200);
}

rigidBodyTranslation::~rigidBodyTranslation()
{
    delete ui;
}

void rigidBodyTranslation::RBTOK_clicked()
{
    dX1Str=dX1->text();dX2Str=dX2->text();
    deltaX1=dX1Str.toFloat();deltaX2=dX2Str.toFloat();
    rigidBodyTranslation::close();
}

void rigidBodyTranslation::setLabelsAndLineedits()
{
    mainVBox = new QVBoxLayout;
    RBTGroupBox = new QGroupBox(tr("Displacement field"));
    rigidBodyTransGrid=new QGridLayout;
    x1 =new QLabel(tr("x1"));X1 =new QLabel(tr("X1"));
    x2 =new QLabel(tr("x2"));X2 =new QLabel(tr("X2"));
    x3 =new QLabel(tr("x3"));X3 =new QLabel(tr("X3"));
    equals1 =new QLabel(tr("="));
    equals2 =new QLabel(tr("="));
    equals3 =new QLabel(tr("="));
    Plus1 = new QLabel(tr("+"));
    Plus2 = new QLabel(tr("+"));
    Plus3 = new QLabel(tr("+"));
    dX1 = new QLineEdit;dX1->setFixedWidth(30);
    dX2 = new QLineEdit;dX2->setFixedWidth(30);
    dX3 = new QLineEdit;dX3->setFixedWidth(30);
    explanationRBT = new QLabel;
    explanationRBT->setWordWrap(true);
    explanationRBT->setText("Upper case X denots the initial "
    "configuration and the lower case x denotes the current configuration.");
    OKBtn = new QPushButton(tr("OK"));
    QObject::connect(OKBtn, SIGNAL(clicked()), this, SLOT(RBTOK_clicked()));
    rigidBodyTransGrid->addWidget(x1, 0, 0);
    rigidBodyTransGrid->addWidget(equals1, 0, 1);
    rigidBodyTransGrid->addWidget(x2, 1, 0);
    rigidBodyTransGrid->addWidget(equals2, 1, 1);
    rigidBodyTransGrid->addWidget(x3, 2, 0);
    rigidBodyTransGrid->addWidget(equals3, 2, 1);

    rigidBodyTransGrid->addWidget(X1, 0, 2);
    rigidBodyTransGrid->addWidget(Plus1, 0, 3);
    rigidBodyTransGrid->addWidget(X2, 1, 2);
    rigidBodyTransGrid->addWidget(Plus2, 1, 3);
    rigidBodyTransGrid->addWidget(X3, 2, 2);
    rigidBodyTransGrid->addWidget(Plus3, 2, 3);

    rigidBodyTransGrid->addWidget(dX1, 0, 4);
    rigidBodyTransGrid->addWidget(dX2, 1, 4);
    rigidBodyTransGrid->addWidget(dX3, 2, 4);

    RBTGroupBox->setLayout(rigidBodyTransGrid);
    mainVBox->addWidget(explanationRBT);
    mainVBox->addWidget(RBTGroupBox);
    mainVBox->addWidget(OKBtn);
    this->setLayout(mainVBox);
}
