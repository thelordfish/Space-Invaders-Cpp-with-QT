#ifndef ENEMYSYSTEM_H
#define ENEMYSYSTEM_H

#include "enemy.h"

class Enemy;
class EnemySystem{

    public:
        EnemySystem(QGraphicsScene* scenePtr);
        void moveAllEnemies();
        void registerEnemy(Enemy* Enemy);
        void destroyEnemy(Enemy* Enem);
        std::list<Enemy*> enemyRegistry; //a list is easier to delete from than a vector, which requires you to shift all members along to keep it contiguous

    private:
        QGraphicsScene* scene;

};





#endif // ENEMYSYSTEM_H
