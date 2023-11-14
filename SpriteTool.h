#ifndef SPRITETOOL_H
#define SPRITETOOL_H
#include <QImage>
#include <QColor>
#include <QMouseEvent>
#include <QString>

class SpriteTool {
public:
  SpriteTool();
  QString getName() const;

protected:
  virtual void mousePressed(QImage &image, QColor &currColor,
                            QMouseEvent *event, int scaleFactor);
  virtual void mouseReleased();
  virtual void mouseMoved(QImage &image, QColor &currColor, QMouseEvent *event, int scaleFactor);
  QPoint mapToImageCoordinates(const QPoint &point, int scaleFactor);
  QString name;

  friend class SpriteModel;
};

#endif // SPRITETOOL_H
