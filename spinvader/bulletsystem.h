#ifndef BULLETSYSTEM_H
#define BULLETSYSTEM_H
#include <QPointer>
#include <QGraphicsScene>

class Bullet;

class BulletSystem
{
public:
    BulletSystem(QGraphicsScene* scenePointer); //this system needs access to the scene so it can remove bullets from scene
    void moveAllBullets();
    void registerBullet(Bullet* bullet);
    void destroyBullet(Bullet* bullet);
    std::list<Bullet*> bulletRegistry; //a list is easier to delete from than a vector, which requires you to shift all members along to keep it contiguous

private:
    QGraphicsScene* scene;

};

#endif // BULLETSYSTEM_H
