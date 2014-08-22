#ifndef SPECKLES_H
#define SPECKLES_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsObject>
#include <QGraphicsScene>

namespace Ui {
class speckles;
}

class speckles : public QDialog
{
    Q_OBJECT
    
public:
    explicit speckles(QWidget *parent = 0);
    ~speckles();
    
private:
    Ui::speckles *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
};

#endif // SPECKLES_H
