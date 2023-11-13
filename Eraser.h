#ifndef ERASER_H
#define ERASER_H
#include "SpriteTool.h"

class Eraser : public SpriteTool {
public:
  Eraser();

protected:
  virtual void mousePressed();
  virtual void mouseReleased();
  virtual void mouseMoved();
};

#endif // ERASER_H
