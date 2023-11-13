#include "Canvas.h"
#include <iostream>

// General Tool Declaration
Canvas::Canvas(QWidget *parent) : QLabel(parent) {}

void Canvas::mousePressEvent(QMouseEvent *event) {
  emit mouseEventSignal(event);
  std::cout << "MousePressed" << std::endl;
}
void Canvas::mouseReleaseEvent(QMouseEvent *event) {
  emit mouseEventSignal(event);
  std::cout << "mouseReleased" << std::endl;
}
void Canvas::mouseMoveEvent(QMouseEvent *event) {
  emit mouseEventSignal(event);
  std::cout << "MouseMoved" << std::endl;
}
