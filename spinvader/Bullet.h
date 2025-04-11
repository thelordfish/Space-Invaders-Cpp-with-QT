#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
//have to make this class support signals and slots:
//1) make the class inherit from QObject, and
//2) add the "MACRO" of Q_OBJECT

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Bullet();
    QString getRandomCutlery();

private:
    int defaultSpeed;
    int currentSpeed;



public slots:           //a slot means a member function that can be connected to a signal
    //we've made a slot function called move here:
    void move();
};

#endif // BULLET_H
