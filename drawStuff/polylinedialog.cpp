#include "polylinedialog.h"
#include "ui_polylinedialog.h"

PolyLineDialog::PolyLineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PolyLineDialog)
{
    ui->setupUi(this);
    //Adding the toolbar and assigning the actions
    polyLineMainWin = new QMainWindow;
    polyLineToolbar = new QToolBar;
    polyLineMainWin->addToolBar(polyLineToolbar);
    QPixmap undoPix("undo2.png");
    undoAct = polyLineToolbar->addAction(undoPix,tr("&Undo  CTRL+u"));
    undoAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_U));
    polyLineToolbar->addSeparator();
    //--------------------------------------------------------
    //lineColorLbl = new QLabel(tr("Color"));lineWidthLlb = new QLabel(tr("Width"));
    xStartLbl = new QLabel(tr("Start X"));yStartLbl = new QLabel(tr("Start Y"));
    xNextLbl = new QLabel(tr("Next X"));yNextLbl = new QLabel(tr("Next Y"));
    Explanation = new QLabel("For each line sequence enter the starting point only once in the first line,"
                             " then add the subsequent points in the second line."
                             "Click Add after each line and click Done after the last line.");
    Explanation->setWordWrap(true);
    xStart = new QLineEdit;yStart= new QLineEdit;
    xNext = new QLineEdit; yNext = new QLineEdit;
    OKBtn = new QPushButton(tr("Add"));CancelBtn=new QPushButton("Cancel");DoneBtn=new QPushButton("Done");
    polyLineEntriesLayout = new QGridLayout;
    okCancelLayout = new QGridLayout;
    polyLineDiaVBox = new QVBoxLayout;
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
    polyLineEntriesLayout->addWidget(lineWidthCombo,0,1);
    polyLineEntriesLayout->addWidget(lineColorCombo, 0,3);
    polyLineEntriesLayout->addWidget(xStartLbl, 1,0);polyLineEntriesLayout->addWidget(xStart, 1,1);
    polyLineEntriesLayout->addWidget(yStartLbl, 1,2);polyLineEntriesLayout->addWidget(yStart, 1,3);
    polyLineEntriesLayout->addWidget(xNextLbl, 2,0);polyLineEntriesLayout->addWidget(xNext, 2,1);
    polyLineEntriesLayout->addWidget(yNextLbl, 2,2);polyLineEntriesLayout->addWidget(yNext, 2,3);
    okCancelLayout->addWidget(OKBtn, 0, 1);okCancelLayout->addWidget(DoneBtn, 0, 2);okCancelLayout->addWidget(CancelBtn, 0, 3);
    polyLineDiaVBox->addWidget(polyLineMainWin);
    polyLineDiaVBox->addWidget(Explanation);
    polyLineDiaVBox->addLayout(polyLineEntriesLayout);
    polyLineDiaVBox->addLayout(okCancelLayout);
    setLayout(polyLineDiaVBox);
   // connect(OKBtn, SIGNAL(clicked()), this, SLOT(OKBtn_clicked()));
}

PolyLineDialog::~PolyLineDialog()
{
    delete ui;
}

QPushButton *PolyLineDialog::getAddBtn()
{
    return OKBtn;
}

QPushButton *PolyLineDialog::getCancelBtn()
{
    return CancelBtn;
}

QPushButton *PolyLineDialog::getDoneBtn()
{
    return DoneBtn;
}

QComboBox *PolyLineDialog::getLineColorCombo()
{
    return lineColorCombo;
}

QComboBox *PolyLineDialog::getLineWidthCombo()
{
    return lineWidthCombo;
}

QAction *PolyLineDialog::getUndoAct()
{
    return undoAct;
}

void PolyLineDialog::assignValues()
{
    QString xStartStr=xStart->text();
    QString yStartStr=yStart->text();
    QString xNextStr=xNext->text();
    QString yNextStr=yNext->text();
    xStartF =xStartStr.toFloat();
    yStartF=yStartStr.toFloat();
    xNextF =xNextStr.toFloat();
    yNextF=yNextStr.toFloat();
}


