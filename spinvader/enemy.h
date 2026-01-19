#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

//have to make this class support signals and slots:
//1) make the class inherit from QObject, and
//2) add the "MACRO" of Q_OBJECT

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();


    bool toDelete=false;

    //a slot means a member function that can be connected to a signal
public slots:
    //we've made a slot function called move here:
    void move();
    void markForDeletion();
};

#endif // ENEMY_H
