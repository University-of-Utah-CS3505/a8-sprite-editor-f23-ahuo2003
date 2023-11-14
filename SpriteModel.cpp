#include "SpriteModel.h"
#include "Pencil.h"
#include "Eraser.h"
#include "Bucket.h"
#include "Eyedropper.h"
#include "Filter.h"
#include <QMouseEvent>
#include <QDebug>

SpriteModel::SpriteModel(QObject *parent) : QObject(parent), framesIterator(frames){
    //Empty Map and QList
    tools.clear();
    frames.clear();

    //Put tools in the Map
    tools["Pencil"]     = new Pencil();
    tools["Eraser"]     = new Eraser();
    tools["Bucket"]     = new Bucket();
    tools["Eyedropper"] = new Eyedropper();
    tools["Filter"]     = new Filter();

    //Set the rest of the variables to default values
    backgroundColor     = Qt::white;
    currColor           = Qt::black;
    currTool            = tools["Pencil"];
    currFrame           = QImage(8, 8, QImage::Format_ARGB32);
    scaleFactor         = 64;

    //Fill the currentImage completely with transparent pixels
    currFrame.fill(Qt::transparent);

    //Add initial frame to frame iterator.
    frames.append(currFrame);
    framesIterator.toFront();
}

void SpriteModel::changeTool(QString toolName)
{
    if (tools.contains(toolName)) {
        currTool = tools.value(toolName);
    }
}

void SpriteModel::useTool(QMouseEvent *event){
    if (event->type() == QEvent::MouseButtonPress)
        this->currTool->mousePressed(currFrame, currColor, event, scaleFactor);
    else if (event->type() == QEvent::MouseButtonRelease){
        this->currTool->mouseReleased();
        if (currTool->getName() == "Eyedropper")
            emit chooseColor(currColor);
        qDebug()<< currTool->getName();
    }
    else if (event->type() == QEvent::MouseMove)
        this->currTool->mouseMoved(currFrame, currColor, event, scaleFactor);
    emit updateFrame(currFrame);
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
    if (framesIterator.hasPrevious()){
        //TODO: Emit signal to enable PREVIOUS frame button
        currFrame = framesIterator.previous();
        emit updateFrame(currFrame);
    }

    else {
       //TODO: Emit signal to disable the PREVIOUS frame button
    }
}

void SpriteModel::nextFrame()
{
    if (framesIterator.hasNext()){
        //TODO: Emit signal to enable NEXT frame button
        currFrame = framesIterator.next();
        emit updateFrame(currFrame);
    }

    else {
        //TODO: Emit signal to disable the NEXT button
    }
}

void SpriteModel::changeColor(int red, int green, int blue)
{
    currColor = QColor(red, green, blue);
}

void SpriteModel::rescale(QSize newSize){
    currFrame = currFrame.scaled(newSize, Qt::KeepAspectRatio);
    scaleFactor = newSize.width() * newSize.height();
}
