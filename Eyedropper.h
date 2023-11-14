#ifndef EYEDROPPER_H
#define EYEDROPPER_H
#include "SpriteTool.h"

class Eyedropper : public SpriteTool {
public:
  Eyedropper();
  QColor getPixelColor(QImage& image, QPoint pixelCoords);
protected:
  virtual void mousePressed(QImage& image, QColor& currColor, QMouseEvent *event, int scaleFactor);
  virtual void mouseReleased();
  virtual void mouseMoved(QImage& image, QColor& currColor, QMouseEvent *event, int scaleFactor);
};

#endif // EYEDROPPER_H
