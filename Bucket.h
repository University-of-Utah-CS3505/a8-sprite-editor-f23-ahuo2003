#ifndef BUCKET_H
#define BUCKET_H
#include "SpriteTool.h"

class Bucket : public SpriteTool{
public:
    Bucket();
    virtual void onMousePress(QMouseEvent *event);
    virtual void onMouseRelease(QMouseEvent *event);
    virtual void onMouseMove(QMouseEvent *event);
    virtual void floodFill(QImage& image, const QPoint& pos, const QColor& startColor, const QColor& newColor);
};

#endif // BUCKET_H
