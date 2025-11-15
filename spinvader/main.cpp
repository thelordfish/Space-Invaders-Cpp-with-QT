#include "GameWindow.h"
#include "GameDriver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameWindow* window = new GameWindow();
    GameDriver* driver = new GameDriver(window);

    window->show();
    return app.exec();
}
