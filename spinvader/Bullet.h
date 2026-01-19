#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "enemy.h"
#include <QPointer>
//have to make this class support signals and slots:
//1) make the class inherit from QObject, and
//2) add the "MACRO" of Q_OBJECT

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Bullet(const QPixmap& sprite);

    float speed = -10.0f;
    float jellySpeedMultiplier = 0.92f;
    bool inJelly = false;
    QPointer<Enemy> collidedJelly = nullptr; //crucial it is a qpointer, so it automatically updates to nullptr, when multiple cutlery hits the same jelly and holds reference to it after its deleted


    void setCollidedJelly(Enemy* enemy);
   // void moveSelfUp(float speed); //should be done by bulletSystem

private:




public slots:           //a slot means a member function that can be connected to a signal
    //we've made a slot function called move here:
    //void move();
};

#endif // BULLET_H
