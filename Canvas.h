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

protected:
  virtual void mousePressEvent(QMouseEvent *event) override;
  virtual void mouseReleaseEvent(QMouseEvent *event) override;
  virtual void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // CANVAS_H
