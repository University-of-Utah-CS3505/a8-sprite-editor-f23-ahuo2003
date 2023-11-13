#include "Bucket.h"
#include "qpixmap.h"

Bucket::Bucket() : SpriteTool(){}

void Bucket::mousePressed() {
    //    if (!pixmap.isNull()) {
    //        QPoint pressPos = event->pos();
    //        // Get the color of the pixel at the pressed position
    //        QColor startColor = pixmap.toImage().pixelColor(pressPos);

    //        // Check if the new color is different from the starting color
    //        if (newColor != startColor) {
    //            // Perform the flood fill
    //            floodFill(pixmap, pressPos, startColor, newColor);
    //        }
    //    }
}
void Bucket::mouseReleased() {

}
void Bucket::mouseMoved() {

}

void Bucket::floodFill(QImage& image, const QPoint& pos, const QColor& startColor, const QColor& newColor) {
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
    floodFill(image, QPoint(pos.x() + 1, pos.y()), startColor, newColor);
    floodFill(image, QPoint(pos.x() - 1, pos.y()), startColor, newColor);
    floodFill(image, QPoint(pos.x(), pos.y() + 1), startColor, newColor);
    floodFill(image, QPoint(pos.x(), pos.y() - 1), startColor, newColor);
}
