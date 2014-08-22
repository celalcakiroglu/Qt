#ifndef POLYLINEDIALOG_H
#define POLYLINEDIALOG_H

#include "shape2d.h"

namespace Ui {
class PolyLineDialog;
}

class PolyLineDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PolyLineDialog(QWidget *parent = 0);
    ~PolyLineDialog();
    qreal xStartF, yStartF, xNextF, yNextF;
    QPushButton* getAddBtn();
    QPushButton* getCancelBtn();
    QPushButton* getDoneBtn();
    QComboBox* getLineColorCombo();
    QComboBox* getLineWidthCombo();
    QAction *getUndoAct();

public slots:
    void assignValues();
    
private:
    Ui::PolyLineDialog *ui;
    QLineEdit *xStart, *yStart, *xNext, *yNext;
    QLabel *xStartLbl, *yStartLbl, *xNextLbl, *yNextLbl, *Explanation;
    QComboBox *lineWidthCombo, *lineColorCombo;
    QGridLayout *polyLineEntriesLayout;QGridLayout *okCancelLayout;
    QVBoxLayout *polyLineDiaVBox;
    QPushButton *CancelBtn, *OKBtn, *DoneBtn, *BackBtn;
    QMainWindow *polyLineMainWin;
    QToolBar *polyLineToolbar;
    QAction *undoAct;
};

#endif // POLYLINEDIALOG_H
