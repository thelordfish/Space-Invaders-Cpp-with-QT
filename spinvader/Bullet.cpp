#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "Enemies.h"
#include "game.h"
#include "Score.h"

extern Game* game;

Bullet::Bullet()
{
    //drew the bullet
    setRect(0,0,10,50);

    //connect
    QTimer* timer = new QTimer();

    //for every SIGNAL (a macro) of a certain amount of time, this will move
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move() {
    qDebug() << "bullet be movin";

    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i =0, n = colliding_items.size(); i<n; i++) {
        qDebug() << "for loop be startin";

        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            qDebug() << "Collision with Enemy detected";

            if (!game) {
                qDebug() << "Error: 'game' is null!";
                return;
            }

            if (!game->score) {
                qDebug() << "Error: 'game->score' is null!";
                return;
            }
            qDebug() << "game:" << game << "score:" << game->score;

            //increase score
            game->score->increase();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //delete them from the heap?
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move bullet
    setPos(x(), y()-10);
    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
        //qDebug() << "Bullet deleted";

    }

}
