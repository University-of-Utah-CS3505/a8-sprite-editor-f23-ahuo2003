#ifndef TOOL_H
#define TOOL_H
#include <QString>

class Tool : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Tool constructor
     * @param parent a QObject
     */
    explicit Tool(QObject *parent = nullptr, QString name);
    virtual onMousePress();
    virtual onMouseRelease();
    virtual onMouseMove();

signals:
    unselectTools();
    selectTool(string toolName);

protected:
    QString name;
};
#endif // TOOL_H
