

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "myRect.h"
#include <QTimer>

/*
 *-QTimer
 *-signals and slots (connect function)
 *-QObject and Q_OBJECT macro
 *
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //create an item to put into the scene
    MyRect * player = new MyRect();
    //QGraphicsRectItem* rect = new QGraphicsRectItem();

    //rectitem is a rectangle of 0 length 0 width. use setRect() method(python)/member function (the c++ equivalent) to give it size and position
    player->setRect(0,0,100, 100);

    //add the item to the scene using member function addItem

    scene->addItem(player);

    // make rect focusable (for whatever reason only one object can be focussed/affected by the keypress, isnt automatically selected even if there only is one
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    // create a view to see the scene
    QGraphicsView * view = new QGraphicsView(scene);

    //turn off the scroll bar as a dirty fix from the bullet endlessly expanding the box
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    //the view is a widget, it is invisible by default, make it visible by calling its show member function:
    view->show();

     //3 sets of coordinates in QT the QGraphicsScene, the QGraphicsView, the thing/MyRect. We didn't set the size of the scene so they can expand infinitely
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2, view->height()- player->rect().height());

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
