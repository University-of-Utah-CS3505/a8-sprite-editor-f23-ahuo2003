#ifndef FRAME_H
#define FRAME_H
#include <QList>
#include <QPixMap>

/**
 * @authors Names:
 * @authors GitHubs:
 *
 * @title Assignment 8: Sprite Editor Implementation
 *
 * @brief The Frame class ...
 */
class Frame : public QObject {
    Q_OBJECT
public:
    /**
     * @brief Frame constructor
     * @param parent a QObject
     */
    explicit Frame(QObject *parent = nullptr);


public slots:
    /**
     * @brief nextVersion moves pointer backward if possible.
     */
    nextVersion();

    /**
     * @brief previousVersion moves pointer forward if possible.
     */
    previousVersion();

protected:
    QList<QPixmap> versions;
    QPixmap* currentVersion;
};

#endif // FRAME_H
