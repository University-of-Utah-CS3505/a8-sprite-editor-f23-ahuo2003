#ifndef BUCKET_H
#define BUCKET_H
#include "SpriteTool.h"
#include <QImage>
#include <QColor>
#include <QMouseEvent>

class Bucket : public SpriteTool {
public:
  Bucket();
  virtual void floodFill(QImage &image, const QPoint &pos,
                         const QColor &startColor, const QColor &newColor);

protected:
  virtual void mousePressed(QImage& image, QColor& currColor, QMouseEvent *event);
  virtual void mouseReleased();
  virtual void mouseMoved(QImage& image, QColor& currColor, QMouseEvent *event);
};

#endif // BUCKET_H
