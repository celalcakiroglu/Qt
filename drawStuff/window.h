#ifndef WINDOW_H
#define WINDOW_H

#include "canvas.h"

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    Canvas* getCanvas();
public slots:
    void BgColorChanged();
    void shapeChanged();
    void openDimsWindow();//This function should pop up the window where we enter the shape dimensions
private:
    Ui::Window *ui;
    Canvas *canvas;
    QGridLayout *editGrid;
    QGridLayout *coordInpGrid;
    QGridLayout *mouseInpGrid;
    QGridLayout *mainLayout;
    QGridLayout *rightLayout;
    QPushButton *shapeAddBtnC;//C for coordinate input
    QPushButton *shapeAddBtnM;//M for mouse input
    QLabel *canvasBgLabel;
    QLabel *canvasShapeLabelC;
    QLabel *canvasShapeLabelM;
    QComboBox *canvasBgCombo;
    QComboBox *canvasShapeComboC;
    QComboBox *canvasShapeComboM;
    QGroupBox *editGroupBox;
    QGroupBox *coordInpGroupBox;
    QGroupBox *mouseInpGroupBox;
    QGroupBox *rightSideGroupBox;
    QGridLayout *createRightSide();
    QGroupBox *editGroup();
    QGroupBox *coordInpGroup();
    QGroupBox *mouseInpGroup();
};

#endif // WINDOW_H
