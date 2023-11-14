#include "Bucket.h"
#include <QImage>
#include <QDebug>

Bucket::Bucket() : SpriteTool(){
    name = "Bucket";
}

void Bucket::mousePressed(QImage& image, QColor& newColor, QMouseEvent *event, int scaleFactor) {
    //List to avoid infinite recursion when recursively painting pixels.
    QList<QPoint> visitedPixels;

    if (!image.isNull()) {
            QPoint scaledPoint = this->mapToImageCoordinates(event->pos(), scaleFactor);
            QColor startColor = image.pixelColor(scaledPoint);
            // Check if the new color is different from the starting color
            if (newColor != startColor) {
                // Perform the flood fill
                floodFill(image, scaledPoint, startColor, newColor, visitedPixels);
            }
        }
        visitedPixels.clear();
}
void Bucket::mouseReleased() {
    //Do Nothing
}
void Bucket::mouseMoved(QImage& image, QColor& currColor, QMouseEvent *event, int scaleFactor) {

}

void Bucket::floodFill(QImage& image, const QPoint& pos, const QColor& startColor, const QColor& newColor, QList<QPoint>& visitedPixels) {
    if (pos.x() < 0 || pos.x() >= image.width() || pos.y() < 0 || pos.y() >= image.height()) {
        // Check if the position is within bounds
        return;
    }

    // Check if the pixel has already been visited
    if (visitedPixels.contains(pos)){
        return;
    }

    // Check if the color at the current position matches the starting color
    if (image.pixelColor(pos) != startColor) {
        return;
    }

    // Change the color of the current pixel
    image.setPixelColor(pos, newColor);
    visitedPixels.append(pos);

    // Recursively fill the neighboring pixels
    floodFill(image, QPoint(pos.x() + 1, pos.y())    , startColor, newColor, visitedPixels);    // Right
    floodFill(image, QPoint(pos.x() - 1, pos.y())    , startColor, newColor, visitedPixels);    // Left
    floodFill(image, QPoint(pos.x()    , pos.y() + 1), startColor, newColor, visitedPixels);    // Down
    floodFill(image, QPoint(pos.x()    , pos.y() - 1), startColor, newColor, visitedPixels);    // Up
    floodFill(image, QPoint(pos.x() + 1, pos.y() + 1), startColor, newColor, visitedPixels);    // Bottom-Right
    floodFill(image, QPoint(pos.x() - 1, pos.y() - 1), startColor, newColor, visitedPixels);    // Upper-Left
    floodFill(image, QPoint(pos.x() - 1, pos.y() + 1), startColor, newColor, visitedPixels);    // Bottom-Left
    floodFill(image, QPoint(pos.x() + 1, pos.y() - 1), startColor, newColor, visitedPixels);    // Upper-Right
}
