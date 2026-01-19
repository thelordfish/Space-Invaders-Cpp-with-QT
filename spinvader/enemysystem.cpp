#include "enemysystem.h"
#include "enemy.h"
#include "qgraphicsscene.h"


EnemySystem::EnemySystem(QGraphicsScene* scenePtr)
    : scene(scenePtr)       // initializing the private member variable *QGraphicsScene* scene given in the header file
{}



void EnemySystem::registerEnemy(Enemy* enemy)
{
    enemyRegistry.push_back(enemy);
}

void EnemySystem::destroyEnemy(Enemy* enemy)
{
    if (!enemy) return;

    if (enemy->scene())                        //if bullet is in a scene, remove bullet from that scene
        enemy->scene()->removeItem(enemy);


    enemy->deleteLater();      //QT specific deletion for objects inheriting from QObject - delete bullet can crash
}

void EnemySystem::moveAllEnemies(){
    qDebug() << "EnemySystem tick, registry size =" << enemyRegistry.size();

    std::list<Enemy*>::iterator i = enemyRegistry.begin();

    while (i != enemyRegistry.end()) {       //not i<enemyregistry.end() because < only works for random access iterators (vector, array) bidirectional iterators (list) are just moving from one node to the next, they dont see it as higher or lower

        Enemy* enemy = *i; //“The iterator points to a list node; dereferencing it gives me the Enemy* stored in that node

        enemy->move();

        if (enemy->toDelete)
        {
            destroyEnemy(enemy);
            i = enemyRegistry.erase(i);
        }
        else{
            i++;
        }
    }


}
