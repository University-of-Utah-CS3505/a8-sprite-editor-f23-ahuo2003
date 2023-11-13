#ifndef FILTER_H
#define FILTER_H
#include "SpriteTool.h"

class Filter : public SpriteTool {
public:
  Filter();

protected:
  virtual void mousePressed();
  virtual void mouseReleased();
  virtual void mouseMoved();
};

#endif // FILTER_H
