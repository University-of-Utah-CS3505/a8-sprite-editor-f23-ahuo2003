#ifndef CANVAS_H
#define CANVAS_H
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <iostream>

class Canvas : public QLabel {
  Q_OBJECT
public:
  Canvas(QWidget *parent = nullptr);

signals:
  void mouseEventSignal(QMouseEvent *event);
public slots:
  void redrawCanvas(QImage frame);
  void updateCanvasScaleFactor(int scaleFactor);

protected:
  virtual void mousePressEvent(QMouseEvent *event) override;
  virtual void mouseReleaseEvent(QMouseEvent *event) override;
  virtual void mouseMoveEvent(QMouseEvent *event) override;
  void drawGrid(QPixmap &pixmap);
  friend class MainWindow;

private:
  int scaleFactor;
};

#endif // CANVAS_H
