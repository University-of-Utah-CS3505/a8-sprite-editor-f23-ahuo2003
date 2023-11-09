#ifndef TOOL_H
#define TOOL_H
#include <QString>
#include <QObject>

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
    explicit Tool(QObject *parent = nullptr, QString name = NULL);

public slots:
    /**
     * @brief onMousePress does an action when the mouse is pressed.
     */
    void virtual onMousePress();

    /**
     * @brief onMouseRelease does an action when the mouse is released.
     */
    void virtual onMouseRelease();

    /**
     * @brief onMouseMove does an action when the mouse moves.
     */
    void virtual onMouseMove();

signals:
    /**
     * @brief unselectTools tells the view to unselect all tools selected.
     */
    void unselectTools();

    /**
     * @brief selectTool tells the view to select a tool and show the user which tool is selected.
     * @param toolName name of the tool selected.
     */
    void selectTool(std::string toolName);

protected:
    QString name;
};
#endif // TOOL_H
