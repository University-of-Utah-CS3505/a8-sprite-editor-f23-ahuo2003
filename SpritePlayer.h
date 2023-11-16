#ifndef SPRITEPLAYER_H
#define SPRITEPLAYER_H

#include "Canvas.h"

class SpritePlayer : public Canvas {
  Q_OBJECT
public:
  explicit SpritePlayer(QWidget *parent = nullptr);
  void redrawCanvas(QImage frame) override;
};

#endif // SPRITEPLAYER_H
