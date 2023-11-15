#ifndef CURSOR_H
#define CURSOR_H

#include "SpriteTool.h"

class Cursor : public SpriteTool {
public:
    Cursor();

protected:
    virtual void mousePressed();
    virtual void mouseReleased();
    virtual void mouseMoved();
};

#endif // CURSOR_H
