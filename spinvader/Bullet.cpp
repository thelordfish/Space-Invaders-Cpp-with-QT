#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "spriteselector.h"
#include <QPixmap>




Bullet::Bullet() : defaultSpeed(10), currentSpeed(10)
{
    //create random cutlery
    setPixmap(SpriteSelector::getRandomSprite(SpriteSelector::Cutlery));
    setScale(0.25);                                  // scale it down to match original size
    setZValue(0);

}

void Bullet::moveUp(float speed)
{
    setPos(x(), y() - speed);
}










