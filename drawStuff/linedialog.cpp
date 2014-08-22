#include "linedialog.h"
#include "ui_linedialog.h"

LineDialog::LineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LineDialog)
{
    ui->setupUi(this);
    xStartLbl = new QLabel(tr("Start X"));yStartLbl = new QLabel(tr("Start Y"));
    xEndLbl = new QLabel(tr("End X"));yEndLbl = new QLabel(tr("End Y"));
    xStart = new QLineEdit;yStart= new QLineEdit;
    xEnd = new QLineEdit; yEnd = new QLineEdit;
    OKBtn = new QPushButton(tr("Add"));CancelBtn=new QPushButton("Cancel");
    lineEntriesLayout = new QGridLayout;
    okCancelLayout = new QGridLayout;
    lineDiaVBox = new QVBoxLayout;
    lineWidthCombo = new QComboBox;
    lineWidthCombo->addItem(tr("Select linewidth"));
    lineWidthCombo->addItem(tr("0.25 mm"),d025mm);
    lineWidthCombo->addItem(tr("0.5 mm"), d05mm);
    lineWidthCombo->addItem(tr("0.75 mm"), d075mm);
    lineWidthCombo->addItem(tr("1 mm"), d1mm);
    lineWidthCombo->addItem(tr("1.5 mm"), d15mm);
    lineWidthCombo->addItem(tr("3 mm"), d3mm);
    lineColorCombo = new QComboBox;
    lineColorCombo->addItem(tr("Select Color"));
    lineColorCombo->addItem(tr("Skyblue"), skyblue);
    lineColorCombo->addItem(tr("Darkblue"), darkblue);
    lineColorCombo->addItem(tr("Red"), rot);
    lineColorCombo->addItem(tr("Green"), gruen);
    lineEntriesLayout->addWidget(lineWidthCombo,0,1);lineEntriesLayout->addWidget(lineColorCombo,0,3);
    lineEntriesLayout->addWidget(xStartLbl, 1,0);lineEntriesLayout->addWidget(xStart, 1,1);
    lineEntriesLayout->addWidget(yStartLbl, 1,2);lineEntriesLayout->addWidget(yStart, 1,3);
    lineEntriesLayout->addWidget(xEndLbl, 2,0);lineEntriesLayout->addWidget(xEnd, 2,1);
    lineEntriesLayout->addWidget(yEndLbl, 2,2);lineEntriesLayout->addWidget(yEnd, 2,3);
    okCancelLayout->addWidget(OKBtn, 0, 1);okCancelLayout->addWidget(CancelBtn, 0, 2);
    lineDiaVBox->addLayout(lineEntriesLayout);
    lineDiaVBox->addLayout(okCancelLayout);
    setLayout(lineDiaVBox);
    connect(OKBtn, SIGNAL(clicked()), this, SLOT(assignValues()));

}

LineDialog::~LineDialog()
{
    delete ui;
}

QPushButton *LineDialog::getOKBtn()
{
    return OKBtn;
}

QPushButton *LineDialog::getCancelBtn()
{
    return CancelBtn;
}

QComboBox *LineDialog::getLineColorCombo()
{
    return lineColorCombo;
}

QComboBox *LineDialog::getLineWidthCombo()
{
    return lineWidthCombo;
}

void LineDialog::assignValues()
{
    QString xStartStr=xStart->text();
    QString yStartStr=yStart->text();
    QString xEndStr=xEnd->text();
    QString yEndStr=yEnd->text();
    xStartF =xStartStr.toFloat();
    yStartF=yStartStr.toFloat();
    xEndF =xEndStr.toFloat();
    yEndF=yEndStr.toFloat();
}

void LineDialog::cancelBtn_clicked()
{
    LineDialog::close();
}
