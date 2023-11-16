/*
 *Names: Hunter Keating, Hai Minh Pham, Thomas Kuhrke Limia, Andy Huo, Nam Nguyen, Emmanuel Luna
 *Assignment: A8: Sprite Editor
 *Description: This program is a sprite editor, anywhere from 4x4 to 64x64 pixel size.
 *An animation can be made with multiple frames, rendered at 1-24 frames per second.
 *Filter options allow for easy customization.
 */
#include "Canvas.h"
#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  SpriteModel model;
  Canvas canvas;
  MainWindow w(model, canvas);
  w.show();
  return a.exec();
}
