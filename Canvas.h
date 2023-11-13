#ifndef CANVAS_H
#define CANVAS_H
#include <QMouseEvent>
#include <QLabel>

class Canvas : public QLabel {
    Q_OBJECT

    public:
        Canvas(QLabel *parent = nullptr);
    protected:
        virtual void mousePressEvent(QMouseEvent *event) override;
        virtual void mouseReleaseEvent(QMouseEvent *event) override;
        virtual void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // CANVAS_H
