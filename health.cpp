#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    // initialize Health to 0
    health = 5;

    //draw and describe txt
    setPlainText("Health: " +QString::number(health)); // Health: 5
    setDefaultTextColor(Qt::darkRed);
    setFont(QFont("times", 16));
}

void Health::decrease() {
    health--;
    setPlainText("Health: " +QString::number(health)); // Health: -1

}

int Health::getHealth(){
    return health;
}
