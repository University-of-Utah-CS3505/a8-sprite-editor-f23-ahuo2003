#ifndef PENCIL_H
#define PENCIL_H
#include "SpriteTool.h"
#include <QImage>
#include <QColor>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>

class Pencil : public SpriteTool {
public:
  Pencil();

protected:
  virtual void mousePressed(QImage& image, QColor& currColor, QMouseEvent *event, int scaleFactor);
  virtual void mouseReleased();
  virtual void mouseMoved(QImage& image, QColor& currColor, QMouseEvent *event, int scaleFactor);

private:
  QPainter painter;
  QPoint startPoint, endPoint;
};

#endif // PENCIL_H
