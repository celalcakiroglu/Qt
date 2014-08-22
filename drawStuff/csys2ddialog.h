#ifndef CSYS2DDIALOG_H
#define CSYS2DDIALOG_H

#include "shape2d.h"

namespace Ui {
class Csys2Ddialog;
}

class Csys2Ddialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Csys2Ddialog(QWidget *parent = 0);
    ~Csys2Ddialog();
    QPushButton* getApplyBtn();QPushButton* getCancelBtn();
    qreal originXF, originYF, xLimF, yLimF, xStepF, yStepF;

public slots:
    void assignValues();
    
private:
    Ui::Csys2Ddialog *ui;
    QLineEdit *originXEdt, *originYEdt,*xLimEdt, *yLimEdt, *xStepEdt, *yStepEdt;
    QLabel *originXLbl, *originYLbl,*percOfWidthLbl, *percOfHeightLbl,*xLimLbl, *yLimLbl, *xStepLbl, *yStepLbl;
    QPushButton *CancelBtn, *ApplyBtn;
    QGridLayout *csys2DEntriesLayout;
    QGridLayout *applyCancelLayout;
    QVBoxLayout *csys2DDiaVBox;
};

#endif // CSYS2DDIALOG_H
