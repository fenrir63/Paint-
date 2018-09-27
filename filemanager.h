#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFileDialog>
#include <QDir>


class FileManager : public QFileDialog
{
    Q_OBJECT

public:

    FileManager(QWidget * parent = nullptr);

    ~FileManager();

    QString openFile();

    QString saveFile();
};

#endif // FILEMANAGER_H
