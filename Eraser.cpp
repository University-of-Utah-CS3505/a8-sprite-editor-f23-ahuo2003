#include "Eraser.h"

Eraser::Eraser() : SpriteTool() { name = "Eraser"; }

void Eraser::mousePressed(QImage &image, QColor &currColor, QMouseEvent *event,
                          int scaleFactor) {
  // Transform canvas coordinates into grid, and set pixel to transparent.
  QPoint point = this->mapToImageCoordinates(event->pos(), scaleFactor);
  image.setPixelColor(point, Qt::transparent);
}
void Eraser::mouseReleased() {
  // Do nothing
}

void Eraser::mouseMoved(QImage &image, QColor &currColor, QMouseEvent *event,
                        int scaleFactor) {
  // Get and endPoint for the startPoint recorded in mousePressed, and transform
  // it into grid coordinates.
  endPoint = this->mapToImageCoordinates(event->pos(), scaleFactor);

  // Delete each pixel as mouse move
  image.setPixelColor(endPoint, Qt::transparent);

  // Get a new starting point for next line connection.
  startPoint = this->mapToImageCoordinates(event->pos(), scaleFactor);
  image.setPixelColor(startPoint, Qt::transparent);
}
