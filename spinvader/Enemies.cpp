#include "Enemies.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include "game.h"

extern Game* game;

Enemy::Enemy()
{
    //set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);
    //drew the Enemy
    setRect(0, 0, 100, 100);

    //connect
    QTimer *timer = new QTimer();

    //for every SIGNAL (a macro) of a certain amount of time, this will move
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    //move enemy down
    setPos(x(), y() + 5);
    //delete enemy once it's off the screen:
    if (pos().y() + rect().height() > 700) {
       // qDebug() << "health should decrease";

        //decrease health
        game->health->decrease();
       // qDebug() << "health should decrease";


        scene()->removeItem(this);
        delete this;
       // qDebug() << "Enemy deleted";
    }
}
