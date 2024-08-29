#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    //qgraphicsitem is the base class for all other other graphical items in a qgraphicsscene
    Health(QGraphicsItem* parent=0);
    void decrease();
    int getHealth();
    int health;


};

#endif // HEALTH_H
