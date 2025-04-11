#include "Enemies.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include <QPixmap>
#include "game.h"
#include <QList>
#include <stdlib.h>
#include "spriteselector.h"

extern Game* game;

Enemy::Enemy()
{


    //set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //draw the Enemy
    //setPixmap(QPixmap(imagePaths[index]));



    setPixmap(SpriteSelector::getRandomSprite(SpriteSelector::Jelly));
    setScale(0.2);
    setOpacity(0.75);
    setZValue(1);

    //connect
    QTimer *timer = new QTimer(this);

    //for every SIGNAL (a macro) of a certain amount of time, this will move
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    //move enemy down
    setPos(x(), y() + 5);
    //delete enemy once it's off the screen:
    if (pos().y() + pixmap().height() *scale() > scene()->height()) {
        qDebug() << "health should decrease";
        qDebug() << "Jelly Y: " << pos().y() << " threshold: " << scene()->height();
        qDebug() << "posY:" << pos().y()
                 << "scaledHeight:" << pixmap().height() * scale()
                 << "sceneHeight:" << scene()->height();

        //decrease health
        game->health->decrease();
       // qDebug() << "health should decrease";


        scene()->removeItem(this);
        delete this;
       // qDebug() << "Enemy deleted";
    }
}
