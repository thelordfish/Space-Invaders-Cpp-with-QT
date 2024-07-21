#include "Bullet.h"
#include <QTimer>

Bullet::Bullet()
{
    //drew the bullet
    setRect(0,0,10,50);

    //connect
    QTimer * timer = new QTimer();
    //for every SIGNAL (a macro) of a certain amount of time, this will move
    connect(timer,SIGNAL(timeout()),this.SLOT(move()));
    timer->start(50);
}
