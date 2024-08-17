#include <QGuiApplication>
#include "MainManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    MainManager mainManager;

    return app.exec();
}
