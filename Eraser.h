#ifndef ERASER_H
#define ERASER_H
#include "SpriteTool.h"

class Eraser : public SpriteTool{
public:
    Eraser();
    virtual void onMousePress(QMouseEvent *event);
    virtual void onMouseRelease(QMouseEvent *event);
    virtual void onMouseMove(QMouseEvent *event);
};


#endif // ERASER_H
