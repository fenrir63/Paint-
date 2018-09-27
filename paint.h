#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QSlider>
#include <QGraphicsView>
#include "paintscene.h"
#include "painttools.h"
#include <QMenuBar>

namespace Ui {
class Paint;
}

class Paint : public QWidget
{
    Q_OBJECT

public:
    explicit Paint(QWidget *parent = nullptr);
    ~Paint();

private:
    Ui::Paint *ui;

    QTimer *timer;

    QSlider * horizontalSlider;

    QGraphicsView * graphicsView;

    paintScene * scene;

    QMenuBar * menuBar;

    PaintTools * paintTools;

private:

    void resizeEvent(QResizeEvent * event);

    void createComponents();

private slots:
    void slotTimer();

    void slotChangeSize(int);
};

#endif // PAINT_H
