#ifndef CANVAS_H
#define CANVAS_H

#include "ellipticfixedsizedialog.h"
#include "platesizedialog.h"
#include "rigidbodytranslation.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);
    bool drawPlate, drawSpeckles, thereisPlate, specksElliptic;
    bool openImage(const QString &fileName);//loads an image from a file into the scribble area, allowing the user to edit the image
    bool saveImage(const QString &fileName, const char *fileFormat);//writes the currently displayed image to file
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);
    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }
    qreal majorRadius, minorRadius, pHeight, pLength;
    qreal plateOriginX, plateOriginY, screenHeight, screenLength;
    float speckDiam, radH, radV, rigidBodyDX1, rigidBodyDX2;
    int speckCount;
    SHAPE speckShape;
public slots:
    void drawPlateBtn_clicked();
    void speckPlateBtn_clicked();
    void cleanPlateBtn_clicked();
    void cleanScreenBtn_clicked();
    void clearImage();//clears the image displayed in the scribble area
    void drawRBT_clicked();
  //  void print();//handles printing
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);//to update the scribble area
    void resizeEvent(QResizeEvent *event);//to ensure that the QImage on which we draw is at least as large as the widget at any time
private:
    QString speckCountLnEdtStr;
    EllipticFixedSizeDialog *dia;
    // xList and yLits are storing the upper left corners of the rectangles bounding the speckles
    QList<double> randomsW, randomsL, xList, yList, heightList, lengthList;
    QBrush redBrush, blueBrush, whiteBrush;
    QPen blackPen, whitePen;
    void setBgWhite();
    void setPensAndBrushes();
    //-----------------------------------------------------------------
    //  From Scribble
    //-----------------------------------------------------------------
    void drawLineTo(const QPoint &endPoint);//actually does the drawing
    void drawThePlate();
    void speckleThePlate();
    void drawRigidBodyTranslation();
    void resizeImage(QImage *image, const QSize &newSize);//changes the size of a QImage
    bool modified;//is true if there are unsaved changes to the image displayed in the scribble area.
    bool scribbling;//is true while the user is pressing the left mouse button within the scribble area.
    int myPenWidth;//holds the currently set width for the pen used in the application
    QColor myPenColor;//holds the currently set color for the pen used in the application
    QImage image; //stores the image drawn by the user
    QPoint lastPoint;//holds the position of the cursor at the last mouse press or
    //mouse move event.
};

#endif // CANVAS_H
