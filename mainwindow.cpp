#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SpriteModel.h"
#include "Canvas.h"
#include "scalecanvas.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QFileDialog>


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

    // Set Icon for the tools and filters
    SetIcons();

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
    QPixmap whiteColorPreview(ui->colorPreview->size());
    whiteColorPreview.fill(myColor);
    ui->colorPreview->setPixmap(whiteColorPreview);
}

void MainWindow::pencilToggled()
{
    ui->pencilTool->setChecked(true);
    ui->eraserTool->setChecked(false);
    ui->bucketTool->setChecked(false);
    ui->eyeDropperTool->setChecked(false);
}

void MainWindow::eraserToggled(){
    ui->pencilTool->setChecked(false);
    ui->eraserTool->setChecked(true);
    ui->bucketTool->setChecked(false);
    ui->eyeDropperTool->setChecked(false);
}

void MainWindow::bucketToggled(){
    ui->pencilTool->setChecked(false);
    ui->eraserTool->setChecked(false);
    ui->bucketTool->setChecked(true);
    ui->eyeDropperTool->setChecked(false);
}

void MainWindow::eyeDropperToggled(){
    ui->pencilTool->setChecked(false);
    ui->eraserTool->setChecked(false);
    ui->bucketTool->setChecked(false);
    ui->eyeDropperTool->setChecked(true);
}

void MainWindow::SetIcons()
{
    ui->pencilTool->setIcon(QIcon(":/stylesheet/res/icons/Pencil.png"));
    ui->pencilTool->setIconSize(QSize(20, 20));
    ui->pencilTool->setCheckable(true);
    ui->pencilTool->setChecked(true);
    connect(ui->pencilTool, &QToolButton::clicked, this, &MainWindow::pencilToggled);

    ui->eraserTool->setIcon(QIcon(":/stylesheet/res/icons/Eraser.png"));
    ui->eraserTool->setIconSize(QSize(20, 20));
    ui->eraserTool->setCheckable(true);
    connect(ui->eraserTool, &QToolButton::clicked, this, &MainWindow::eraserToggled);

    ui->eyeDropperTool->setIcon(QIcon(":/stylesheet/res/icons/Eyedropper.png"));
    ui->eyeDropperTool->setIconSize(QSize(20, 20));
    ui->eyeDropperTool->setCheckable(true);
    connect(ui->eyeDropperTool, &QToolButton::clicked, this, &MainWindow::eyeDropperToggled);

    ui->bucketTool->setIcon(QIcon(":/stylesheet/res/icons/BucketIcon.png"));
    ui->bucketTool->setIconSize(QSize(20, 20));
    ui->bucketTool->setCheckable(true);
    connect(ui->bucketTool, &QToolButton::clicked, this, &MainWindow::bucketToggled);

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

void MainWindow::saveProject(const QString& filePath)
{
    // Create a JSON object to represent the project
    QJsonObject project;

    // Add project-specific information to the JSON object
    project["projectName"] = "Your Project Name";
    project["frameCount"] = 1;  // Assuming 1 frame for simplicity, adjust as needed

    // Create a JSON array to represent the frames
    QJsonArray frames;

    // Assuming 'pixmap' is a QPixmap representing your image
    // Convert the image to a JSON array of pixel values
    QJsonArray pixelData;
//    for (int y = 0; y < pixmap.height(); ++y) {
//        for (int x = 0; x < pixmap.width(); ++x) {
//            QColor pixelColor = pixmap.toImage().pixelColor(x, y);
//            QJsonObject pixel;
//            pixel["red"] = pixelColor.red();
//            pixel["green"] = pixelColor.green();
//            pixel["blue"] = pixelColor.blue();
//            pixel["alpha"] = pixelColor.alpha();
//            pixelData.append(pixel);
//        }
//    }

    // Create a frame object with the pixel data
    QJsonObject frame;
    //frame["width"] = pixmap.width();
    //frame["height"] = pixmap.height();
    frame["pixels"] = pixelData;

    // Add the frame to the frames array
    frames.append(frame);

    // Add the frames array to the project
    project["frames"] = frames;

    // Convert the JSON object to a JSON document
    QJsonDocument jsonDoc(project);

    // Save the JSON document to a file with .ssp extension
    QString savePath = filePath.isEmpty() ?
                           QFileDialog::getSaveFileName(this, "Save Project", "", "Sprite Sheet Project (*.ssp)") :
                           filePath;

    if (!savePath.isEmpty()) {
        QFile saveFile(savePath);
        if (saveFile.open(QFile::WriteOnly | QFile::Text)) {
            saveFile.write(jsonDoc.toJson());
            saveFile.close();
        } else {
            qDebug() << "Failed to save project.";
        }
    } else {
        qDebug() << "Save operation canceled.";
    }
}

void MainWindow::loadProject(const QString& filePath)
{
    // Load the JSON document from the file
    QFile loadFile(filePath);

    QJsonDocument jsonDoc = QJsonDocument::fromJson(loadFile.readAll());
    loadFile.close();

    // Parse the JSON document and retrieve project information
    QJsonObject project = jsonDoc.object();

    QString projectName = project["projectName"].toString();
    int frameCount = project["frameCount"].toInt();

    // Retrieve frame information
    QJsonArray frames = project["frames"].toArray();

    // Process each frame
    for (int i = 0; i < frameCount; ++i) {
        QJsonObject frame = frames[i].toObject();

        int width = frame["width"].toInt();
        int height = frame["height"].toInt();

        // Retrieve pixel data
        QJsonArray pixelData = frame["pixels"].toArray();

        // Create a QImage and set pixel values
        QImage image(width, height, QImage::Format_ARGB32);
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                QJsonObject pixel = pixelData[y * width + x].toObject();
                int red = pixel["red"].toInt();
                int green = pixel["green"].toInt();
                int blue = pixel["blue"].toInt();
                int alpha = pixel["alpha"].toInt();

                image.setPixelColor(x, y, QColor(red, green, blue, alpha));
            }
        }

        // Use the QImage 'image' for further processing
    }
}
