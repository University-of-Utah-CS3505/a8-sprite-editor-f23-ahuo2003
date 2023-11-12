#ifndef SPRITETOOL_H
#define SPRITETOOL_H
#include <QMouseEvent>

class SpriteTool{
    public:
        SpriteTool();
        virtual void onMousePress(QMouseEvent *event);
        virtual void onMouseRelease(QMouseEvent *event);
        virtual void onMouseMove(QMouseEvent *event);
};

#endif // SPRITETOOL_H
