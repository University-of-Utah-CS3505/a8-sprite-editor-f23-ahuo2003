#ifndef CANVAS_H
#define CANVAS_H
#include <QLabel>
#include <QMouseEvent>

class Canvas : public QLabel {
  Q_OBJECT
public:
  Canvas(QWidget *parent = nullptr);

signals:
  void mouseEventSignal(QMouseEvent *event);
public slots:
  void redrawCanvas(QImage frame);

protected:
  virtual void mousePressEvent(QMouseEvent *event) override;
  virtual void mouseReleaseEvent(QMouseEvent *event) override;
  virtual void mouseMoveEvent(QMouseEvent *event) override;

  private:
  void drawGrid(QPixmap &pixmap);
  QPoint mapToImageCoords(const QPoint &point);
  int scaleFactor;
};

#endif // CANVAS_H
