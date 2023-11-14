#include "SpriteTool.h"

// General Tool Declaration
SpriteTool::SpriteTool(){}

void SpriteTool::mousePressed(QImage& image, QColor& currColor, QMouseEvent *event){

}
void SpriteTool::mouseReleased(){

}
void SpriteTool::mouseMoved(QImage& image, QColor& currColor, QMouseEvent *event){

}

QPoint SpriteTool::mapToImageCoordinates(const QPoint &point) {
    return QPoint(point.x() / scaleFactor, point.y() / scaleFactor);
}
