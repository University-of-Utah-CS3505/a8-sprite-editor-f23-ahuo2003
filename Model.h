#ifndef MODEL_H
#define MODEL_H
#include <QColor>
#include <QList>
#include <QMap>
#include "Tool.h"
#include "Frame.h"

/**
 * @authors Names:
 * @authors GitHubs:
 *
 * @title Assignment 8: Sprite Editor Implementation
 *
 * @brief The Model class performs operations needed for the Sprite Editor to execute the tools in the Graphical User Interface.
 */
class Model : public QObject {
    Q_OBJECT
public:
    /**
     * @brief Model constructor
     * @param parent a QObject
     */
    explicit Model(QObject *parent = nullptr);


public slots:
    /**
     * @brief start sets all the private values to its default state
     */
    start();

    /**
     * @brief changeTool changes the currentTool for the tool desired
     * @param tool
     */
    changeTool(Tool tool);

    /**
     * @brief useTool uses the mousePressed method of the tool selected.
     * @param currentTool
     */
    useTool(Tool currentTool);

    /**
     * @brief undo reverts to the previous frame version
     */
    undo();

    /**
     * @brief redo goes forward to a newer frame version
     */
    redo();

    /**
     * @brief previousFrame shows to the previous frame.
     */
    previousFrame();

    /**
     * @brief nextFrame shows the next frame.
     */
    nextFrame();

    /**
     * @brief changeColor changes the currentColor based on the RGB sliders in the view.
     */
    changeColor();

signals:
    /**
     * @brief updateFrame tells the view to update the drawing in the current Frame.
     */
    void updateFrame();

    /**
     * @brief chooseTool tells the view to show the user the selected tool
     * @param currentTool the current tool
     */
    void chooseTool(Tool currentTool);

    /**
     * @brief chooseColor tells the view that a new color has been assigned in the model,
     * and that it needs to update its RGB sliders.
     * @param currentColor
     */
    void chooseColor(QColor currentColor);

private:
    QMap<string, tool> tools;
    Tool currTool;
    QList<Frame> Frames;
    QColor backgroundColor;
    Frame* currentFrame;
};


#endif // MODEL_H
