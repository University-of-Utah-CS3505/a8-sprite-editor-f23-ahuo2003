#include "SpriteTool.h"


// General Tool Here
SpriteTool::SpriteTool(){}

void SpriteTool::onMousePress()
{
    //Do something
}

void SpriteTool::onMouseRelease()
{
    //Do something
}

void SpriteTool::onMouseMove()
{
    //Do something
}

// Pencil Here
Pencil::Pencil() : SpriteTool(){}

void Pencil::onMousePress()
{
    //Do something
}

void Pencil::onMouseRelease()
{
    //Do something
}

void Pencil::onMouseMove()
{
    //Do something
}

Bucket::Bucket() : SpriteTool(){}
void Bucket::onMousePress() {}
void Bucket::onMouseRelease() {}
void Bucket::onMouseMove() {}

Eyedropper::Eyedropper() : SpriteTool(){}
void Eyedropper::onMousePress() {}
void Eyedropper::onMouseRelease() {}
void Eyedropper::onMouseMove() {}

Eraser::Eraser() : SpriteTool(){}
void Eraser::onMousePress() {}
void Eraser::onMouseRelease() {}
void Eraser::onMouseMove() {}

Filter::Filter() : SpriteTool(){}
void Filter::onMousePress() {}
void Filter::onMouseRelease() {}
void Filter::onMouseMove() {}
