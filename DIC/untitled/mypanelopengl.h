#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QtOpenGL/QGLWidget>
#include <QDebug>
#include <cmath>

class MyPanelOpenGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyPanelOpenGL(QWidget *parent = 0);
protected:
    void paintEvent(/*QPaintEvent *e*/);
};

#endif // MYPANELOPENGL_H
