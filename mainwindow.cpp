#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap drawOn(400, 400);
    QPixmap colorPreview(40,40);
    QPixmap spritePreview(40,40);

    spritePreview.fill(Qt::black);
    drawOn.fill(Qt::red);
    colorPreview.fill(Qt::black);

    ui->Canvas->setPixmap(drawOn);
    ui->ColorPreview->setPixmap(colorPreview);
    ui->SpritePreview->setPixmap(spritePreview);

    // Default window size of 1280x720 and a minimum size of 800x600
    setMinimumSize(800,600);
    resize(1280,720);
}

MainWindow::~MainWindow()
{
    delete ui;
}

