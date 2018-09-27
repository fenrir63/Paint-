#include "paint.h"
#include "ui_paint.h"
#include "filemenu.h"
#include <iostream>

Paint::Paint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Paint)
{

    // create new Layout

    QGridLayout * gridLayout = new QGridLayout();
    ui->setupUi(this);
    delete layout();

    resize(1000, 1000);

    createComponents();

    //add widgets on Layout

    gridLayout->addWidget(menuBar);
    gridLayout->addWidget(paintTools, 1, 0);
    gridLayout->addWidget(horizontalSlider, 2, 0);
    gridLayout->addWidget(graphicsView, 3, 0);

    setLayout(gridLayout);

    //start resize timer

    timer = new QTimer();

    //connect timer signal with slot

    connect(timer, &QTimer::timeout, this, &Paint::slotTimer);

    //connect changing of slider value with slot

    connect(horizontalSlider, &QSlider::valueChanged, this, &Paint::slotChangeSize);

    timer->start(100);
}

Paint::~Paint(){

    //freeing the allocated pointer memory

    delete horizontalSlider;
    delete menuBar;
    delete paintTools;
    delete scene;
    delete ui;
    delete graphicsView;

}

void Paint::slotTimer(){
    timer->stop();
    //paint scene resizing
    scene->setSceneRect(0,0, graphicsView->width() - 20, graphicsView->height() - 20);
}

void Paint::slotChangeSize(int newSize){
    scene->setSize(newSize);
}

void Paint::resizeEvent(QResizeEvent *event){
    timer->start(100);
    QWidget::resizeEvent(event);
}

void Paint::createComponents(){
    scene = new paintScene();

    menuBar = new QMenuBar();
    FileMenu * fileMenu = new FileMenu();
    try {
        fileMenu->setWindow(this);
        fileMenu->setScene(scene);
    } catch (std::exception exp) {
        std::cout << exp.what() << std::endl;
    }
    menuBar->addMenu(fileMenu);

    graphicsView = new QGraphicsView();
    graphicsView->setScene(scene);

    horizontalSlider = new QSlider();
    horizontalSlider->setValue(scene->getSize());
    horizontalSlider->setOrientation(Qt::Horizontal);

    paintTools = new PaintTools();
    try {
        paintTools->setScene(scene);
        paintTools->setWindow(this);
    } catch (std::exception exp) {
        std::cout << exp.what() << std::endl;
    }


}



