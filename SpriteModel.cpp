#include "SpriteModel.h"
#include "Bucket.h"
#include "Cursor.h"
#include "Eraser.h"
#include "Eyedropper.h"
#include "Filter.h"
#include "Pencil.h"

SpriteModel::SpriteModel(QObject *parent)
    : QObject(parent), framesIterator(frames) {
  // Empty Map and QList
  tools.clear();
  frames.clear();

  // Put tools in the Map
  tools["Cursor"] = new Cursor();
  tools["Pencil"] = new Pencil();
  tools["Eraser"] = new Eraser();
  tools["Bucket"] = new Bucket();
  tools["Eyedropper"] = new Eyedropper();
  tools["Filter"] = new Filter();

  // Set the rest of the variables to default values
  backgroundColor = Qt::white;
  currColor = Qt::black;
  currTool = tools["Cursor"];
  currFrame = QImage(8, 8, QImage::Format_ARGB32);
  scaleFactor = 64;

  // Fill the currentImage completely with transparent pixels
  currFrame.fill(Qt::transparent);

  // Add initial frame to frame iterator.
  frames.append(currFrame);
  framesIterator.toFront();
}

void SpriteModel::changeTool(QString toolName) {
  if (tools.contains(toolName)) {
    currTool = tools.value(toolName);
  }
}

void SpriteModel::useTool(QMouseEvent *event) {
  if (event->type() == QEvent::MouseButtonPress)
    this->currTool->mousePressed(currFrame, currColor, event, scaleFactor);
  else if (event->type() == QEvent::MouseButtonRelease) {
    this->currTool->mouseReleased();
    if (currTool->getName() == "Eyedropper")
      emit chooseColor(currColor);
  } else if (event->type() == QEvent::MouseMove)
    this->currTool->mouseMoved(currFrame, currColor, event, scaleFactor);
  emit updateFrame(currFrame);
}

void SpriteModel::previousFrame() {
  if (framesIterator.hasPrevious()) {
    // TODO: Emit signal to enable PREVIOUS frame button
    currFrame = framesIterator.previous();
    emit updateFrame(currFrame);
  }

  else {
    // TODO: Emit signal to disable the PREVIOUS frame button
  }
}

void SpriteModel::nextFrame() {
  if (framesIterator.hasNext()) {
    // TODO: Emit signal to enable NEXT frame button
    currFrame = framesIterator.next();
    emit updateFrame(currFrame);
  }

  else {
    // TODO: Emit signal to disable the NEXT button
  }
}

void SpriteModel::changeColor(int red, int green, int blue) {
  currColor = QColor(red, green, blue);
}

void SpriteModel::rescale(QSize newSize) {
  //TODO: Rescale all frames
  currFrame = currFrame.scaled(newSize.width(), newSize.height());
  scaleFactor = 512 / newSize.width();
  emit updateScaleFactor(scaleFactor);
}

void SpriteModel::saveProject(const QString &filePath) {
  // Ensure the filePath has the .ssp extension
  QString savePath = filePath;
  if (!savePath.endsWith(".ssp", Qt::CaseInsensitive))
    savePath += ".ssp";

  QJsonObject project;

  // Add project-specific information to the JSON object
  project["projectName"] = "Your Project Name";

  // Assuming 'currentFrame' is a QPixmap representing the current frame
  project["frame"] = frameToJson(currFrame);

  // Convert the JSON object to a JSON document
  QJsonDocument jsonDoc(project);

  // Save the JSON document to a file with .ssp extension
  QFile saveFile(savePath);
  if (saveFile.open(QFile::WriteOnly | QFile::Text)) {
    saveFile.write(jsonDoc.toJson());
    saveFile.close();
  } else {
    qDebug() << "Failed to save project.";
  }
}

void SpriteModel::loadProject(const QString &filePath) {
  // Load the JSON document from the file
  QFile loadFile(filePath);
  if (!loadFile.open(QFile::ReadOnly | QFile::Text)) {
    qDebug() << "Could not open the project file.";
    return;
  }

  QJsonDocument jsonDoc = QJsonDocument::fromJson(loadFile.readAll());
  loadFile.close();

  if (jsonDoc.isNull()) {
    qDebug() << "Failed to parse the project file.";
    return;
  }

  // Parse the JSON document and retrieve project information
  QJsonObject project = jsonDoc.object();

  // Retrieve frames data and currFrame data
  QList<QImage> loadedFrames;
  jsonToFrame(project, loadedFrames);

  // Set currFrame to the first frame if there is at least one frame
  if (!loadedFrames.isEmpty()) {
    currFrame = loadedFrames.first();
    // You may want to handle the case where currFrame is part of the loaded frames differently
    loadedFrames.removeFirst();
  }

  // Update the frames QList with the loaded frames
  frames = loadedFrames;

  // emit updateFrame(); // Optional: emit a signal after loading
}

void SpriteModel::addFrame() {
  frames.append(QImage(currFrame.size(), QImage::Format_ARGB32));
  currFrame = framesIterator.next();
  emit updateFrame(currFrame);
}

void SpriteModel::removeFrame() {
  frames.removeOne(currFrame);
  currFrame = framesIterator.previous();
  emit updateFrame(currFrame);
}

QJsonObject SpriteModel::frameToJson(const QList<QImage>& frames)
{
    QJsonObject project;

    // Add project-specific information to the JSON object
    project["projectName"] = "Your Project Name";

    // Convert the list of frames to a JSON array
    QJsonArray framesData;
    for (const QImage& frame : frames) {
        QJsonObject frameData;
        frameData["width"] = frame.width();
        frameData["height"] = frame.height();

        // Convert the pixel data to a JSON array
        QJsonArray pixelData;
        for (int y = 0; y < frame.height(); ++y) {
            for (int x = 0; x < frame.width(); ++x) {
                QRgb pixelColor = frame.pixel(x, y);
                QString pixelValue = QString("%1,%2,%3,%4")
                                        .arg(qRed(pixelColor))
                                        .arg(qGreen(pixelColor))
                                        .arg(qBlue(pixelColor))
                                        .arg(qAlpha(pixelColor));
                pixelData.append(pixelValue);
            }
        }

        frameData["pixels"] = pixelData;
        framesData.append(frameData);
    }

    project["frames"] = framesData;
    
    // Assuming 'currentFrame' is a QPixmap representing the current frame
    project["currFrame"] = frameToJson(currFrame);

    return project;
}

void SpriteModel::jsonToFrame(const QJsonObject& project, QList<QImage>& frames)
{
    // Retrieve the frames data array
    QJsonArray framesData = project["frames"].toArray();

    // Clear the existing frames QList
    frames.clear();

    // Loop through each frame data
    for (const QJsonValue& frameValue : framesData) {
        QJsonObject frameData = frameValue.toObject();

        // Retrieve width and height
        int width = frameData["width"].toInt();
        int height = frameData["height"].toInt();

        // Create a new frame with the specified dimensions
        QImage frame = QImage(width, height, QImage::Format_ARGB32);

        // Retrieve pixel data
        QJsonArray pixelData = frameData["pixels"].toArray();
        int index = 0;
        for (int y = 0; y < frame.height(); ++y) {
            for (int x = 0; x < frame.width(); ++x) {
                QJsonObject pixel = pixelData[index++].toObject();

                int red = pixel["red"].toInt();
                int green = pixel["green"].toInt();
                int blue = pixel["blue"].toInt();
                int alpha = pixel["alpha"].toInt();

                frame.setPixelColor(x, y, QColor(red, green, blue, alpha));
            }
        }

        // Add the frame to the frames QList
        frames.append(frame);
    }

    // Set currFrame to the first frame if there is at least one frame
    if (!frames.isEmpty()) {
        QJsonObject currFrameData = project["currFrame"].toObject();
    }
}
