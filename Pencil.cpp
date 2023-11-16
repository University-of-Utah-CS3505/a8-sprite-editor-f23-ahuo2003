#include "Pencil.h"

Pencil::Pencil() : SpriteTool() { name = "Pencil"; }

void Pencil::mousePressed(QImage &image, QColor &currColor, QMouseEvent *event,
                          int scaleFactor) {
  // Start the Painter
  painter.begin(&image);

  // Set format of the Pen
  QPen cursorPen = painter.pen();
  cursorPen.setColor(currColor);
  painter.setPen(cursorPen);

  // Transform canvas coordinates into grid, and draw.
  QPoint point = this->mapToImageCoordinates(event->pos(), scaleFactor);
  painter.drawPoint(point);
  startPoint = point;
}

void Pencil::mouseReleased() { painter.end(); }
void Pencil::mouseMoved(QImage &image, QColor &currColor, QMouseEvent *event,
                        int scaleFactor) {
  // Get and endPoint for the startPoint recorded in mousePressed, and transform
  // it into grid coordinates.
  endPoint = this->mapToImageCoordinates(event->pos(), scaleFactor);
  ;

  // Draw a Line.
  painter.drawLine(startPoint, endPoint);

  // Get a new starting point for next line connection.
  startPoint = this->mapToImageCoordinates(event->pos(), scaleFactor);
}
