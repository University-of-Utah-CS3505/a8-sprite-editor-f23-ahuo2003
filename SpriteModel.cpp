#include "SpriteModel.h"
#include "Bucket.h"
#include "Cursor.h"
#include "Eraser.h"
#include "Eyedropper.h"
#include "Filter.h"
#include "Pencil.h"

SpriteModel::SpriteModel(QObject *parent) : QObject(parent) {
  // Empty Map and QList
  tools.clear();
  frames.clear();

  // Put tools in the Map
  tools["Cursor"] = new Cursor();
  tools["Pencil"] = new Pencil();
  tools["Eraser"] = new Eraser();
  tools["Bucket"] = new Bucket();
  tools["Eyedropper"] = new Eyedropper();
  // tools["Filter"] = new Filter();

  // Set the rest of the variables to default values
  backgroundColor = Qt::white;
  currColor = Qt::black;
  currTool = tools["Cursor"];
  frames.append(QImage(8, 8, QImage::Format_ARGB32));
  currFrame = &frames[0];
  scaleFactor = 64;

  // Fill the currentImage completely with transparent pixels
  currFrame->fill(Qt::transparent);

  // Add initial frame to frame iterator.
  framesIterator = 0;

  spritePlayerSpeed = 1000;
}

void SpriteModel::changeTool(QString toolName) {
  if (tools.contains(toolName)) {
    currTool = tools.value(toolName);
  }
}

void SpriteModel::useTool(QMouseEvent *event) {
  if (event->type() == QEvent::MouseButtonPress)
    this->currTool->mousePressed(*currFrame, currColor, event, scaleFactor);
  else if (event->type() == QEvent::MouseButtonRelease) {
    this->currTool->mouseReleased();
    if (currTool->getName() == "Eyedropper")
      emit chooseColor(currColor);
  } else if (event->type() == QEvent::MouseMove)
    this->currTool->mouseMoved(*currFrame, currColor, event, scaleFactor);
  emit updateFrame(*currFrame);
}

void SpriteModel::previousFrame() {
  qDebug() << framesIterator;
  if (framesIterator > 0) {
    // TODO: Emit signal to enable PREVIOUS frame button
    framesIterator--;
    currFrame = &(frames[framesIterator]);
    emit updateFrame(*currFrame);
  }

  else {
    emit disablePreviousFrameButton();
  }
}

void SpriteModel::nextFrame() {
  if (framesIterator < frames.size() - 1) {
    // TODO: Emit signal to enable NEXT frame button
    framesIterator++;
    currFrame = &(frames[framesIterator]);
    emit updateFrame(*currFrame);
  }

  else {
    emit disableNextFrameButton();
  }
}

void SpriteModel::changeColor(int red, int green, int blue) {
  currColor = QColor(red, green, blue);
}

void SpriteModel::rescale(QSize newSize) {
  // Rescale all frames
  for (QImage &frame : frames) {
    frame = frame.scaled(newSize.width(), newSize.height());
  }
  // Re-scale the currentFrame so it shows properly on the canvas
  // currFrame = currFrame->scaled(newSize.width(), newSize.height());
  scaleFactor = 512 / newSize.width();
  emit updateScaleFactor(scaleFactor);
  emit updateFrame(*currFrame);
}

void SpriteModel::removeFrame() {
  if (frames.size() > 1) {
    if (framesIterator == frames.size() - 1) {
      framesIterator--;
      currFrame = &(frames[framesIterator]);
    }
    frames.removeAt(frames.size() - 1);
    emit updateFrame(*currFrame);
  } else {
    // disable remove signal
  }
}

void SpriteModel::startSpritePlayer() {
  int initialSpeed = spritePlayerSpeed;
  for (const QImage &frame : frames) {
    initialSpeed += spritePlayerSpeed;
    QTimer::singleShot(initialSpeed, this,
                       [this, frame]() { emit updateSpritePlayer(frame); });
  }
}

void SpriteModel::changeSpriteSpeed(int fps) {
  int miliseconds = 1000 / fps;
  spritePlayerSpeed = miliseconds;
}

void SpriteModel::redFilter() {
  // Apply redscale filter to the entire image
  for (int y = 0; y < currFrame->height(); ++y) {
    for (int x = 0; x < currFrame->width(); ++x) {
      QRgb pixelColor = currFrame->pixel(x, y);
      int luminance = qRed(pixelColor) * 0.3 + qGreen(pixelColor) * 0.59 +
                      qBlue(pixelColor) * 0.11;
      currFrame->setPixelColor(x, y, QColor(luminance, 0, 0));
    }
  }
}

void SpriteModel::greenFilter() {
  // Apply redscale filter to the entire image
  for (int y = 0; y < currFrame->height(); ++y) {
    for (int x = 0; x < currFrame->width(); ++x) {
      QRgb pixelColor = currFrame->pixel(x, y);
      int luminance = qRed(pixelColor) * 0.3 + qGreen(pixelColor) * 0.59 +
                      qBlue(pixelColor) * 0.11;
      currFrame->setPixelColor(x, y, QColor(0, luminance, 0));
    }
  }
}

void SpriteModel::blueFilter() {
  // Apply redscale filter to the entire image
  for (int y = 0; y < currFrame->height(); ++y) {
    for (int x = 0; x < currFrame->width(); ++x) {
      QRgb pixelColor = currFrame->pixel(x, y);
      int luminance = qRed(pixelColor) * 0.3 + qGreen(pixelColor) * 0.59 +
                      qBlue(pixelColor) * 0.11;
      currFrame->setPixelColor(x, y, QColor(0, 0, luminance));
    }
  }
}

void SpriteModel::greyFilter() {
  // Apply greyscale filter to the entire image
  for (int y = 0; y < currFrame->height(); ++y) {
    for (int x = 0; x < currFrame->width(); ++x) {
      QRgb pixelColor = currFrame->pixel(x, y);
      int grey = qRed(pixelColor) * 0.3 + qGreen(pixelColor) * 0.59 +
                 qBlue(pixelColor) * 0.11;
      currFrame->setPixelColor(x, y, QColor(grey, grey, grey));
    }
  }
}

void SpriteModel::onPerformSave(QString fileName) {
  QFile saveFile(fileName);
  if (!saveFile.open(QIODevice::WriteOnly)) {
    qDebug() << "Failed saving";
    return;
  }

  QJsonObject projectData;
  projectData["frames"] = framesToJson(frames);
  QJsonDocument saveDoc(projectData);
  saveFile.write(saveDoc.toJson());
  saveFile.close();
}

QJsonArray SpriteModel::framesToJson(const QList<QImage> &frames) {
  QJsonArray framesArray;

  for (const QImage &frame : frames) {
    QJsonObject frameData;
    frameData["width"] = frame.width();
    frameData["height"] = frame.height();

    QJsonArray pixelDataArray;
    for (int y = 0; y < frame.height(); ++y) {
      for (int x = 0; x < frame.width(); ++x) {
        QRgb pixel = frame.pixel(x, y);
        QJsonObject pixelData;
        pixelData["r"] = qRed(pixel);
        pixelData["g"] = qGreen(pixel);
        pixelData["b"] = qBlue(pixel);
        pixelData["a"] = qAlpha(pixel);
        pixelDataArray.append(pixelData);
      }
    }
    frameData["pixels"] = pixelDataArray;
    framesArray.append(frameData);
  }

  return framesArray;
}

void SpriteModel::jsonToFrames(const QJsonArray &framesArray,
                               QList<QImage> &frames) {
  frames.clear();

  for (const QJsonValue &value : framesArray) {
    QJsonObject frameData = value.toObject();
    int width = frameData["width"].toInt();
    int height = frameData["height"].toInt();
    QImage frame(width, height, QImage::Format_ARGB32);

    QJsonArray pixelDataArray = frameData["pixels"].toArray();
    int index = 0;
    for (int y = 0; y < height; ++y) {
      for (int x = 0; x < width; ++x) {
        QJsonObject pixelData = pixelDataArray[index++].toObject();
        int r = pixelData["r"].toInt();
        int g = pixelData["g"].toInt();
        int b = pixelData["b"].toInt();
        int a = pixelData["a"].toInt();
        frame.setPixelColor(x, y, QColor(r, g, b, a));
      }
    }

    frames.append(frame);
  }
}

void SpriteModel::onPerformLoad(QString fileName) {
  QFile loadFile(fileName);
  if (!loadFile.open(QIODevice::ReadOnly))
    return;

  QByteArray saveData = loadFile.readAll();
  QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
  QJsonObject projectData = loadDoc.object();

  jsonToFrames(projectData["frames"].toArray(), frames);

  framesIterator = 0;
  emit updateFrame(frames[0]);
}

// const QString &filePath parameter
void SpriteModel::saveProject() { emit requestSaveFilePath(); }

void SpriteModel::loadProject() { emit requestLoadFilePath(); }

void SpriteModel::addFrame() {
  if (frames.size() < 1)
    frames.append(*currFrame);
  emit updateSpritePlayer(*currFrame);

  QImage newFrame(currFrame->size(), QImage::Format_ARGB32);
  newFrame.fill(Qt::transparent);
  frames.append(newFrame);

  framesIterator++;
  currFrame = &(frames[framesIterator]);
  emit updateFrame(*currFrame);
}
