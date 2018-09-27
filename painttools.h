#ifndef PAINTTOOLS_H
#define PAINTTOOLS_H
#include <QToolBar>
#include "paintscene.h"
#include <QColorDialog>

class PaintTools : public QToolBar
{
    Q_OBJECT
public:
    PaintTools(QWidget * parent = nullptr);

    ~PaintTools();

    void setScene(paintScene *);

    void setWindow(QWidget *);
private:
    paintScene * scene;

    QWidget * window;

    QColor * color = new QColor(Qt::black);

    QAction * colorAction;
    QAction * brushAction;
    QAction * washerAction;

    QAction * lineAction;
    QAction * circleAction;
    QAction * squareAction;

private slots:
    void changeColor();

    void changeBrush();

    void useWasher();

    void paintLine();

    void paintCircle();

    void paintSquare();
};

#endif // PAINTTOOLS_H
