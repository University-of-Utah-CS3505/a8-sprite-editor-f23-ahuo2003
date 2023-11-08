#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Default window size of 1280x720 and a minimum size of 800x600
    setMinimumSize(800,600);
    resize(1280,720);
}

MainWindow::~MainWindow()
{
    delete ui;
}

