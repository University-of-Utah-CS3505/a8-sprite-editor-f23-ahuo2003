#include "Pencil.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>

Pencil::Pencil() : SpriteTool(){}

void Pencil::mousePressed(QImage& image, QColor& currColor, QMouseEvent *event) {
    //Start the Painter
    painter.begin(&image);

    //Set format of the Pen
    QPen cursorPen = painter.pen();
    cursorPen.setColor(currColor);
    painter.setPen(cursorPen);

    //Draw a Pixel
    painter.drawPoint(event->pos());
    //Set x1 and y1 to startPoint
    startPoint = event->pos();
}

void Pencil::mouseReleased(){
    //End Painter
    painter.end();
}
void Pencil::mouseMoved(QImage& image, QColor& currColor, QMouseEvent *event){
    //Set x2 and y2 to endPoint
    endPoint = event->pos();

    //Draw a Line between (x1,y1) and (x2,y2)
    painter.drawLine(startPoint, endPoint);

    //Get a new starting point for next line connection.
    startPoint = event->pos();
}
