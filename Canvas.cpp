#include "Canvas.h"
#include "qpainter.h"
#include "qpen.h"

// General Tool Declaration
Canvas::Canvas(QWidget *parent) : QLabel(parent) {}

void Canvas::redrawCanvas(QImage frame)
{
    //Base scale factor for 8x8 canvas
    scaleFactor = 64;
    QPixmap pixmap = QPixmap::fromImage(frame.scaled(frame.width() * scaleFactor, frame.height() * scaleFactor, Qt::KeepAspectRatio, Qt::FastTransformation));
    drawGrid(pixmap);
    setPixmap(pixmap);
}

void Canvas::updateCanvasScaleFactor(int scaleFactor)
{
    this->scaleFactor = scaleFactor;
}

void Canvas::drawGrid(QPixmap &pixmap){
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));

    for (int i = scaleFactor; i <= pixmap.width(); i+= scaleFactor) {
        painter.drawLine(i, 0, i, pixmap.height());
        painter.drawLine(0, i, pixmap.width(), i);
    }
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
