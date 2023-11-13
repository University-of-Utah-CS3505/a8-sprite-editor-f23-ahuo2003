#ifndef EYEDROPPER_H
#define EYEDROPPER_H
#include "SpriteTool.h"

class Eyedropper : public SpriteTool {
public:
  Eyedropper();
  QColor getPixelColor(QImage& image, QMouseEvent *event);
protected:
  virtual void mousePressed(QImage& image, QColor& currColor, QMouseEvent *event);
  virtual void mouseReleased();
  virtual void mouseMoved(QImage& image, QColor& currColor, QMouseEvent *event);
};

#endif // EYEDROPPER_H
