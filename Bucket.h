#ifndef BUCKET_H
#define BUCKET_H
#include "SpriteTool.h"

class Bucket : public SpriteTool{
public:
    Bucket();
    virtual void mousePressed();
    virtual void mouseReleased();
    virtual void mouseMoved();
};

#endif // BUCKET_H
