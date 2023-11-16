#include "SpritePlayer.h"

SpritePlayer::SpritePlayer(QWidget *parent) : Canvas(parent) {}

void SpritePlayer::redrawCanvas(QImage frame) {
  QPixmap pixmap = QPixmap::fromImage(frame);
  setPixmap(pixmap);
}
