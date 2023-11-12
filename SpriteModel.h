#ifndef SPRITEMODEL_H
#define SPRITEMODEL_H
#include "SpriteTool.h"
#include "doublelinkedlist.h"
#include <QMap>
#include <QColor>
#include <QObject>

class SpriteModel : public QObject{
    Q_OBJECT
public:
    explicit SpriteModel (QObject *parent = nullptr);
public slots:
    /**
     * @brief start sets all the private values to its default state
     */
    void start();

    /**
     * @brief changeTool changes the currentTool for the tool desired
     * @param tool
     */
    void changeTool(SpriteTool tool);

    /**
     * @brief useTool uses the mousePressed method of the tool selected.
     * @param currentTool
     */
    void useTool(SpriteTool currentTool);

    /**
     * @brief undo reverts to the previous frame version.
     */
    void undo();

    /**
     * @brief redo goes forward to a newer frame version.
     */
    void redo();

    /**
     * @brief previousFrame shows to the previous frame.
     */
    void previousFrame();

    /**
     * @brief nextFrame shows the next frame.
     */
    void nextFrame();

    /**
     * @brief changeColor changes the currentColor based on the RGB sliders in the view.
     */
    void changeColor();
signals:
    /**
     * @brief updateFrame tells the view to update the drawing in the current Frame.
     */
    void updateFrame();

    /**
     * @brief chooseTool tells the view to show the user the selected tool
     * @param currentTool the current tool
     */
    void chooseTool(SpriteTool currentTool);

    /**
     * @brief chooseColor tells the view that a new color has been assigned in the model,
     * and that it needs to update its RGB sliders.
     * @param currentColor
     */
    void chooseColor(QColor currentColor);

private:
    QMap<std::string, SpriteTool> tools;
    SpriteTool currTool;
    QColor backgroundColor;
    QColor currColor;
    DoubleLinkedList<int> frames; // This int will be replace with Frames

};
#endif // SPRITEMODEL_H
