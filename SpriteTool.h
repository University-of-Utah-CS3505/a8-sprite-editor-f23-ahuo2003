#ifndef SPRITETOOL_H
#define SPRITETOOL_H
#include <QImage>
#include <QColor>
#include <QMouseEvent>

class SpriteTool {
public:
  SpriteTool();

protected:
  virtual void mousePressed(QImage& image, QColor& currColor, QMouseEvent *event);
  virtual void mouseReleased();
  virtual void mouseMoved();

  friend class SpriteModel;
};

#endif // SPRITETOOL_H
