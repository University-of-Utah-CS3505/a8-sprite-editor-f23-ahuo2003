#ifndef SCALECANVAS_H
#define SCALECANVAS_H

#include <QDialog>

namespace Ui {
class ScaleCanvas;
}

class ScaleCanvas : public QDialog
{
    Q_OBJECT

public:
    explicit ScaleCanvas(QWidget *parent = nullptr);
    ~ScaleCanvas();
public slots:
    void fourSelected();
    void eightSelected();
    void sixteenSelected();
    void thirtytwoSelected();
    void sixtyfourSelected();

private:
    Ui::ScaleCanvas *ui;
};

#endif // SCALECANVAS_H
