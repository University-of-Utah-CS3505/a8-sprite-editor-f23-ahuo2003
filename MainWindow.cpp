#include "MainWindow.h"
#include "Canvas.h"
#include "SpriteModel.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(SpriteModel &model, Canvas &canvas, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->fpsSlider->setRange(1, 24);

    // Default window size of 1280x720 (non-resizable)
    this->setFixedSize(1280, 720);

    // Setup global stylesheet using qss file
    loadStyleSheet();

    // Set visible of size buttons.
    initSizeButtons();

    // Initialize canvas.
    initPreviews();

    // Draw the canvas
    initCanvas();

    // Set Icon for the tools and filters
    SetIcons();

    // Set file tab for Save and Load
    SetFileTab();

    // Set sliders Range to match RGB's range of values.
    initSliders();

    // Canvas-to-Tools connection
    connect(ui->drawingCanvas, &Canvas::mouseEventSignal, &model, &SpriteModel::useTool);
    connect(&model, &SpriteModel::updateFrame, ui->drawingCanvas, &Canvas::redrawCanvas);
    connect(&model, &SpriteModel::updateScaleFactor, ui->drawingCanvas, &Canvas::updateCanvasScaleFactor);

    // Slider Connections
    connect(ui->redSlider, &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);
    connect(ui->greenSlider, &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);
    connect(ui->blueSlider, &QSlider::valueChanged, this, &MainWindow::onSlidersValueChanged);
    connect(this, &MainWindow::changeModelCurrentColor, &model, &SpriteModel::changeColor);
    connect(this, &MainWindow::changeTool, &model, &SpriteModel::changeTool);
    connect(this, &MainWindow::save, &model, &SpriteModel::saveProject );
    connect(this, &MainWindow::load, &model, &SpriteModel::loadProject );
    connect(&model, &SpriteModel::chooseColor, this, &MainWindow::changeSlidersColor);

    // Canvas Sizes Options Connection
    connect(ui->showSize, &QPushButton::clicked, this, &MainWindow::showBoxes);
    connect(ui->hideSize, &QPushButton::clicked, this, &MainWindow::hideBoxes);
    connect(ui->four, &QPushButton::clicked, this, &MainWindow::four);
    connect(ui->eight, &QPushButton::clicked, this, &MainWindow::eight);
    connect(ui->sixteen, &QPushButton::clicked, this, &MainWindow::sixteen);
    connect(ui->thirtyTwo, &QPushButton::clicked, this, &MainWindow::thirtyTwo);
    connect(ui->sixtyFour, &QPushButton::clicked, this, &MainWindow::sixtyFour);
    connect(this, &MainWindow::getSize, &model, &SpriteModel::rescale);
    connect(&model, &SpriteModel::updateScaleFactor, &canvas, &Canvas::updateCanvasScaleFactor);

    //Sprite Player Connections
    connect(ui->nextButton, &QToolButton::clicked, &model, &SpriteModel::nextFrame);
    connect(ui->previousButton, &QToolButton::clicked, &model, &SpriteModel::previousFrame);
    connect(ui->playButton, &QToolButton::clicked, &model, &SpriteModel::startSpritePlayer);
    connect(&model, &SpriteModel::updateSpritePlayer, ui->animationPreview, &SpritePlayer::redrawCanvas);
    connect(ui->addFrameButton, &QPushButton::clicked, &model, &SpriteModel::addFrame);
    connect(ui->deleteFrameButton, &QPushButton::clicked, &model, &SpriteModel::removeFrame);
    connect(ui->fpsSlider, &QSlider::valueChanged, this, &MainWindow::onFPSValueChanged);
    connect(this, &MainWindow::changeFPS, &model, &SpriteModel::changeSpriteSpeed);
    connect(ui->fpsSlider, &QSlider::valueChanged, this, [this](int value) {ui->fpsLabel->setText(QString::number(value) + " FPS");});

    //Filter Conenctions
    connect(ui->filterRed, &QPushButton::clicked, &model, &SpriteModel::redFilter);
    connect(ui->filterRed, &QPushButton::clicked, this, &MainWindow::cursorToggled);
    connect(ui->filterBlue, &QPushButton::clicked, &model, &SpriteModel::blueFilter);
    connect(ui->filterBlue, &QPushButton::clicked, this, &MainWindow::cursorToggled);
    connect(ui->filterGreen, &QPushButton::clicked, &model, &SpriteModel::greenFilter);
    connect(ui->filterGreen, &QPushButton::clicked, this, &MainWindow::cursorToggled);
    connect(ui->filterGrey, &QPushButton::clicked, &model, &SpriteModel::greyFilter);
    connect(ui->filterGrey, &QPushButton::clicked, this, &MainWindow::cursorToggled);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadStyleSheet() {
    QFile stylesheetFile(":/stylesheet/res/stylesheet/stylesheet.qss");
    stylesheetFile.open(QFile::ReadOnly);
    QString style(stylesheetFile.readAll());
    this->setStyleSheet(style);
}

void MainWindow::initCanvas() {
    QImage canvas(8, 8, QImage::Format_ARGB32);
    canvas.fill(Qt::transparent);
    ui->drawingCanvas->redrawCanvas(canvas);
}

void MainWindow::initSizeButtons() {
    ui->four->setVisible(false);
    ui->eight->setVisible(false);
    ui->sixteen->setVisible(false);
    ui->thirtyTwo->setVisible(false);
    ui->sixtyFour->setVisible(false);
}

void MainWindow::initPreviews() {
    QPixmap blackColorPreview(ui->colorPreview->size());
    QPixmap animationPrev(ui->animationPreview->size());
    animationPrev.fill(Qt::white);
    blackColorPreview.fill(Qt::black);

    // Set the preview
    ui->animationPreview->setPixmap(animationPrev);
    ui->colorPreview->setPixmap(blackColorPreview);
}

void MainWindow::initSliders() {
    ui->redSlider->setRange(0, 255);
    ui->greenSlider->setRange(0, 255);
    ui->blueSlider->setRange(0, 255);
}

void MainWindow::four() {
    QSize size(4, 4);
    emit getSize(size);
}

void MainWindow::eight() {
    QSize size(8, 8);
    emit getSize(size);
}

void MainWindow::sixteen() {
    QSize size(16, 16);
    emit getSize(size);
}

void MainWindow::thirtyTwo() {
    QSize size(32, 32);
    emit getSize(size);
}

void MainWindow::sixtyFour() {
    QSize size(64, 64);
    emit getSize(size);
}

void MainWindow::showBoxes() {
    ui->four->setVisible(true);
    ui->eight->setVisible(true);
    ui->sixteen->setVisible(true);
    ui->thirtyTwo->setVisible(true);
    ui->sixtyFour->setVisible(true);
}

void MainWindow::hideBoxes() {
    ui->four->setVisible(false);
    ui->eight->setVisible(false);
    ui->sixteen->setVisible(false);
    ui->thirtyTwo->setVisible(false);
    ui->sixtyFour->setVisible(false);
}

void MainWindow::onFPSValueChanged(){
    int fps = ui->fpsSlider->value();
    emit changeFPS(fps);
}

void MainWindow::onSlidersValueChanged() {
    int red = ui->redSlider->value();
    int green = ui->greenSlider->value();
    int blue = ui->blueSlider->value();
    changeColorPreview(red, green, blue);
    emit changeModelCurrentColor(red, green, blue);
}

void MainWindow::changeColorPreview(int red, int green, int blue) {
    QColor myColor = QColor(red, green, blue);
    QPixmap blackColorPreview(ui->colorPreview->size());
    blackColorPreview.fill(myColor);
    ui->colorPreview->setPixmap(blackColorPreview);
}

void MainWindow::cursorToggled() {
    ui->cursorTool->setChecked(true);
    ui->pencilTool->setChecked(false);
    ui->eraserTool->setChecked(false);
    ui->bucketTool->setChecked(false);
    ui->eyeDropperTool->setChecked(false);
    emit changeTool("Cursor");
}

void MainWindow::pencilToggled() {
    ui->cursorTool->setChecked(false);
    ui->pencilTool->setChecked(true);
    ui->eraserTool->setChecked(false);
    ui->bucketTool->setChecked(false);
    ui->eyeDropperTool->setChecked(false);
    emit changeTool("Pencil");
}

void MainWindow::eraserToggled() {
    ui->cursorTool->setChecked(false);
    ui->pencilTool->setChecked(false);
    ui->eraserTool->setChecked(true);
    ui->bucketTool->setChecked(false);
    ui->eyeDropperTool->setChecked(false);
    emit changeTool("Eraser");
}

void MainWindow::bucketToggled() {
    ui->cursorTool->setChecked(false);
    ui->pencilTool->setChecked(false);
    ui->eraserTool->setChecked(false);
    ui->bucketTool->setChecked(true);
    ui->eyeDropperTool->setChecked(false);
    emit changeTool("Bucket");
}

void MainWindow::eyeDropperToggled() {
    ui->cursorTool->setChecked(false);
    ui->pencilTool->setChecked(false);
    ui->eraserTool->setChecked(false);
    ui->bucketTool->setChecked(false);
    ui->eyeDropperTool->setChecked(true);
    emit changeTool("Eyedropper");
}

void MainWindow::applyRedFilter(){
    emit red();
}

void MainWindow::applyBlueFilter(){
    emit blue();
}

void MainWindow::applyGreenFilter(){
    emit green();
}

void MainWindow::applyGreyFilter(){
    emit grey();
}

void MainWindow::changeSlidersColor(QColor color) {
    QPixmap blackColorPreview(ui->colorPreview->size());
    blackColorPreview.fill(color);
    ui->colorPreview->setPixmap(blackColorPreview);
    ui->redSlider->setValue(color.red());
    ui->greenSlider->setValue(color.green());
    ui->blueSlider->setValue(color.blue());
}

void MainWindow::saveToggled() {
    emit save();
}

void MainWindow::loadToggled() {
    emit load();
}

void MainWindow::SetFileTab() {
    connect(ui->saveButton, &QPushButton::clicked, this,
                &MainWindow::saveToggled);
    connect(ui->loadButton, &QPushButton::clicked, this,
            &MainWindow::loadToggled);
}

void MainWindow::SetIcons() {
    // Cursor tool icon
    ui->cursorTool->setIcon(QIcon(":/stylesheet/res/icons/Cursor.png"));
    ui->cursorTool->setIconSize(QSize(20, 20));
    ui->cursorTool->setChecked(true);
    connect(ui->cursorTool, &QToolButton::clicked, this,
            &MainWindow::cursorToggled);

    // Pencil Tool icon
    ui->pencilTool->setIcon(QIcon(":/stylesheet/res/icons/Pencil.png"));
    ui->pencilTool->setIconSize(QSize(20, 20));
    connect(ui->pencilTool, &QToolButton::clicked, this,
            &MainWindow::pencilToggled);

    // Eraser tool icon
    ui->eraserTool->setIcon(QIcon(":/stylesheet/res/icons/Eraser.png"));
    ui->eraserTool->setIconSize(QSize(20, 20));
    connect(ui->eraserTool, &QToolButton::clicked, this,
            &MainWindow::eraserToggled);

    // Eyedropper tool icon
    ui->eyeDropperTool->setIcon(QIcon(":/stylesheet/res/icons/Eyedropper.png"));
    ui->eyeDropperTool->setIconSize(QSize(20, 20));
    connect(ui->eyeDropperTool, &QToolButton::clicked, this,
            &MainWindow::eyeDropperToggled);

    // Bucket tool Icon
    ui->bucketTool->setIcon(QIcon(":/stylesheet/res/icons/BucketIcon.png"));
    ui->bucketTool->setIconSize(QSize(20, 20));
    connect(ui->bucketTool, &QToolButton::clicked, this,
            &MainWindow::bucketToggled);

    // Filter icons
    ui->filterRed->setIcon(QIcon(":/stylesheet/res/icons/RedFilter.png"));
    ui->filterRed->setIconSize(QSize(20, 20));
    ui->filterGreen->setIcon(QIcon(":/stylesheet/res/icons/GreenFilter.png"));
    ui->filterGreen->setIconSize(QSize(20, 20));
    ui->filterBlue->setIcon(QIcon(":/stylesheet/res/icons/BlueFilter.png"));
    ui->filterBlue->setIconSize(QSize(20, 20));
    ui->filterGrey->setIcon(QIcon(":/stylesheet/res/icons/GreyFilter.png"));
    ui->filterGrey->setIconSize(QSize(20, 20));

    // SpritePlayer icons
    ui->playButton->setIcon(QIcon(":/stylesheet/res/icons/Play.png"));
    ui->playButton->setIconSize(QSize(30, 30));
    ui->previousButton->setIcon(QIcon(":/stylesheet/res/icons/previousButton.png"));
    ui->previousButton->setIconSize(QSize(30, 30));
    ui->nextButton->setIcon(QIcon(":/stylesheet/res/icons/nextButton.png"));
    ui->nextButton->setIconSize(QSize(30, 30));

}

void MainWindow::disablePreviousButton()
{
    ui->previousButton->setEnabled(false);
}

void MainWindow::disableNextButton()
{
    ui->nextButton->setEnabled(false);
}
