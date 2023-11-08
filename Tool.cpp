// Most of this is theoretical and based of docs, needs to be refactor to fit our use
#include "Tool.h"

Tool::Tool(QObject *parent, QString name) : QObject(parent) {
    this->name = name;
    // Initialize other members...
}

#include "PencilTool.h" // Assume PencilTool is a derived class of Tool

PencilTool::PencilTool(QObject *parent) : Tool(parent, "Pencil") {
    // Additional initialization for the Pencil tool
    // We can set a specific color or other properties for the Pencil tool here.
}

void PencilTool::onMousePress(QPixmap& pixmap, const QPoint& pos) {
    // Implement the action when the mouse is pressed
    QPainter painter(&pixmap); // Create a QPainter object associated with the QPixmap
    painter.setPen(QPen(currentColor, 1)); // Set the color and pen width
    painter.drawPoint(pos);
    // Update the pixmap or emit signals to update the view.
    // We might want to update the view after every mouse press or as needed.
}

void PencilTool::onMouseRelease(QPixmap& pixmap, const QPoint& pos) {
    // Implement the action when the mouse is released (if applicable)
}

void PencilTool::onMouseMove(QPixmap& pixmap, const QPoint& startPos, const QPoint& endPos) {
    // Implement the action when the mouse is moved (for drawing, e.g., line drawing)
    QPainter painter(&pixmap);
    painter.setPen(QPen(currentColor, 1)); // Set the color and pen width
    painter.drawLine(startPos, endPos);
    // Update the pixmap or emit signals to update the view.
}
