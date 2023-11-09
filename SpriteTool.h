#ifndef SPRITETOOL_H
#define SPRITETOOL_H
#include <QString>

class SpriteTool{
    public:
        SpriteTool();
        virtual void onMousePress();
        virtual void onMouseRelease();
        virtual void onMouseMove();
};

class Pencil : SpriteTool{
    public:
        Pencil();
        virtual void onMousePress();
        virtual void onMouseRelease();
        virtual void onMouseMove();
};
#endif // SPRITETOOL_H
