#include "Frame.h"

Frame::Frame(QSize size) : currFrameIterator(versions)
{
    QImage currFrame(size, QImage::Format_ARGB32);
    currFrame.fill(Qt::transparent);
    versions.append(currFrame);
    currFrameIterator.toFront();
}

QImage Frame::getCurrentFrame() const
{
    return currFrame;
}

void Frame::addNewVersion(QImage& newVersion)
{
    if (versions.size() > 5){
        removeOldestVersion();
    }

    versions.append(newVersion);
    currFrame = currFrameIterator.next();
}

void Frame::nextVersion(QImage& newVersion){
    if (currFrameIterator.hasNext()){
        currFrame = currFrameIterator.next();
    }
    else{
        addNewVersion(newVersion);
    }
}

void Frame::previousVersion(){
    if (currFrameIterator.hasPrevious()){
        currFrame = currFrameIterator.previous();
    }
}

void Frame::removeOldestVersion()
{
    versions.pop_front();
}

