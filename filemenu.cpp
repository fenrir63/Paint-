#include "filemenu.h"

FileMenu::FileMenu(QWidget *parent) : QMenu(parent){
    setTitle("File");
    setActions();
    addActions();
}
FileMenu::~FileMenu(){

    delete openAction;
    delete saveAction;
    delete closeAction;
    delete newAction;
    delete fileManager;
}
void FileMenu::setActions(){

    //creating of new file action

    newAction = new QAction();

    newAction->setIcon(QIcon(":/rec/images/new.png"));
    newAction->setText("New");
    newAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));

    connect(newAction, SIGNAL(triggered()), this, SLOT(slotNew()));

    //creating of open file action

    openAction = new QAction();

    openAction->setIcon(QIcon(":/rec/images/open.png"));
    openAction->setText("Open...");
    openAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));

    connect(openAction, SIGNAL(triggered()), this, SLOT(slotOpen()));

    //creating of save file action

    saveAction = new QAction();

    saveAction->setIcon(QIcon(":/rec/images/save.png"));
    saveAction->setText("Save...");
    saveAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));

    connect(saveAction, SIGNAL(triggered()), this, SLOT(slotSave()));

    //creating of close action

    closeAction = new QAction();

    closeAction->setIcon(QIcon(":/rec/images/close.png"));
    closeAction->setText("Close");
    closeAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));

    connect(closeAction, SIGNAL(triggered()), this, SLOT(slotClose()));

}
void FileMenu::addActions(){
    fileManager = new FileManager();

    this->addAction(newAction);

    this->addAction(openAction);

    this->addAction(saveAction);

    this->addAction(closeAction);
}

void FileMenu::slotClose(){
    if(window != nullptr){
        window->close();
    }else{
        throw std::exception();
    }
}
void FileMenu::slotOpen(){

    if(fileManager != nullptr){
        //getting path of file

        QString path = fileManager->openFile();

        if(path != ""){
            scene->clear();
            scene->addPixmap(QPixmap(path));
        }
    }else{
        throw std::exception();
    }
}
void FileMenu::slotSave(){
    if(fileManager != nullptr){

        //clearing and rendering of paintScene items

        scene->clearSelection();
        scene->setSceneRect(scene->itemsBoundingRect());
        QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
        QPainter painter(&image);
        scene->render(&painter);
        QString path = fileManager->saveFile();
        if(path != ""){
            image.save(path);
        }
    }else{
        throw std::exception();
    }
}

void FileMenu::setWindow(QWidget * newWindow){
    if(newWindow != nullptr){
        window = newWindow;
    }else{
        throw std::exception();
    }
}

void FileMenu::setScene(paintScene * newScene){
    if(newScene != nullptr){
        scene = newScene;
    }else{
        throw std::exception();
    }
}

void FileMenu::slotNew(){
    if(scene != nullptr){
        scene->clear();
    }
}

