#include "ScaleCanvas.h"
#include "ui_scalecanvas.h"

ScaleCanvas::ScaleCanvas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScaleCanvas)
{
    ui->setupUi(this);

    ui->fourxbutton->setCheckable(true);
    ui->eightxbutton->setCheckable(true);
    ui->sixteenxbutton->setCheckable(true);
    ui->thirtytwoxbutton->setCheckable(true);
    ui->sixtyfourxbutton->setCheckable(true);

    ui->sixteenxbutton->setChecked(true);

    connect(ui->fourxbutton, &QToolButton::clicked, this, &ScaleCanvas::fourSelected);
    connect(ui->eightxbutton, &QToolButton::clicked, this, &ScaleCanvas::eightSelected);
    connect(ui->sixteenxbutton, &QToolButton::clicked, this, &ScaleCanvas::sixteenSelected);
    connect(ui->thirtytwoxbutton, &QToolButton::clicked, this, &ScaleCanvas::thirtytwoSelected);
    connect(ui->sixtyfourxbutton, &QToolButton::clicked, this, &ScaleCanvas::sixtyfourSelected);
}

void ScaleCanvas::fourSelected(){
    ui->fourxbutton->setChecked(true);
    ui->eightxbutton->setChecked(false);
    ui->sixteenxbutton->setChecked(false);
    ui->thirtytwoxbutton->setChecked(false);
    ui->sixtyfourxbutton->setChecked(false);
}

void ScaleCanvas::eightSelected(){
    ui->fourxbutton->setChecked(false);
    ui->eightxbutton->setChecked(true);
    ui->sixteenxbutton->setChecked(false);
    ui->thirtytwoxbutton->setChecked(false);
    ui->sixtyfourxbutton->setChecked(false);
}

void ScaleCanvas::sixteenSelected(){
    ui->fourxbutton->setChecked(false);
    ui->eightxbutton->setChecked(false);
    ui->sixteenxbutton->setChecked(true);
    ui->thirtytwoxbutton->setChecked(false);
    ui->sixtyfourxbutton->setChecked(false);
}

void ScaleCanvas::thirtytwoSelected(){
    ui->fourxbutton->setChecked(false);
    ui->eightxbutton->setChecked(false);
    ui->sixteenxbutton->setChecked(false);
    ui->thirtytwoxbutton->setChecked(true);
    ui->sixtyfourxbutton->setChecked(false);
}

void ScaleCanvas::sixtyfourSelected(){
    ui->fourxbutton->setChecked(false);
    ui->eightxbutton->setChecked(false);
    ui->sixteenxbutton->setChecked(false);
    ui->thirtytwoxbutton->setChecked(false);
    ui->sixtyfourxbutton->setChecked(true);
}

ScaleCanvas::~ScaleCanvas()
{
    delete ui;
}
