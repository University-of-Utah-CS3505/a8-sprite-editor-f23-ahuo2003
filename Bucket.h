/*This was checked by Emmanuel Luna*/
#ifndef BUCKET_H
#define BUCKET_H
#include "SpriteTool.h"
#include <QColor>
#include <QImage>
#include <QMouseEvent>
#include <QPainter>
/**
 * @brief The Bucket class represents a tool that changes a pixel and its
 * neighbors to the desired color.
 */
class Bucket : public SpriteTool {
public:
  /**
   * @brief Bucket constructor method.
   */
  Bucket();
  /**
   * @brief floodFill changes the color of a selected pixel and its neighbors at
   * the desired location.
   * @param image an image.
   * @param pos position where the method is called.
   * @param startColor the color the pixel is holding before change.
   * @param newColor the color the pixel will be changed to.
   */
  virtual void floodFill(QImage &image, const QPoint &pos,
                         const QColor &startColor, const QColor &newColor);

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
};

#endif // BUCKET_H
