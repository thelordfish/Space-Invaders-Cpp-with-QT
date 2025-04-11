

#include "MyRect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0)
            setPos(x() - 10, y());

    } else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 800)
            setPos(x() + 10, y());

    }
    // else if (event ->key() == Qt::Key_Up) {
    //     setPos(x(),y()-10);
    // }
    // else if (event ->key() == Qt::Key_Down) {
    //     setPos(x(),y()+10);
    // }



    else if (event->key() == Qt::Key_Space) {

        // create a bullet
        Bullet *bullet = new Bullet();
        qreal playerCenterX = x() + boundingRect().width() / 2;
        qreal bulletOffset = bullet->pixmap().width() * bullet->scale() / 2;

        bullet->setPos(playerCenterX - bulletOffset, y());
        scene()->addItem(bullet);
    }
}


