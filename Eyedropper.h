/*This was checked by Nam Nguyen*/
#ifndef EYEDROPPER_H
#define EYEDROPPER_H
#include "SpriteTool.h"

/**
 * @brief The Eyedropper class represents a tool that retrieves the pixel of a
 * color from an image..
 */
class Eyedropper : public SpriteTool {
public:
  /**
   * @brief Eyedropper constructor.
   */
  Eyedropper();

  /**
   * @brief getPixelColor gets the color of a pixel at the desired position of
   * an image.
   * @param image an image.
   * @param pixelCoords the desired coordinates to retrieve the pixel color.
   * @return the color of the pixel as a QColor Object.
   */
  QColor getPixelColor(QImage &image, QPoint pixelCoords);

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

#endif // EYEDROPPER_H
