#include "Canvas.h"
#include <iostream>

// General Tool Declaration
Canvas::Canvas(QWidget *parent) : QLabel(parent) {}

void Canvas::redrawCanvas(QImage frame)
{
    setPixmap(QPixmap::fromImage(frame));
    std::cout << "Canvas redrawn" << std::endl;
}

void Canvas::mousePressEvent(QMouseEvent *event) {
  emit mouseEventSignal(event);
}
void Canvas::mouseReleaseEvent(QMouseEvent *event) {
  emit mouseEventSignal(event);
}
void Canvas::mouseMoveEvent(QMouseEvent *event) {
  emit mouseEventSignal(event);
}
