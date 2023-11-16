#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Canvas.h"
#include "SpriteModel.h"
#include <QButtonGroup>
#include <QFile>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(SpriteModel &model, Canvas &canvas, QWidget *parent = nullptr);
    ~MainWindow();

    /**
   * @brief SetIcons sets the various icons in our buttons
   */
    void SetIcons();

    void SetFileTab();

    void initSizeButtons();

public slots:
    /**
   * @brief onSlidersValueChanged handles the event when one of the RGB sliders
   * is changed
   */
    void onSlidersValueChanged();

    /**
   * @brief changeColorPreview changes the current color being displayed in our
   * preview box
   * @param red the red value in RGB
   * @param green the green value in RGB
   * @param blue the blue value in RGB
   */
    void changeColorPreview(int red, int green, int blue);

    /**
   * @brief cursorToggled handles the event when the cursor tool is selected
   */
    void cursorToggled();

    /**
   * @brief pencilToggled handles the event when the pencil tool is selected
   */
    void pencilToggled();

    /**
   * @brief eraserToggled handles the event when the eraser tool is selected
   */
    void eraserToggled();

    /**
   * @brief bucketToggled handles the event when the bucket tool is selected
   */
    void bucketToggled();

    /**
   * @brief eyeDropperToggled handles the event when the eydropper tool is
   * selected
   */
    void eyeDropperToggled();

    void saveToggled();
    void loadToggled();

    /**
   * @brief changeSlidersColor handles the event for changing the color sliders
   * @param color the color to be changed to
   */
    void changeSlidersColor(QColor color);

    /**
   * @brief four change the size of the canvas to four
   */
    void four();

    /**
   * @brief eight change the size of the canvas to eight
   */
    void eight();
    /**
   * @brief sixteen change the size of the canvas to sixteen
   */
    void sixteen();

    /**
   * @brief thirtyTwo change the size of the canvas to thirtytwo
   */
    void thirtyTwo();

    /**
   * @brief sixtyFour change the size of the canvas to sixtyfour
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

signals:
    /**
   * @brief changeModelCurrentColor change the current selected color
   * @param red red value
   * @param green green value
   * @param blue blue value
   */
    void changeModelCurrentColor(int red, int green, int blue);

    /**
   * @brief changeTool change the current selected tool
   * @param toolName the tool to be changed to
   */
    void changeTool(QString toolName);

    void save();
    void load();

    /**
   * @brief getSize send the size of the new canvas
   * @param size the new size
   */
    void getSize(QSize size);

private:
    // The UI for this MainWindow
    Ui::MainWindow *ui;

    /**
   * @brief loadStyleSheet set the StyleSheet
   */
    void loadStyleSheet();

    /**
   * @brief initCanvas set the drawing canvas
   */
    void initCanvas();

    /**
   * @brief initPreviews set the preview canvas
   */
    void initPreviews();

    /**
   * @brief initSliders set the sliders
   */
    void initSliders();
};
#endif // MAINWINDOW_H
