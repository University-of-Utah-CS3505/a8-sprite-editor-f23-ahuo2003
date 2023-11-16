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
#include <QTimer>

/**
 * @brief The SpriteModel class makes all the operations for the Sprite Editor
 * Project to function as desired.
 */
class SpriteModel : public QObject {
  Q_OBJECT
public:
  /**
   * @brief SpriteModel constructor.
   * @param parent a QObject pointer.
   */
  explicit SpriteModel(QObject *parent = nullptr);
public slots:

  /**
   * @brief changeTool changes the currentTool for the tool desired.
   * @param tool the tool to be changed to.
   */
  void changeTool(QString tool);

  /**
   * @brief useTool uses the implemented event methods of the tool selected.
   * @param *event an event pointer.
   */
  void useTool(QMouseEvent *event);

  /**
   * @brief previousFrame moves to the previous frame.
   */
  void previousFrame();

  /**
   * @brief nextFrame moves to the next frame.
   */
  void nextFrame();

  /**
   * @brief changeColor changes the currentColor based on the RGB sliders in the
   * view.
   * @param red a value representing red between 0 and 255.
   * @param green a value representing green between 0 and 255.
   * @param blue a value representing blue between 0 and 255.
   */
  void changeColor(int red, int green, int blue);

  /**
   * @brief rescale re-scales the image and recalculates the scaleFactor
   * based on the canvas dimensions.
   * @param newSize new width and height for the new canvas.
   */
  void rescale(QSize newSize);

  /**
   * @brief saveProject saves the project in a .ssp format.
   */
  void saveProject();

  /**
   * @brief loadProject loads a project based on a .ssp format.
   */
  void loadProject();

  /**
   * @brief add a new frame to the editor.
   */
  void addFrame();

  /**
   * @brief deletes the latest(rightmost) frame. If the frame to be removed is
   * the current one, it makes the current frame the previous one and proceeds
   * to delete the rightmost frame as intended.
   */
  void removeFrame();

  /**
   * @brief startSpritePlayer goes through all the frames in order with the
   * desired delay between them.
   */
  void startSpritePlayer();

  /**
   * @brief changeSpriteSpeed changes the speed at which the frames are shown in
   * the sprite player.
   * @param fps an int representing the speed to print the frames (frames per
   * second).
   */
  void changeSpriteSpeed(int speed);

  /**
   * @brief greyFilter applies a grey filter to the current frame.
   */
  void greyFilter();

  /**
   * @brief redFilter applies a red filter to the current frame.
   */
  void redFilter();

  /**
   * @brief greenFilter applies a green filter to the current frame.
   */
  void greenFilter();

  /**
   * @brief blueFilter applies a blue filter to the current frame.
   */
  void blueFilter();

  /**
   * @brief onPerformSave save the project.
   * @param fileName the name of the file.
   */
  void onPerformSave(QString fileName);

  /**
   * @brief onPerformLoad load the project.
   * @param fileName the name of the file.
   */
  void onPerformLoad(QString fileName);

signals:
  /**
   * @brief updateFrame tells the view to update the frame shown in the view
   * with the given frame.
   * @param frame the given frame.
   */
  void updateFrame(QImage);

  /**
   * @brief chooseColor tells the view that a new color has been assigned in the
   * model, and that it needs to update its RGB sliders.
   * @param currentColor
   */
  void chooseColor(QColor currentColor);

  /**
   * @brief sends the new scale factor for the canvas to redraw.
   * @param scaleFactor a factor to scale the canvas.
   */
  void updateScaleFactor(int scaleFactor);

  /**
   * @brief disablePreviousFrameButton tells the view to disable the previous
   * frame button.
   */
  void disablePreviousFrameButton();

  /**
   * @brief disableNextFrameButton tells the view to disable the previous frame
   * button.
   */
  void disableNextFrameButton();

  /**
   * @brief updateSpritePlayer tells the view to update the sprite player with
   * the given frame.
   * @param frame a frame to update the sprite player with.
   */
  void updateSpritePlayer(QImage frame);

  /**
   * @brief requestSaveFilePath tells the view to start save file protocols.
   */
  void requestSaveFilePath();

  /**
   * @brief requestLoadFilePath tells the view to start load file protocols.
   */
  void requestLoadFilePath();

private:
  QMap<QString, SpriteTool *> tools;
  SpriteTool *currTool;
  QImage *currFrame;
  QColor backgroundColor;
  QColor currColor;
  QList<QImage> frames;
  int framesIterator;
  int scaleFactor;
  int spritePlayerSpeed;

  /**
   * @brief framesToJson change model readable data to Json format data.
   * @param frames the frames data that will be converted.
   * @return converted data in Json format.
   */
  QJsonArray framesToJson(const QList<QImage> &frames);

  /**
   * @brief jsonToFrames change Json format data to model readable data.
   * @param framesArray a QJsonArray object containing frame data.
   * @param frames a QList of frames.
   */
  void jsonToFrames(const QJsonArray &framesArray, QList<QImage> &frames);
};
#endif // SPRITEMODEL_H
