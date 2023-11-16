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
   * @param *event
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
   * @param newSize: new width and height for the new canvas.
   */
    void rescale(QSize newSize);

    /**
     * @brief saveProject TODO
     */
    void saveProject();

    /**
     * @brief loadProject TODO
     */
    void loadProject();

    /**
   * @brief add Frame(s) to create animation.
   */
    void addFrame();

    /**
   * @brief delete unwanted Frame(s).
   */
    void removeFrame();

    /**
     * @brief startSpritePlayer TODO
     */
    void startSpritePlayer();

    /**
     * @brief changeSpriteSpeed TODO
     */
    void changeSpriteSpeed(int speed);

    /**
     * @brief greyFilter
     * @param currentFrame
     */
    void greyFilter(QImage& currentFrame);

    /**
     * @brief redFilter
     * @param currentFrame
     */
    void redFilter(QImage& currentFrame);

    /**
     * @brief greenFilter
     * @param currentFrame
     */
    void greenFilter(QImage& currentFrame);

    /**
     * @brief blueFilter
     * @param currentFrame
     */
    void blueFilter(QImage& currentFrame);

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

    /**
   * @brief get the new scale factor for the canvas to redraw.
   * @param scaleFactor
   */
    void updateScaleFactor(int scaleFactor);

    /**
     * @brief disablePreviousFrameButton TODO
     */
    void disablePreviousFrameButton();

    /**
     * @brief disableNextFrameButton TODO
     */
    void disableNextFrameButton();

    /**
     * @brief updateSpritePlayer TODO
     */
    void updateSpritePlayer(QImage frame);

private:
    QMap<QString, SpriteTool *> tools;
    SpriteTool *currTool;
    QImage *currFrame;
    QColor backgroundColor;
    QColor currColor;
    QList<QImage> frames;
    int framesIterator;
    int scaleFactor;
    // Helper functions for saving and loading
    QJsonObject frameToJson(const QList<QImage> &frames);
    void jsonToFrame(const QJsonObject &project, QList<QImage> &frames);
    int spritePlayerSpeed;
};
#endif // SPRITEMODEL_H
