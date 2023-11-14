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
    whiteCanvas.fill(Qt::transparent);


    ui->animationPreview->setPixmap(animationPrev);
    ui->drawingCanvas->setPixmap(whiteCanvas);
    ui->colorPreview->setPixmap(whiteColorPreview);

    // Set Icon for the tools
    ui->pencilTool->setIcon(QIcon(":/stylesheet/res/icons/Pencil.png"));
    ui->pencilTool->setIconSize(QSize(20, 20));
    ui->eraserTool->setIcon(QIcon(":/stylesheet/res/icons/Eraser.png"));
    ui->eraserTool->setIconSize(QSize(20, 20));
    ui->eyeDropperTool->setIcon(QIcon(":/stylesheet/res/icons/Eyedropper.png"));
    ui->eyeDropperTool->setIconSize(QSize(20, 20));
    ui->bucketTool->setIcon(QIcon(":/stylesheet/res/icons/BucketIcon.png"));
    ui->bucketTool->setIconSize(QSize(20, 20));
    ui->filterRed->setIcon(QIcon(":/stylesheet/res/icons/RedFilter.png"));
    ui->filterRed->setIconSize(QSize(20, 20));
    ui->filterGreen->setIcon(QIcon(":/stylesheet/res/icons/GreenFilter.png"));
    ui->filterGreen->setIconSize(QSize(20, 20));
    ui->filterBlue->setIcon(QIcon(":/stylesheet/res/icons/BlueFilter.png"));
    ui->filterBlue->setIconSize(QSize(20, 20));
    ui->filterGrey->setIcon(QIcon(":/stylesheet/res/icons/GreyFilter.png"));
    ui->filterGrey->setIconSize(QSize(20, 20));
    ui->playButton->setIcon(QIcon(":/stylesheet/res/icons/Play.png"));
    ui->playButton->setIconSize(QSize(30, 30));
    ui->stopButton->setIcon(QIcon(":/stylesheet/res/icons/Pause.png"));
    ui->stopButton->setIconSize(QSize(30, 30));

    // Set sliders Range to match RGB's range of values.
    ui->redSlider  ->setRange(0,255);
    ui->greenSlider->setRange(0,255);
    ui->blueSlider ->setRange(0,255);

    ui->drawingCanvas->setStyleSheet("border: 1px solid black");
    //Canvas-to-Tools connection
    connect(ui->drawingCanvas, &Canvas::mouseEventSignal, &model, &SpriteModel::useTool);
    connect(&model, &SpriteModel::updateFrame, ui->drawingCanvas, &Canvas::redrawCanvas);

    //Slider Connections
    connect(ui->redSlider  , &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);
    connect(ui->greenSlider, &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);
    connect(ui->blueSlider , &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);
    connect(this, &MainWindow::changeModelCurrentColor, &model, &SpriteModel::changeColor);
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
    changeColorPreview(red, green, blue);
    emit changeModelCurrentColor(red,green,blue);
}

void MainWindow::changeColorPreview(int red, int green, int blue)
{
    QColor myColor = QColor(red, green, blue);
    QPixmap whiteColorPreview(ui->colorPreview->size());
    whiteColorPreview.fill(myColor);
    ui->colorPreview->setPixmap(whiteColorPreview);
}

