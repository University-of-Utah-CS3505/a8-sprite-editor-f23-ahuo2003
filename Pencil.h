#ifndef PENCIL_H
#define PENCIL_H
#include "SpriteTool.h"
#include <QImage>
#include <QColor>
#include <QMouseEvent>

class Pencil : public SpriteTool {
public:
  Pencil();
  void drawPixel(QImage& image, QColor& currColor, QMouseEvent *event);

protected:
  virtual void mousePressed(QImage& image, QColor& currColor, QMouseEvent *event);
  virtual void mouseReleased();
  virtual void mouseMoved(QImage& image, QColor& currColor, QMouseEvent *event);
};

#endif // PENCIL_H
