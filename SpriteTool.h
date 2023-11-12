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

class Bucket : SpriteTool{
    public:
        Bucket();
        virtual void onMousePress();
        virtual void onMouseRelease();
        virtual void onMouseMove();
};

class Eyedropper : SpriteTool{
    public:
        Eyedropper();
        virtual void onMousePress();
        virtual void onMouseRelease();
        virtual void onMouseMove();
};

class Eraser : SpriteTool{
    public:
        Eraser();
        virtual void onMousePress();
        virtual void onMouseRelease();
        virtual void onMouseMove();
};

class Filter : SpriteTool{
    public:
        Filter();
        virtual void onMousePress();
        virtual void onMouseRelease();
        virtual void onMouseMove();
};
#endif // SPRITETOOL_H
