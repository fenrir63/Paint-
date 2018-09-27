#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include <QColor>
#include <cmath>
class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:

    enum Figure{
        circle,
        line,
        square,
        brushPainter
    };

    Figure figure = brushPainter;

    explicit paintScene(QObject *parent = nullptr);

    void setSize(int);

    int getSize();

    void setColor(QColor *);

    ~paintScene();


private:
    QPointF previousPoint;

    QColor * color;

    int size = 10;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);


};

#endif // PAINTSCENE_H
