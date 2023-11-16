#ifndef SPRITETOOL_H
#define SPRITETOOL_H
#include <QColor>
#include <QImage>
#include <QMouseEvent>
#include <QString>

/**
 * @brief The SpriteTool class is a parent class that is used to create specific
 * tools that can modify an image through different methods.
 */
class SpriteTool {
public:
  /**
   * @brief SpriteTool constructor.
   */
  SpriteTool();

  /**
   * @brief getName getter for the name variable.
   * @return the name of the tool.
   */
  QString getName() const;

protected:
  QString name;
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

  /**
   * @brief mapToImageCoordinates multiplies coordinates from the main window
   * canvas with a constant to convert them from MainWindow Canvas coordinates
   * to QImage Model coordinates.
   * @param point a location from the MainWindow Canvas.
   * @param scaleFactor a number used for scaling.
   * @return valid coordinates for the Model's QImage.
   */
  QPoint mapToImageCoordinates(const QPoint &point, int scaleFactor);

  friend class SpriteModel;
};

#endif // SPRITETOOL_H
