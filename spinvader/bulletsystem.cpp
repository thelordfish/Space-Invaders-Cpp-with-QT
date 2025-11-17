#include "BulletSystem.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include <list>
#include <vector>


BulletSystem::BulletSystem(QGraphicsScene* scenePtr)
    : scene(scenePtr)
{}

void BulletSystem::registerBullet(Bullet* bullet)
{
    bulletRegistry.push_back(bullet);
}

void BulletSystem::destroyBullet(Bullet* bullet)
{
    if (!bullet) return;

    if (bullet->scene())                        //if bullet is in a scene, remove bullet from that scene
        bullet->scene()->removeItem(bullet);

    bulletRegistry.remove(bullet);

    bullet->deleteLater();      //QT specific deletion for objects inheriting from QObject - delete bullet can crash
}

void BulletSystem::moveAllBullets(){

    std::vector<Bullet*> toDelete;

    for (Bullet* bullet : bulletRegistry)
    {


        if (!bullet)
            continue; // null if deleted

        bullet->setPos(bullet->x(), bullet->y() + bullet->speed); // move it up according to bullet speed


        // If the bullet is inside jelly, exponentially slow it
        if (bullet->inJelly)
        {
            bullet->speed *= bullet->jellySpeedMultiplier;
        }

        // Off-screen removal
        float bulletBottom = bullet->y() + bullet->pixmap().height() * bullet->scale();

        if (bulletBottom < scene->sceneRect().top())  // out of scene
        {
            toDelete.push_back(bullet);
        }
    }

        // Second pass
    for (Bullet* bullet : toDelete)
        destroyBullet(bullet);



}
