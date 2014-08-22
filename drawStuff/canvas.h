#ifndef CANVAS_H
#define CANVAS_H

#include "linedialog.h"
#include "polylinedialog.h"
#include "csys2ddialog.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);
    QList<Shape2D> shapeList;
    QStack<Shape2D> redoShapeList;
    Shape getShape();
    LineDialog *getLineDia();
    PolyLineDialog *getPolyLineDia();
    Csys2Ddialog *getCsys2DDia();

signals:
    
public slots:
    void setBgColor(Farbe farbe);
    void setShape(Shape shape);
    void drawShape();
    void clearLastLine();
    void clearLastPolyLine();
    void clearCSys();
    void polyLineDone();
    void undoLastPart();
    void redoLastPart();
    void assignLineColor();//what purpose does that function serve ?
    void assignLineWidth();//what purpose does that function serve ?
protected:
    void paintEvent(QPaintEvent *event);
private:
    void setBgWhite();
    QPalette canvasPalette;
    Shape shape;
    LineDialog *lineDia;
    PolyLineDialog *polyLineDia;
    Csys2Ddialog *csys2DDia;
    int polyLineSize;
    QColor lineColor;//do we need this?
    qreal lineWidth;//do we need this?
    qreal cnvsWidth, cnvsHeight;
    int numXTicks, numYTicks;
    qreal CSysOriginX, CSysOriginY;
    qreal mappedXInterval, mappedYInterval;
};

#endif // CANVAS_H
