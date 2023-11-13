#ifndef PENCIL_H
#define PENCIL_H
#include "SpriteTool.h"

class Pencil : public SpriteTool {
public:
  Pencil();

protected:
  virtual void mousePressed();
  virtual void mouseReleased();
  virtual void mouseMoved();
};

#endif // PENCIL_H
