#include "Canvas.h"
#include "qpainter.h"
#include "qpen.h"
#include <QDebug>
#include <iostream>

// General Tool Declaration
Canvas::Canvas(QWidget *parent) : QLabel(parent) {}

void Canvas::redrawCanvas(QImage frame)
{
    scaleFactor = 64;
    QPixmap pixmap = QPixmap::fromImage(frame.scaled(frame.width() * scaleFactor, frame.height() * scaleFactor, Qt::KeepAspectRatio, Qt::FastTransformation));
    drawGrid(pixmap);
    setPixmap(pixmap);
    std::cout << "Canvas redrawn" << std::endl;
}

void Canvas::updateCanvasScaleFactor(int scaleFactor)
{
    this->scaleFactor = scaleFactor;
}

void Canvas::drawGrid(QPixmap &pixmap){
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::gray, 1, Qt::SolidLine));

    for (int i = 0; i <= pixmap.width(); i+= scaleFactor) {
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
