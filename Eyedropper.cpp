#include "Eyedropper.h"
#include <QDebug>

Eyedropper::Eyedropper() : SpriteTool(){}

QColor Eyedropper::getPixelColor(QImage& image, QMouseEvent *event){
    return image.pixelColor(event->pos());
}

void Eyedropper::mousePressed(QImage& image, QColor& currColor, QMouseEvent *event){
    currColor = getPixelColor(image, event);
}
void Eyedropper::mouseReleased(){
    //Do nothing. This will be taken care of in model.
}
void Eyedropper::mouseMoved(QImage& image, QColor& currColor, QMouseEvent *event){
    currColor = getPixelColor(image, event);
}

