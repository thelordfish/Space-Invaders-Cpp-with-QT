#include <QGraphicsView>
#include <QGraphicsItem>
#include "qapplication.h"
#include <QTimer>
#include "game.h"



Game* game;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv); // Initialize QApplication

    //Game game;
    // Initialize the global game pointer
    game = new Game();  // Allocate memory for the game instance
    //game->show();       // Show the game window

    return a.exec();
}
