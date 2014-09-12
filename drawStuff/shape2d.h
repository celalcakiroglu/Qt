#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <iostream>
#include <QDebug>
#include <QPointF>
#include <QLineF>
#include <QRectF>
#include <QDialog>
#include <QWidget>
#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QKeySequence>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QPalette>
#include <QComboBox>
#include <QLabel>
#include <QMenu>
#include <QList>
#include <QStack>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>

enum Shape { Line, Points, PolyLine, CSys2D, Polygon, Rect, RoundedRect, Ellipse, Arc,
                  Chord, Pie, Path, Text, Pixmap, None };

enum Farbe {weiss, gruen, darkblue, gelb, skyblue, rot, schwarz};

enum Dicke {d025mm, d05mm, d075mm, d1mm, d15mm, d3mm};


class Shape2D
{
public:
    Shape2D();
    QLineF* getLine();
    Shape* getShape();
    QColor *getFarbe();
    qreal *getDicke();
    bool* isPartOfCSys();
    void setShape(Shape shape);
    void setFarbe(QColor farbe);
    void setDicke(qreal dicke);
    bool partOfCSys;

private:
    Shape shape;
    QColor farbe;
    qreal dicke; // in pixels
    QLineF ln;
};

#endif // SHAPE2D_H
