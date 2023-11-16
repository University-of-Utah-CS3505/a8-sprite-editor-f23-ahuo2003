#ifndef ERASER_H
#define ERASER_H
#include "SpriteTool.h"

/**
 * @brief The Eraser class represents a tool that sets pixels to transparent
 * pixels at the desired location.
 */
class Eraser : public SpriteTool {
public:
  /**
   * @brief Eraser constructor.
   */
  Eraser();

protected:
  /**
   * @brief mousePressed a method that executes when the user mouse is pressed.
   * @param image an image.
   * @param currColor a color.
   * @param event mouse pressed event.
   * @param scaleFactor factor to scale the image.
   */
  virtual void mousePressed(QImage &image, QColor &currColor,
                            QMouseEvent *event, int scaleFactor);

  /**
   * @brief mouseReleased a method that executes when the user mouse is
   * released.
   */
  virtual void mouseReleased();

  /**
   * @brief mouseMoved a method that executes when the user mouse is moved while
   * pressed.
   * @param image an image.
   * @param currColor a color.
   * @param event mouse moved event (while pressed).
   * @param scaleFactor factor to scale the image.
   */
  virtual void mouseMoved(QImage &image, QColor &currColor, QMouseEvent *event,
                          int scaleFactor);

private:
  QPoint startPoint, endPoint;
};

#endif // ERASER_H
