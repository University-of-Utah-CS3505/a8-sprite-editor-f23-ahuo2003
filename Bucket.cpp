#include "Bucket.h"

Bucket::Bucket() : SpriteTool() { name = "Bucket"; }

void Bucket::mousePressed(QImage &image, QColor &newColor, QMouseEvent *event, int scaleFactor) {
    if (!image.isNull()) {
        QPoint scaledPoint = this->mapToImageCoordinates(event->pos(), scaleFactor);
        QColor startColor = image.pixelColor(scaledPoint);
        // Check if the new color is different from the starting color
        if (newColor != startColor) {
            // Perform the flood fill
            floodFill(image, scaledPoint, startColor, newColor);
        }
    }
}

void Bucket::mouseReleased() {
    // Do Nothing
}

void Bucket::mouseMoved(QImage &image, QColor &currColor, QMouseEvent *event, int scaleFactor) {
    // Do Nothing
}

void Bucket::floodFill(QImage &image, const QPoint &pos, const QColor &startColor, const QColor &newColor) {
    if (pos.x() < 0 || pos.x() >= image.width() || pos.y() < 0 || pos.y() >= image.height()) {
        // Check if the position is within bounds
        return;
    }

    // Check if the color at the current position matches the starting color
    if (image.pixelColor(pos) != startColor) {
        return;
    }

    // Change the color of the current pixel
    image.setPixelColor(pos, newColor);

    // Recursively fill the neighboring pixels
    floodFill(image, QPoint(pos.x() + 1, pos.y()), startColor, newColor); // Right
    floodFill(image, QPoint(pos.x() - 1, pos.y()), startColor, newColor); // Left
    floodFill(image, QPoint(pos.x(), pos.y() + 1), startColor, newColor); // Down
    floodFill(image, QPoint(pos.x(), pos.y() - 1), startColor, newColor); // Up
}
