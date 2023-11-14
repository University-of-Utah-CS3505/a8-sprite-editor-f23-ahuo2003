#ifndef BUCKET_H
#define BUCKET_H
#include "SpriteTool.h"
#include <QImage>
#include <QColor>
#include <QMouseEvent>
#include <QPainter>

class Bucket : public SpriteTool {
public:
  Bucket();
  virtual void floodFill(QImage &image, const QPoint &pos,
                         const QColor &startColor, const QColor &newColor, QList<QPoint>& visitedPixels);

protected:
  virtual void mousePressed(QImage& image, QColor& currColor, QMouseEvent *event, int scaleFactor);
  virtual void mouseReleased();
  virtual void mouseMoved(QImage& image, QColor& currColor, QMouseEvent *event, int scaleFactor);
};

#endif // BUCKET_H
