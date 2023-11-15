#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "SpriteModel.h"
#include <QButtonGroup>
#include "Canvas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(SpriteModel& model, Canvas& canvas, QWidget *parent = nullptr);
    ~MainWindow();

    void SetIcons();

public slots:
    void onSlidersValueChanged();
    void changeColorPreview(int red, int green, int blue);
    void cursorToggled();
    void pencilToggled();
    void eraserToggled();
    void bucketToggled();
    void eyeDropperToggled();
    void changeSlidersColor(QColor color);
    void setCanvasSize();
    void four();
    void eight();
    void sixteen();
    void thirtyTwo();
    void sixtyFour();
signals:
    void changeModelCurrentColor(int red, int green, int blue);
    void changeTool(QString toolName);
    void getSize(QSize size);

private:
    Ui::MainWindow *ui;
    void loadStyleSheet();
    void initCanvas();
    void initPreviews();
    void initSliders();
};
#endif // MAINWINDOW_H
