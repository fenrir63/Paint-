#include "paintscene.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent){
    //setting default color
    color = new QColor(Qt::black);
}

paintScene::~paintScene(){
    delete color;
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(figure == brushPainter){
        //drawing ellipse in pressed position

        addEllipse(event->scenePos().x() - size/2,
                   event->scenePos().y() - size/2,
                   size,
                   size,
                   QPen(Qt::NoPen),
                   QBrush(*color));

        //previous point saving

        previousPoint = event->scenePos();
    }
    if(figure == line || figure == circle || figure == square){
        previousPoint = event->scenePos();
    }
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(figure == brushPainter){

        //line drawing from prious point position

        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(*color, size, Qt::SolidLine,Qt::RoundCap));

        previousPoint = event->scenePos();
    }
}



void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
    if(figure == line){
        //line drawing from pressed  mouse position
        //to released mouse position

        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(*color, size, Qt::SolidLine,Qt::RoundCap));
    }
    if(figure == circle){

        //calculating of ellipse center

        double xp = previousPoint.x();
        double yp = previousPoint.y();
        double xc = event->scenePos().x();
        double yc = event->scenePos().y();
        double xo = std::abs((xp + xc)/2) - std::abs(xc - xp)/2;
        double yo = std::abs((yp + yc)/2) - std::abs(yc - yp)/2;

        //ellipse drawing with diagonal from pressed mouse position
        //to released mouse position

        addEllipse(xo,
                   yo,
                   std::abs(event->scenePos().x() - previousPoint.x()),
                   std::abs(event->scenePos().y() - previousPoint.y()),
                   QPen(*color, size),
                   QBrush(Qt::NoBrush));

    }
    if(figure == square){

        //rectangle lines drawing with diagonal from pressed mouse position
        //to released mouse position

        addLine(previousPoint.x(),
                previousPoint.y(),
                previousPoint.x(),
                event->scenePos().y(),
                QPen(*color, size, Qt::SolidLine,Qt::RoundCap));
        addLine(previousPoint.x(),
                event->scenePos().y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(*color, size, Qt::SolidLine,Qt::RoundCap));
        addLine(event->scenePos().x(),
                event->scenePos().y(),
                event->scenePos().x(),
                previousPoint.y(),
                QPen(*color, size, Qt::SolidLine,Qt::RoundCap));
        addLine(event->scenePos().x(),
                previousPoint.y(),
                previousPoint.x(),
                previousPoint.y(),
                QPen(*color, size, Qt::SolidLine,Qt::RoundCap));
    }
}

void paintScene::setColor(QColor * newColor){
    color = newColor;
}
void paintScene::setSize(int newSize){
    if(newSize > 0){
        size = newSize;
    }
}
int paintScene::getSize(){
    return size;
}

