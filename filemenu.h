#ifndef FILEMENU_H
#define FILEMENU_H
#include <QMenu>
#include <exception>
#include "filemanager.h"
#include "paintscene.h"
#include <QPainter>

class FileMenu : public QMenu
{
    Q_OBJECT

public:

    FileMenu(QWidget *parent = nullptr);

    ~FileMenu();

    void setWindow(QWidget *);

    void setScene(paintScene *);

private:

    QAction * openAction;

    QAction * saveAction;

    QAction * closeAction;

    QAction * newAction;

    QWidget * window;

    paintScene * scene;

    FileManager * fileManager;

    void setActions();

    void addActions();

private slots:

    void slotOpen();

    void slotSave();

    void slotClose();

    void slotNew();
};


#endif // FILEMENU_H
