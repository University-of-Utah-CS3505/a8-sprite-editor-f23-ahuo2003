#include "SpriteModel.h"
#include "Pencil.h"
#include "Eraser.h"
#include "Bucket.h"
#include "Eyedropper.h"
#include "Filter.h"
#include <iostream>
#include <QMouseEvent>

SpriteModel::SpriteModel(QObject *parent) : QObject(parent){
    //Empty Map and QList
    currFrame = QImage(512, 512, QImage::Format_ARGB32);
    tools.clear();
    frames.clear();

    //Put tools in the Map
    tools["Pencil"]     = new Pencil();
    tools["Eraser"]     = new Eraser();
    tools["Bucket"]     = new Bucket();
    tools["Eyedropper"] = new Eyedropper();
    tools["Filter"]     = new Filter();

    //White Background, Black Cursor
    backgroundColor = Qt::white;
    currColor = Qt::black;
    currTool = tools["Pencil"];
}

void SpriteModel::changeTool(SpriteTool tool)
{
    QString toolName = typeid(tool).name();
    currTool = tools.value(toolName);
}

void SpriteModel::useTool(QMouseEvent *event){
//    if (event->type() == QEvent::MouseButtonPress)
//        this->currTool->mousePressed(currFrame, currColor, event);
//    else if (event->type() == QEvent::MouseButtonRelease)
//        this->currTool->mouseReleased();
//    else if (event->type() == QEvent::MouseMove)
//        this->currTool->mouseMoved();
    std::cout << "useTool Requested" << std::endl;
    currTool->mousePressed(currFrame, currColor, event);
    emit updateFrame(currFrame);
    std::cout << "MouseEvent Triggered" << std::endl;
}

void SpriteModel::undo()
{
    //TODO
}

void SpriteModel::redo()
{
    //TODO
}

void SpriteModel::previousFrame()
{
    //TODO
}

void SpriteModel::nextFrame()
{
    //TODO
}

void SpriteModel::changeColor(int red, int green, int blue)
{
    QColor newColor = QColor(red, green, blue);
    emit chooseColor(newColor);
}
