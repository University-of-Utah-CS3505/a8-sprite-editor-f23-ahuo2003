#ifndef CANVAS_H
#define CANVAS_H
#include <QLabel>
#include <QMouseEvent>

/**
 * @brief The Canvas class reprensents a drawing canvas by using a combination
 * of QPixmap and QImage.
 */
class Canvas : public QLabel {
  Q_OBJECT
public:
  /**
   * @brief Canvas constructor.
   * @param parent QWidget pointer.
   */
  Canvas(QWidget *parent = nullptr);

signals:
  /**
   * @brief mouseEventSignal sends a mouseEvent signal.
   * @param event the event signal.
   */
  void mouseEventSignal(QMouseEvent *event);
public slots:
  /**
   * @brief redrawCanvas redraws the canvas given a QImage.
   * @param frame the image to be drawn in the canvas.
   */
  virtual void redrawCanvas(QImage frame);

  /**
   * @brief updateCanvasScaleFactor updates the scaleFactor variable.
   * @param scaleFactor the new scaleFactor variable.
   */
  void updateCanvasScaleFactor(int scaleFactor);

protected:
  /**
   * @brief mousePressEvent a method that executes when the user mouse is
   * pressed.
   * @param event mouse pressed event.
   */
  virtual void mousePressEvent(QMouseEvent *event) override;
  /**
   * @brief mousePressEvent a method that executes when the user mouse is
   * released.
   * @param event mouse released event.
   */
  virtual void mouseReleaseEvent(QMouseEvent *event) override;
  /**
   * @brief mouseMoveEvent a method that executes when the user mouse is moved.
   * @param event mouse moved event.
   */
  virtual void mouseMoveEvent(QMouseEvent *event) override;
  /**
   * @brief drawGrid draws a Grid in the canvas to show the division of pixels.
   * @param pixmap the pixmap where the grid is drawn.
   */
  void drawGrid(QPixmap &pixmap);
  friend class MainWindow;

private:
  int scaleFactor;
};

#endif // CANVAS_H
