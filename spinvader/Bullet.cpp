#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "Enemies.h"
#include "game.h"
#include "Score.h"
#include "spriteselector.h"
#include <QPixmap>


extern Game* game;

Bullet::Bullet() : defaultSpeed(10), currentSpeed(10)
{
    //create random cutlery
    setPixmap(SpriteSelector::getRandomSprite(SpriteSelector::Cutlery));
    setScale(0.25);                                  // scale it down to match original size
    setZValue(0);

    //connect
    QTimer* timer = new QTimer();

    //for every SIGNAL (a macro) of a certain amount of time, this will move
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}
void Bullet::move() {
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); i++) {
        QGraphicsItem* item = colliding_items[i];

        if (typeid(*item) == typeid(Enemy)) {
            currentSpeed = defaultSpeed / 2;

            QTimer::singleShot(500, this, [=]() {
                scene()->removeItem(item);
                scene()->removeItem(this);
                game->score->increase();
                delete item;
                delete this;
            });

            return; // exit early — this bullet has a deletion in the torpedo bay that will destroy it when the singleShot delay is finished
        }
    }

    // move the bullet
    setPos(x(), y() - currentSpeed);

    // delete bullet if it goes off screen
    if (pos().y() + pixmap().height() < 0) {
        scene()->removeItem(this);
        delete this;
        //qDebug() << "Bullet deleted";

    }
}










