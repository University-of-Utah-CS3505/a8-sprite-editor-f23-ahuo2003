#ifndef PIXELSCALE_H
#define PIXELSCALE_H

#include <QDialog>

namespace Ui {
class PixelScale;
}

class PixelScale : public QDialog {
    Q_OBJECT

public:
    explicit PixelScale(QWidget *parent = nullptr);
    ~PixelScale();
private:
    Ui::PixelScale *ui;
};

#endif // PIXELSCALE_H
