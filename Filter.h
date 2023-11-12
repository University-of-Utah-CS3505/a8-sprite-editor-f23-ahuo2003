#ifndef FILTER_H
#define FILTER_H
#include "SpriteTool.h"

class Filter : public SpriteTool{
public:
    Filter();
    virtual void onMousePress(QMouseEvent *event);
    virtual void onMouseRelease(QMouseEvent *event);
    virtual void onMouseMove(QMouseEvent *event);
};

#endif // FILTER_H
