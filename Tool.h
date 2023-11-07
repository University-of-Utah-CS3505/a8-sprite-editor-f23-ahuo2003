#ifndef TOOL_H
#define TOOL_H
#include <QString>

/**
 * @authors Names:
 * @authors GitHubs:
 *
 * @title Assignment 8: Sprite Editor Implementation
 *
 * @brief The Tool class...
 */
class Tool : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Tool constructor
     * @param parent a QObject
     */
    explicit Tool(QObject *parent = nullptr, QString name);

public slots:
    /**
     * @brief onMousePress does an action when the mouse is pressed.
     */
    virtual onMousePress();

    /**
     * @brief onMouseRelease does an action when the mouse is released.
     */
    virtual onMouseRelease();

    /**
     * @brief onMouseMove does an action when the mouse moves.
     */
    virtual onMouseMove();

signals:
    /**
     * @brief unselectTools tells the view to unselect all tools selected.
     */
    unselectTools();

    /**
     * @brief selectTool tells the view to select a tool and show the user which tool is selected.
     * @param toolName name of the tool selected.
     */
    selectTool(string toolName);

protected:
    QString name;
};
#endif // TOOL_H
