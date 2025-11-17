#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <QPixmap>
#include "Enemies.h"
#include <QPointer>


Bullet::Bullet(const QPixmap &sprite)
{
    // BulletSystem::registerBullet(this);
    //create random cutlery
    setPixmap(sprite);
    setScale(0.25);                                  // scale it down to match original size
    setZValue(0);

    speed = -10.0f;
    jellySpeedMultiplier = 0.8f;
    collidedJelly = nullptr;

}

// void Bullet::moveUp(float speed)
// {
//     setPos(x(), y() - speed);
// }



void Bullet::setCollidedJelly(Enemy* enemy) {
    collidedJelly = enemy;
}








