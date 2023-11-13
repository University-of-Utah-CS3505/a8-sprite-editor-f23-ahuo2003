#include "Pencil.h"
#include <QMouseEvent>
#include <QDebug>

Pencil::Pencil() : SpriteTool(){}

void Pencil::drawPixel(QImage& image, QColor& currColor, QMouseEvent *event){
    QPoint scaledPoint(event->pos());
    scaledPoint.setX(scaledPoint.x() - 1);
    image.setPixelColor(scaledPoint, currColor);
}

void Pencil::mousePressed(QImage& image, QColor& currColor, QMouseEvent *event) {
    drawPixel(image, currColor, event);
}

void Pencil::mouseReleased(){

}
void Pencil::mouseMoved(){
//    //Draw based on current cord and previous
//    //x1 and y1
//    startX = event->pos().x();
//    startY = event->pos().y();

//    //x2 and y2
//    endX = event->pos().x();
//    endY = event->pos().y();

//    //Horizonal line or Regular Line
//    if (endX != startX){
//        int slope = (endY-startY)/(endX-startX);
//        for (int i = startX; i < endX; i++){
//            endY = slope * (endX-startY);
//            QPoint newPoint(endX,endY);
//            drawPixel(image, newPoint, currColor);
//        }
//    }
//    //Vertical Line
//    else if (endY != startY){
//        while (startY < endY) {
//            QPoint newPoint(startX, startY + 1);
//            drawPixel(image, newPoint, currColor);
//        }
//    }
}
