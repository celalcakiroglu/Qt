#include "csys2ddialog.h"
#include "ui_csys2ddialog.h"

Csys2Ddialog::Csys2Ddialog(QWidget *parent) :
    QDialog(parent)
    //ui(new Ui::Csys2Ddialog)
{
    //ui->setupUi(this);
    percOfWidthLbl = new QLabel("% of canvas width");
    percOfHeightLbl = new QLabel("% of canvas height");
    xLimLbl = new QLabel("Max X");
    yLimLbl = new QLabel("Max Y");
    xStepLbl = new QLabel("X Interval");
    yStepLbl = new QLabel("Y Interval");
    originXLbl =new QLabel("Origin X");
    originYLbl = new QLabel("Origin Y");
    originXEdt = new QLineEdit;
    originYEdt = new QLineEdit;
    xLimEdt = new QLineEdit;
    yLimEdt = new QLineEdit;
    xStepEdt = new QLineEdit;
    yStepEdt = new QLineEdit;
    ApplyBtn = new QPushButton("Apply");
    CancelBtn = new QPushButton("Cancel");
    csys2DEntriesLayout = new QGridLayout;
    applyCancelLayout = new QGridLayout;
    csys2DDiaVBox = new QVBoxLayout;
    csys2DEntriesLayout->addWidget(originXLbl, 0,0);
    csys2DEntriesLayout->addWidget(originXEdt, 0,1);
    csys2DEntriesLayout->addWidget(percOfWidthLbl, 0,2);
    csys2DEntriesLayout->addWidget(originYLbl, 1,0);
    csys2DEntriesLayout->addWidget(originYEdt, 1,1);
    csys2DEntriesLayout->addWidget(percOfHeightLbl, 1,2);
    csys2DEntriesLayout->addWidget(xLimLbl, 2,0);
    csys2DEntriesLayout->addWidget(xLimEdt, 2,1);
    csys2DEntriesLayout->addWidget(yLimLbl, 3,0);
    csys2DEntriesLayout->addWidget(yLimEdt, 3,1);
    csys2DEntriesLayout->addWidget(xStepLbl, 4,0);
    csys2DEntriesLayout->addWidget(xStepEdt, 4,1);
    csys2DEntriesLayout->addWidget(yStepLbl, 5,0);
    csys2DEntriesLayout->addWidget(yStepEdt, 5,1);
    applyCancelLayout->addWidget(ApplyBtn, 0, 1);
    applyCancelLayout->addWidget(CancelBtn, 0, 3);
    csys2DDiaVBox->addLayout(csys2DEntriesLayout);
    csys2DDiaVBox->addLayout(applyCancelLayout);
    setLayout(csys2DDiaVBox);
}

Csys2Ddialog::~Csys2Ddialog()
{
    delete ui;
}


QPushButton *Csys2Ddialog::getApplyBtn()
{
    return ApplyBtn;
}

QPushButton *Csys2Ddialog::getCancelBtn()
{
    return CancelBtn;
}

void Csys2Ddialog::assignValues()
{
    QString originXStr=originXEdt->text();
    QString originYStr=originYEdt->text();
    QString xLimStr = xLimEdt->text();
    QString yLimStr = yLimEdt->text();
    QString xStepStr = xStepEdt->text();
    QString yStepStr = yStepEdt->text();
    originXF = originXStr.toFloat();
    originYF = originYStr.toFloat();
    xLimF = xLimStr.toFloat();
    yLimF = yLimStr.toFloat();
    xStepF = xStepStr.toFloat();
    yStepF = yStepStr.toFloat();
}
