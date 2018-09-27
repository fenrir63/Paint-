#include "filemanager.h"


FileManager::FileManager(QWidget * parent) : QFileDialog (parent){

}



FileManager::~FileManager(){

}

QString FileManager::openFile(){
    QString stdFilter =  tr("PNG (*.png)");
    QString fileOpenPath = getOpenFileName(this, "Choose image to open it",
                           QDir::homePath(),
                           tr("JPEG (*.jpg *.jpeg);; PNG (*.png)"),
                           &stdFilter);
    return fileOpenPath;
}

QString FileManager::saveFile(){
    QString stdFilter =  tr("PNG (*.png)");
    QString fileSavePath = getSaveFileName(this, "Enter file name and set the directory to save it",
                           QDir::homePath(),
                           tr("PNG (*.png)"),
                           &stdFilter);
    return fileSavePath;
}
