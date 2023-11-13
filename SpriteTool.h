#ifndef SPRITETOOL_H
#define SPRITETOOL_H

class SpriteTool {
public:
  SpriteTool();

protected:
  virtual void mousePressed();
  virtual void mouseReleased();
  virtual void mouseMoved();

  friend class SpriteModel;
};

#endif // SPRITETOOL_H
