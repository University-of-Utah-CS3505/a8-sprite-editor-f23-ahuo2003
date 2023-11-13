#include "Canvas.h"
#include <iostream>

// General Tool Declaration
Canvas::Canvas(QLabel *parent) : QLabel(parent){}

void Canvas::mousePressEvent(QMouseEvent *event){
    std::cout << "MousePressed" << std::endl;
}
void Canvas::mouseReleaseEvent(QMouseEvent *event){
    std::cout << "mouseReleased" << std::endl;
}
void Canvas::mouseMoveEvent(QMouseEvent *event){
    std::cout << "MouseMoved" << std::endl;
}
