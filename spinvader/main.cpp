#include <QGraphicsView>
#include <QGraphicsItem>
#include "qapplication.h"
#include <QTimer>
#include "game.h"

/*
 *-QTimer
 *-signals and slots (connect function)
 */
//@@ -19,26 +21,43 @@

Game* game;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv); // Initialize QApplication

    Game game;


    return a.exec();
}
