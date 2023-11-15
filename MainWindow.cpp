#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "SpriteModel.h"
#include "Canvas.h"
#include "ScaleCanvas.h"


void MainWindow::loadStyleSheet()
{
    QFile stylesheetFile(":/stylesheet/res/stylesheet/stylesheet.qss");
    stylesheetFile.open(QFile::ReadOnly);
    QString style(stylesheetFile.readAll());
    this->setStyleSheet(style);
}

void MainWindow::initCanvas()
{
    QImage canvas(8, 8, QImage::Format_ARGB32);
    canvas.fill(Qt::transparent);
    ui->drawingCanvas->redrawCanvas(canvas);
}

void MainWindow::initPreviews()
{
    QPixmap blackColorPreview(ui->colorPreview->size());
    QPixmap animationPrev(ui->animationPreview->size());
    animationPrev.fill(Qt::white);
    blackColorPreview.fill(Qt::black);

    //Set the preview
    ui->animationPreview->setPixmap(animationPrev);
    ui->colorPreview->setPixmap(blackColorPreview);
}

void MainWindow::initSliders()
{
    ui->redSlider  ->setRange(0,255);
    ui->greenSlider->setRange(0,255);
    ui->blueSlider ->setRange(0,255);
}

MainWindow::MainWindow(SpriteModel& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Default window size of 1280x720 (non-resizable)
    this->setFixedSize(1280,720);

    // Setup global stylesheet using qss file
    loadStyleSheet();

    initPreviews();

    //Draw the canvas
    initCanvas();

    // Set Icon for the tools and filters
    SetIcons();

    // Set sliders Range to match RGB's range of values.
    initSliders();

    //Canvas-to-Tools connection
    connect(ui->drawingCanvas, &Canvas::mouseEventSignal, &model, &SpriteModel::useTool);
    connect(&model, &SpriteModel::updateFrame, ui->drawingCanvas, &Canvas::redrawCanvas);
    connect(&model, &SpriteModel::updateScaleFactor, ui->drawingCanvas, &Canvas::updateCanvasScaleFactor);

    //Slider Connections
    connect(ui->redSlider  , &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);
    connect(ui->greenSlider, &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);
    connect(ui->blueSlider , &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);
    connect(this, &MainWindow::changeModelCurrentColor, &model, &SpriteModel::changeColor);
    connect(this, &MainWindow::changeTool, &model, &SpriteModel::changeTool);
    connect(&model, &SpriteModel::chooseColor, this, &MainWindow::changeSlidersColor);

    //Dialog Box Connection
    connect(ui->canvasSize, &QPushButton::clicked, this, &MainWindow::setCanvasSize);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCanvasSize(){
    ScaleCanvas canvasSize;
    canvasSize.setModal(true);
    canvasSize.exec();
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
    QPixmap blackColorPreview(ui->colorPreview->size());
    blackColorPreview.fill(myColor);
    ui->colorPreview->setPixmap(blackColorPreview);
}

void MainWindow::cursorToggled()
{
    ui->cursorTool->setChecked(true);
    ui->pencilTool->setChecked(false);
    ui->eraserTool->setChecked(false);
    ui->bucketTool->setChecked(false);
    ui->eyeDropperTool->setChecked(false);
    emit changeTool("Cursor");

}

void MainWindow::pencilToggled()
{
    ui->cursorTool->setChecked(false);
    ui->pencilTool->setChecked(true);
    ui->eraserTool->setChecked(false);
    ui->bucketTool->setChecked(false);
    ui->eyeDropperTool->setChecked(false);
    emit changeTool("Pencil");
}

void MainWindow::eraserToggled(){
    ui->cursorTool->setChecked(false);
    ui->pencilTool->setChecked(false);
    ui->eraserTool->setChecked(true);
    ui->bucketTool->setChecked(false);
    ui->eyeDropperTool->setChecked(false);
    emit changeTool("Eraser");
}

void MainWindow::bucketToggled(){
    ui->cursorTool->setChecked(false);
    ui->pencilTool->setChecked(false);
    ui->eraserTool->setChecked(false);
    ui->bucketTool->setChecked(true);
    ui->eyeDropperTool->setChecked(false);
    emit changeTool("Bucket");
}

void MainWindow::eyeDropperToggled(){
    ui->cursorTool->setChecked(false);
    ui->pencilTool->setChecked(false);
    ui->eraserTool->setChecked(false);
    ui->bucketTool->setChecked(false);
    ui->eyeDropperTool->setChecked(true);
    emit changeTool("Eyedropper");
}

void MainWindow::changeSlidersColor(QColor color)
{
    QPixmap blackColorPreview(ui->colorPreview->size());
    blackColorPreview.fill(color);
    ui->colorPreview->setPixmap(blackColorPreview);
    ui->redSlider->setValue(color.red());
    ui->greenSlider->setValue(color.green());
    ui->blueSlider->setValue(color.blue());
}

void MainWindow::SetIcons()
{
    //Cursor tool icon
    ui->cursorTool->setIcon(QIcon(":/stylesheet/res/icons/Cursor.png"));
    ui->cursorTool->setIconSize(QSize(20, 20));
    ui->cursorTool->setChecked(true);
    connect(ui->cursorTool, &QToolButton::clicked, this, &MainWindow::cursorToggled);

    //Pencil Tool icon
    ui->pencilTool->setIcon(QIcon(":/stylesheet/res/icons/Pencil.png"));
    ui->pencilTool->setIconSize(QSize(20, 20));
    connect(ui->pencilTool, &QToolButton::clicked, this, &MainWindow::pencilToggled);

    //Eraser tool icon
    ui->eraserTool->setIcon(QIcon(":/stylesheet/res/icons/Eraser.png"));
    ui->eraserTool->setIconSize(QSize(20, 20));
    connect(ui->eraserTool, &QToolButton::clicked, this, &MainWindow::eraserToggled);

    //Eyedropper tool icon
    ui->eyeDropperTool->setIcon(QIcon(":/stylesheet/res/icons/Eyedropper.png"));
    ui->eyeDropperTool->setIconSize(QSize(20, 20));
    connect(ui->eyeDropperTool, &QToolButton::clicked, this, &MainWindow::eyeDropperToggled);

    //Bucket tool Icon
    ui->bucketTool->setIcon(QIcon(":/stylesheet/res/icons/BucketIcon.png"));
    ui->bucketTool->setIconSize(QSize(20, 20));
    connect(ui->bucketTool, &QToolButton::clicked, this, &MainWindow::bucketToggled);

    //Filter icons
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
}
