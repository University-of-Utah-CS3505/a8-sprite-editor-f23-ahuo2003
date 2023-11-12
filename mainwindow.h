#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "SpriteModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(SpriteModel& model, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onSlidersValueChanged();
    void changeColorPreview();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
