#include "SpriteModel.h"
#include "Pencil.h"
#include "Eraser.h"
#include "Bucket.h"
#include "Eyedropper.h"
#include "Filter.h"
#include <iostream>

SpriteModel::SpriteModel(QObject *parent) : QObject(parent){}

void SpriteModel::start()
{
    //Empty Map and QList
    tools.clear();
    frames.clear();

    //Put tools in the Map
    tools["Pencil"] = new Pencil();
    tools["Eraser"] = new Eraser();
    tools["Bucket"] = new Bucket();
    tools["Eyedropper"] = new Eyedropper();
    tools["Filter"] = new Filter();

    //White Background, Black Cursor
    backgroundColor = Qt::white;
    currColor = Qt::black;
}

void SpriteModel::changeTool(SpriteTool tool)
{
    QString toolName = typeid(tool).name();
    this->currTool = tools.value(toolName);
    std::cout << toolName.toStdString() << " was selected and declared to currTool" << std::endl;
}

void SpriteModel::useTool(QMouseEvent *event){
    //Implementing rn
//    this->currTool->onMouseMove(event);
//    this->currTool->onMousePressed(event);
//    this->currTool->onMouseRelease(event);
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
