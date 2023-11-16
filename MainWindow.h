/*
*Names: Hunter Keating, Hai Minh Pham, Thomas Kuhrke Limia, Andy Huo, Nam Nguyen, Emmanuel Luna
*Assignment: A8: Sprite Editor
*Description: This program make a sp
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Canvas.h"
#include "SpriteModel.h"
#include <QButtonGroup>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief The MainWindow class is the view for the Sprite Editor Project. It
 * lets the user draw in a canvas with a series of tools that can be selected
 * with buttons. On top of that, the user can select the color to draw with,
 * rescale the drawing canvas to multiple sizes, add frames, remove frames, and
 * play the frames at the desired framerate. As a bonus it also lets the user
 * save and load its progress.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  /**
   * @brief MainWindow constructor.
   * @param model a model object.
   * @param canvas a canvas object.
   * @param parent a QWidgent pointer.
   */
  MainWindow(SpriteModel &model, Canvas &canvas, QWidget *parent = nullptr);
  ~MainWindow();

public slots:
  /**
   * @brief onSlidersValueChanged handles the event when one of the RGB sliders
   * is changed.
   */
  void onSlidersValueChanged();

  /**
   * @brief changeColorPreview changes the current color being displayed in our
   * preview box.
   * @param red the red value in RGB.
   * @param green the green value in RGB.
   * @param blue the blue value in RGB.
   */
  void changeColorPreview(int red, int green, int blue);

  /**
   * @brief cursorToggled handles the event when the cursor tool is selected.
   */
  void cursorToggled();

  /**
   * @brief pencilToggled handles the event when the pencil tool is selected.
   */
  void pencilToggled();

  /**
   * @brief eraserToggled handles the event when the eraser tool is selected.
   */
  void eraserToggled();

  /**
   * @brief bucketToggled handles the event when the bucket tool is selected.
   */
  void bucketToggled();

  /**
   * @brief eyeDropperToggled handles the event when the eydropper tool is
   * selected.
   */
  void eyeDropperToggled();

  /**
   * @brief applyRedFilter sends the signal to apply the red filter.
   */
  void applyRedFilter();

  /**
   * @brief applyGreenFilter sends the singal to apply the green filter.
   */
  void applyGreenFilter();

  /**
   * @brief applyBlueFilter sends the signal to apply the blue filter.
   */
  void applyBlueFilter();

  /**
   * @brief applyGreyFilter sends the signal to apply the grey filter.
   */
  void applyGreyFilter();

  /**
   * @brief saveToggled toggles the save button between enabled and disabled.
   */
  void saveToggled();

  /**
   * @brief loadToggled toggles the load button between enabled and disabled.
   */
  void loadToggled();

  /**
   * @brief disablePreviousButton disables the previous frame button.
   */
  void disablePreviousButton();

  /**
   * @brief disableNextButton disables the next frame button.
   */
  void disableNextButton();

  /**
   * @brief changeSlidersColor handles the event for changing the color sliders.
   * @param color the color to be changed to.
   */
  void changeSlidersColor(QColor color);

  /**
   * @brief four change the size of the canvas to four.
   */
  void four();

  /**
   * @brief eight change the size of the canvas to eight.
   */
  void eight();
  /**
   * @brief sixteen change the size of the canvas to sixteen.
   */
  void sixteen();

  /**
   * @brief thirtyTwo change the size of the canvas to thirtytwo.
   */
  void thirtyTwo();

  /**
   * @brief sixtyFour change the size of the canvas to sixtyfour.
   */
  void sixtyFour();

  /**
   * @brief show boxes of available canvas sizes.
   */
  void showBoxes();

  /**
   * @brief hide boxes of available canvas sizes.
   */
  void hideBoxes();

  /**
   * @brief onFPSValueChanged method that triggers when the FPS slider changes,
   * emitting a signal to the model with the new FPS value.
   */
  void onFPSValueChanged();

  /**
   * @brief onRequestSaveFilePath prompt the user where to save the file to.
   */
  void onRequestSaveFilePath();

  /**
   * @brief onRequestLoadFilePath prompt the user where to load the file from.
   */
  void onRequestLoadFilePath();

signals:
  /**
   * @brief changeModelCurrentColor change the current selected color.
   * @param red red value.
   * @param green green value.
   * @param blue blue value.
   */
  void changeModelCurrentColor(int red, int green, int blue);

  /**
   * @brief changeTool change the current selected tool.
   * @param toolName the tool to be changed to.
   */
  void changeTool(QString toolName);

  /**
   * @brief sends a save signal to the model.
   */
  void save();

  /**
   * @brief sends a load signal to the model.
   */
  void load();

  /**
   * @brief getSize send the size of the new canvas.
   * @param size the new size.
   */
  void getSize(QSize size);
  /**
   * @brief red send the red filter signal.
   */
  void red();

  /**
   * @brief blue send the blue filter signal.
   */
  void blue();

  /**
   * @brief green send the green filter signal.
   */
  void green();

  /**
   * @brief grey send the grey filter signal.
   */
  void grey();

  /**
   * @brief changeFPS change the playback speed.
   * @param fps the speed to play the frames.
   */
  void changeFPS(int fps);

  /**
   * @brief performSave save the Project.
   * @param fileName the name of the file.
   */
  void performSave(QString fileName);

  /**
   * @brief performLoad load the Project.
   * @param fileName the name of the file.
   */
  void performLoad(QString fileName);

private:
  // The UI for this MainWindow
  Ui::MainWindow *ui;

  /**
   * @brief loadStyleSheet set the StyleSheet.
   */
  void loadStyleSheet();

  /**
   * @brief initCanvas set the drawing canvas.
   */
  void initCanvas();

  /**
   * @brief initPreviews set the preview animation playback frame.
   */
  void initPreviews();

  /**
   * @brief initSliders set the sliders.
   */
  void initSliders();
  /**
   * @brief SetIcons sets the various icons in our buttons.
   */
  void SetIcons();

  /**
   * @brief SetFileTab set the Save/Load buttons.
   */
  void SetFileButton();

  /**
   * @brief initSizeButtons set the canvas resize buttons.
   */
  void initSizeButtons();

  /**
   * @brief SetFileTab sets the file tab.
   */
  void SetFileTab();
};
#endif // MAINWINDOW_H
