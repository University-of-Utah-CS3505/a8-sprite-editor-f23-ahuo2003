#include "Eyedropper.h"
#include <QDebug>

Eyedropper::Eyedropper() : SpriteTool(){
    name = "Eyedropper";
}

QColor Eyedropper::getPixelColor(QImage& image, QPoint pixelCoord){
    return image.pixelColor(pixelCoord);
}

void Eyedropper::mousePressed(QImage& image, QColor& currColor, QMouseEvent *event, int scaleFactor){
    currColor = getPixelColor(image, this->mapToImageCoordinates(event->pos(), scaleFactor));
}
void Eyedropper::mouseReleased(){
    //Nothing. Once in the model a method emits a signal to update the RGB.
}
void Eyedropper::mouseMoved(QImage& image, QColor& currColor, QMouseEvent *event, int scaleFactor){
    currColor = getPixelColor(image, this->mapToImageCoordinates(event->pos(), scaleFactor));
}

