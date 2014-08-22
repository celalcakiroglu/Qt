#ifndef LINEDIALOG_H
#define LINEDIALOG_H

#include "shape2d.h"

namespace Ui {
class LineDialog;
}

class LineDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LineDialog(QWidget *parent = 0);
    ~LineDialog();
    qreal xStartF, yStartF, xEndF, yEndF;
    QPushButton* getOKBtn();
    QPushButton* getCancelBtn();
    QComboBox* getLineColorCombo();
    QComboBox* getLineWidthCombo();

public slots:
    void assignValues();
    void cancelBtn_clicked();
    
private:
    Ui::LineDialog *ui;
    QLineEdit *xStart, *yStart, *xEnd, *yEnd;
    QLabel *xStartLbl, *yStartLbl, *xEndLbl, *yEndLbl;
    QComboBox *lineWidthCombo, *lineColorCombo;
    QGridLayout *lineEntriesLayout;QGridLayout *okCancelLayout;
    QVBoxLayout *lineDiaVBox;
    QPushButton *CancelBtn;
    QPushButton *OKBtn;
};

#endif // LINEDIALOG_H
