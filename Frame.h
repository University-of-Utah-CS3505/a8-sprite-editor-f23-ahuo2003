#ifndef FRAME_H
#define FRAME_H
#include <QImage>
#include <QList>
#include <QListIterator>


class Frame
{
public:
    Frame(QSize size);
    QImage getCurrentFrame() const;
    void nextVersion(QImage& newVersion);
    void previousVersion();
protected:
    void addNewVersion(QImage& newVersion);
    void removeOldestVersion();

private:
    QImage currFrame;
    QList<QImage> versions;
    QListIterator<QImage> currFrameIterator;
};

#endif // FRAME_H
