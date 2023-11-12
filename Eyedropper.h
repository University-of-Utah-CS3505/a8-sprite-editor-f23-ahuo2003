#ifndef EYEDROPPER_H
#define EYEDROPPER_H
#include "SpriteTool.h"

class Eyedropper : public SpriteTool{
public:
    Eyedropper();
    virtual void onMousePress(QMouseEvent *event);
    virtual void onMouseRelease(QMouseEvent *event);
    virtual void onMouseMove(QMouseEvent *event);
};

#endif // EYEDROPPER_H
