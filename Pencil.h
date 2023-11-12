#ifndef PENCIL_H
#define PENCIL_H
#include "SpriteTool.h"

class Pencil : public SpriteTool {
public:
    Pencil();
    virtual void onMousePress(QMouseEvent *event);
    virtual void onMouseRelease(QMouseEvent *event);
    virtual void onMouseMove(QMouseEvent *event);
};

#endif // PENCIL_H
