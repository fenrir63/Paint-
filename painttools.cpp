#include "painttools.h"

PaintTools::PaintTools(QWidget * parent) : QToolBar (parent)
{
   colorAction = new QAction();
   QPixmap colorIcon(32, 32);
   colorIcon.fill(*color);
   colorAction->setIcon(colorIcon);
   addAction(colorAction);
   connect(colorAction, SIGNAL(triggered()), this, SLOT(changeColor()));


   brushAction = new QAction();
   brushAction->setIcon(QIcon(":/rec/images/brush.png"));
   addAction(brushAction);
   connect(brushAction, SIGNAL(triggered()), this, SLOT(changeBrush()));


   washerAction = new QAction();
   washerAction->setIcon(QIcon(":/rec/images/washer.png"));
   addAction(washerAction);

   connect(washerAction, SIGNAL(triggered()), this, SLOT(useWasher()));

   lineAction = new QAction();
   lineAction->setIcon(QIcon(":/rec/images/line.png"));
   addAction(lineAction);
   connect(lineAction, SIGNAL(triggered()), this, SLOT(paintLine()));

   squareAction = new QAction();
   squareAction->setIcon(QIcon(":/rec/images/square.png"));
   addAction(squareAction);
   connect(squareAction, SIGNAL(triggered()), this, SLOT(paintSquare()));

   circleAction = new QAction();
   circleAction->setIcon(QIcon(":/rec/images/circle.png"));
   addAction(circleAction);
   connect(circleAction, SIGNAL(triggered()), this, SLOT(paintCircle()));


}

void PaintTools::setScene(paintScene * newScene){
    if(newScene != nullptr){
        scene = newScene;
    }else{
        throw std::exception();
    }
}

PaintTools::~PaintTools(){
    delete colorAction;
    delete circleAction;
    delete squareAction;
    delete lineAction;
    delete washerAction;
    delete brushAction;
}

void PaintTools::changeBrush(){
    if(window != nullptr && scene != nullptr){
        window->setCursor(Qt::ArrowCursor);
        scene->figure = paintScene::brushPainter;
    }
}

void PaintTools::changeColor(){
    color = new QColor(QColorDialog::getColor(Qt::black, this));
    if(color->isValid()){
        scene->setColor(color);
        QPixmap icon(32, 32);
        icon.fill(*color);
        colorAction->setIcon(icon);
        if(window != nullptr){
            window->setCursor(Qt::ArrowCursor);
        }
    }
}

void PaintTools::useWasher(){
    if(scene != nullptr && window != nullptr){
        color = new QColor(Qt::white);
        scene->setColor(color);
        QPixmap colorIcon(32, 32);
        colorIcon.fill(*color);
        colorAction->setIcon(colorIcon);
        window->setCursor(Qt::ArrowCursor);
        scene->figure = paintScene::brushPainter;
    }
}

void PaintTools::paintLine(){
    if(scene != nullptr && window != nullptr){
        scene->figure = paintScene::line;
        window->setCursor(Qt::CrossCursor);
    }
}

void PaintTools::paintCircle(){
   if(scene != nullptr && window != nullptr){
        scene->figure = paintScene::circle;
        window->setCursor(Qt::CrossCursor);
    }
}

void PaintTools::paintSquare(){
    if(scene != nullptr && window != nullptr){
        scene->figure = paintScene::square;
        window->setCursor(Qt::CrossCursor);
    }
}

void PaintTools::setWindow(QWidget * newWindow){
    if(newWindow != nullptr){
        window = newWindow;
    }else{
        throw std::exception();
    }
}


