#ifndef PENCIL_H
#define PENCIL_H
#include "SpriteTool.h"
#include <QColor>
#include <QImage>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>

/**
 * @brief The Pencil class represents a tool that changes the colors of pixels
 * in an image given their location.
 */
class Pencil : public SpriteTool {
public:
  /**
   * @brief Pencil constructor.
   */
  Pencil();

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
  QPainter painter;
  QPoint startPoint, endPoint;
};

#endif // PENCIL_H
