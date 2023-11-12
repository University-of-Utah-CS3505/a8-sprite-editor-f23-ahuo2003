#include "SpriteModel.h"

SpriteModel::SpriteModel(QObject *parent) : QObject(parent){}

void SpriteModel::start()
{
    //Do something
}

void SpriteModel::changeTool(SpriteTool tool)
{
    //Do something
}

void SpriteModel::useTool(SpriteTool currentTool){
    //Do something
}

void SpriteModel::undo()
{
    //Do something
}

void SpriteModel::redo()
{
    //Do something
}

void SpriteModel::previousFrame()
{
    //Do something
}

void SpriteModel::nextFrame()
{
    //Do something
}

void SpriteModel::changeColor(int red, int green, int blue)
{
    QColor newColor = QColor(red, green, blue);
    emit chooseColor(newColor);
}
