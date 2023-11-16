/*This was checked by Hai Minh Pham*/
#ifndef CURSOR_H
#define CURSOR_H

#include "SpriteTool.h"

/**
 * @brief The Cursor class represents a cursor, which means it doesn't do
 * anything when clicking in the canvas.
 */
class Cursor : public SpriteTool {
public:
  /**
   * @brief Cursor constructor.
   */
  Cursor();

protected:
  /**
   * @brief mousePressed a method that executes when the user mouse is pressed.
   */
  virtual void mousePressed();
  /**
   * @brief mouseReleased a method that executes when the user mouse is
   * released.
   */
  virtual void mouseReleased();
  /**
   * @brief mouseMoved a method that executes when the user mouse is moved while
   * being pressed.
   */
  virtual void mouseMoved();
};

#endif // CURSOR_H
