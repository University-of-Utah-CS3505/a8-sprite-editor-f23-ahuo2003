#ifndef SPRITEMODEL_H
#define SPRITEMODEL_H
#include "SpriteTool.h"
#include <QColor>
#include <QDebug>
#include <QFile>
#include <QImage>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QListIterator>
#include <QMap>
#include <QMouseEvent>
#include <QObject>
#include <QPixmap>
#include <QSize>

class SpriteModel : public QObject {
  Q_OBJECT
public:
  explicit SpriteModel(QObject *parent = nullptr);
public slots:

  /**
   * @brief changeTool changes the currentTool for the tool desired
   * @param tool
   */
  void changeTool(QString tool);

  /**
   * @brief useTool uses the mousePressed method of the tool selected.
   * @param currentTool
   */
  void useTool(QMouseEvent *event);

  /**
   * @brief previousFrame shows to the previous frame.
   */
  void previousFrame();

  /**
   * @brief nextFrame shows the next frame.
   */
  void nextFrame();

  /**
   * @brief changeColor changes the currentColor based on the RGB sliders in the
   * view.
   */
  void changeColor(int red, int green, int blue);

  /**
   * @brief rescale re-scales the image and recalculates the scaleFactor
   * based on the canvas dimensions.
   */
  void rescale(QSize newSize);

  void saveProject(const QString &filePath);

  void loadProject(const QString &filePath);
  void addFrame();
  void removeFrame();

signals:
  /**
   * @brief updateFrame tells the view to update the drawing in the current
   * Frame.
   */
  void updateFrame(QImage);

  /**
   * @brief chooseTool tells the view to show the user the selected tool
   * @param currentTool the current tool
   */
  void chooseTool(SpriteTool currentTool);

  /**
   * @brief chooseColor tells the view that a new color has been assigned in the
   * model, and that it needs to update its RGB sliders.
   * @param currentColor
   */
  void chooseColor(QColor currentColor);

  void updateScaleFactor(int scaleFactor);

private:
  QMap<QString, SpriteTool *> tools;
  SpriteTool *currTool;
  QImage currFrame;
  QColor backgroundColor;
  QColor currColor;
  QList<QImage> frames;
  QListIterator<QImage> framesIterator;
  int scaleFactor;

  // Helper functions for saving and loading
  QJsonObject frameToJson(const QList<QImage>& frames);
  void jsonToFrame(const QJsonObject& project, QList<QImage>& frames);
};
#endif // SPRITEMODEL_H
