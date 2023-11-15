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
