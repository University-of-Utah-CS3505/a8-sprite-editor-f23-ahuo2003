#ifndef SPRITETOOL_H
#define SPRITETOOL_H
#include <QImage>
#include <QColor>
#include <QMouseEvent>

class SpriteTool {
public:
  SpriteTool();

protected:
  virtual void mousePressed(QImage &image, QColor &currColor,
                            QMouseEvent *event);
  virtual void mouseReleased();
  virtual void mouseMoved(QImage &image, QColor &currColor, QMouseEvent *event);
  QPoint mapToImageCoordinates(const QPoint &point);

  friend class SpriteModel;

private:
  int scaleFactor;
};

#endif // SPRITETOOL_H
