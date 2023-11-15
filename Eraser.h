#ifndef ERASER_H
#define ERASER_H
#include "SpriteTool.h"

class Eraser : public SpriteTool {
public:
    Eraser();

protected:
    virtual void mousePressed(QImage &image, QColor &currColor, QMouseEvent *event, int scaleFactor);
    virtual void mouseReleased();
    virtual void mouseMoved(QImage &image, QColor &currColor, QMouseEvent *event, int scaleFactor);

private:
    QPoint startPoint, endPoint;
};

#endif // ERASER_H
