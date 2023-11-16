/*This was checked by Nam Nguyen*/
#include "SpriteTool.h"

// General Tool Declaration
SpriteTool::SpriteTool() {}

void SpriteTool::mousePressed(QImage &image, QColor &currColor,
                              QMouseEvent *event, int scaleFactor) {}
void SpriteTool::mouseReleased() {}
void SpriteTool::mouseMoved(QImage &image, QColor &currColor,
                            QMouseEvent *event, int scaleFactor) {}

QPoint SpriteTool::mapToImageCoordinates(const QPoint &point, int scaleFactor) {
  return QPoint(point.x() / scaleFactor, point.y() / scaleFactor);
}

QString SpriteTool::getName() const { return name; }
