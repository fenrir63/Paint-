#include "paint.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //create new QApplication

    Paint w;

    //create new Paint widget

    w.show();

    return a.exec();
}
