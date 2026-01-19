#include "BulletSystem.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include <list>
#include <vector>
#include <QPointer>

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


        // If the bullet is inside jelly, exponentially slow it
        if (bullet->inJelly)
        {
            bullet->speed *= bullet->jellySpeedMultiplier;

            //if bullet is almost at standstill, remove bullet n jelleh
            if (std::abs(bullet->speed) < 0.2f)
            {
                if (!bullet->collidedJelly || bullet->collidedJelly->scene() == nullptr) {
                    qDebug() << "SAFE GUARD TRIGGERED: jelly gone for bullet" << static_cast<void*>(bullet);
                }

                else
                {
                    bullet->collidedJelly->toDelete = true;
                    bullet->collidedJelly = nullptr;          // bullet must not keep a dangling pointer
                }
                //mark bullet for death
                toDelete.push_back(bullet);
                continue; //skip movement

            }

        }



        bullet->setPos(bullet->x(), bullet->y() + bullet->speed); // move it up according to bullet speed



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
