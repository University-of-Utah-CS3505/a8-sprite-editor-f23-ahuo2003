/*This was checked by Andy Huo*/
#ifndef SPRITEPLAYER_H
#define SPRITEPLAYER_H

#include "Canvas.h"
/**
 * @brief The SpritePlayer class is a child from the Canvas class used for
 * playing a series of QImages in order with a delay between them.
 */
class SpritePlayer : public Canvas {
  Q_OBJECT
public:
  /**
   * @brief SpritePlayer constructor.
   * @param parent a QWidget pointer.
   */
  explicit SpritePlayer(QWidget *parent = nullptr);
  /**
   * @brief redrawCanvas changes the previous QImage with the one given, and
   * shows it in the MainWindow.
   * @param frame the new frame to show.
   */
  void redrawCanvas(QImage frame) override;
};

#endif // SPRITEPLAYER_H
