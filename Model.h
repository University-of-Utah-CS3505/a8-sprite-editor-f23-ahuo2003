#ifndef MODEL_H
#define MODEL_H

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
    // TODO

signals:
    // TODO

private:
    // TODO

};


#endif // MODEL_H
