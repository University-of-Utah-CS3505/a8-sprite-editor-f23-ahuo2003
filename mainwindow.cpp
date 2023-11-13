#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SpriteModel.h"
#include "Canvas.h"
MainWindow::MainWindow(SpriteModel& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Default window size of 1280x720 (non-resizable)
    this->setFixedSize(1280,720);

    // Setup global stylesheet using qss file
    QFile stylesheetFile(":/stylesheet/res/stylesheet/stylesheet.qss");
    stylesheetFile.open(QFile::ReadOnly);
    QString style(stylesheetFile.readAll());
    this->setStyleSheet(style);

    QPixmap whiteCanvas(ui->drawingCanvas->size());
    QPixmap whiteColorPreview(ui->colorPreview->size());
    QPixmap animationPrev(ui->animationPreview->size());
    animationPrev.fill(Qt::white);
    whiteColorPreview.fill(Qt::white);
    whiteCanvas.fill(Qt::white);


    ui->animationPreview->setPixmap(animationPrev);
    ui->drawingCanvas->setPixmap(whiteCanvas);
    ui->colorPreview->setPixmap(whiteColorPreview);

    // Set sliders Range to match RGB's range of values.
    ui->redSlider  ->setRange(0,255);
    ui->greenSlider->setRange(0,255);
    ui->blueSlider ->setRange(0,255);

    //Canvas *canvas = ui->drawingCanvas;
    //connect(canvas, canvas->mousePressEvent, this, );
    connect(ui->redSlider  , &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);
    connect(ui->greenSlider, &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);
    connect(ui->blueSlider , &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);

    connect(&model, SIGNAL(chooseColor(QColor)), ui->colorPreview, SLOT(changeColorPreview()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSlidersValueChanged()
{
    int red   = ui->redSlider  ->value();
    int green = ui->greenSlider->value();
    int blue  = ui->blueSlider ->value();

    //model.changeColor(red, green, blue);
}

void MainWindow::changeColorPreview()
{
    int red   = ui->redSlider  ->value();
    int green = ui->greenSlider->value();
    int blue  = ui->blueSlider ->value();
    QColor mycolor = QColor(red, green, blue);

    // Change the ColorPreview Label to the current Color.
    ui->colorPreview->setAutoFillBackground(true);
    QPalette palette = ui->colorPreview->palette();
    palette.setColor(QPalette::Base, mycolor);
    ui->colorPreview->setPalette(palette);
}

