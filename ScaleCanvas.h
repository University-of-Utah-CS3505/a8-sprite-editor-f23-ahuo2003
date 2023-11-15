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
    /**
     * @brief fourSelected set the selected canvas size to four
     */
    void fourSelected();

    /**
     * @brief eightSelected set the selected canvas size to eight
     */
    void eightSelected();

    /**
     * @brief sixteenSelected set the selected canvas size to sixteen
     */
    void sixteenSelected();

    /**
     * @brief thirtytwoSelected set the selected canvas size to thirty two
     */
    void thirtytwoSelected();

    /**
     * @brief sixtyfourSelected set the selected canvas size to sixty four
     */
    void sixtyfourSelected();

private:
    // The UI for this window
    Ui::ScaleCanvas *ui;
};

#endif // SCALECANVAS_H
