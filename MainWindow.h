#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "SpriteModel.h"
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(SpriteModel& model, QWidget *parent = nullptr);
    ~MainWindow();
    
    void SetIcons();
    void saveProject(const QString& filePath);
    void loadProject(const QString& filePath);
    
public slots:
    void onSlidersValueChanged();
    void changeColorPreview(int red, int green, int blue);
    void pencilToggled();
    void eraserToggled();
    void bucketToggled();
    void eyeDropperToggled();
    void setCanvasSize();
signals:
    void changeModelCurrentColor(int red, int green, int blue);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H