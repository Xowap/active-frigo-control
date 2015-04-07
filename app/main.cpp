#include "homescreen.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile f(":/style.css");
    f.open(QFile::ReadOnly);
    a.setStyleSheet(f.readAll());

    HomeScreen w;
    w.show();

    return a.exec();
}
