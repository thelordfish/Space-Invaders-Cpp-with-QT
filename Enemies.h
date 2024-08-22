#ifndef ENEMIES_H
#define ENEMIES_H


#include <QGraphicsRectItem>
#include <QObject>
//have to make this class support signals and slots:
//1) make the class inherit from QObject, and
//2) add the "MACRO" of Q_OBJECT

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy();
    //a slot means a member function that can be connected to a signal
public slots:
    //we've made a slot function called move here:
    void move();
};


#endif // ENEMIES_H
