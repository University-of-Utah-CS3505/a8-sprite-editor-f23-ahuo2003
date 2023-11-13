#ifndef EYEDROPPER_H
#define EYEDROPPER_H
#include "SpriteTool.h"

class Eyedropper : public SpriteTool {
public:
  Eyedropper();

protected:
  virtual void mousePressed();
  virtual void mouseReleased();
  virtual void mouseMoved();
};

#endif // EYEDROPPER_H
