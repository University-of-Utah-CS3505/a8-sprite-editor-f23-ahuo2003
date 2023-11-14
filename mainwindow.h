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
    
public slots:
    void onSlidersValueChanged();
    void changeColorPreview(int red, int green, int blue);
private slots:
    void pencilToggled();
    void eraserToggled();
    void bucketToggled();
    void eyeDropperToggled();
signals:
    void changeModelCurrentColor(int red, int green, int blue);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
