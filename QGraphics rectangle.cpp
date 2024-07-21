

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
/*
 * -QGraphicsScene
 * -QGraphicsItem (QGraphicsRectItem)
 * -QGraphicsView
 *
 *-events (keyPressEvent() and QKeyEvent stores information about the event, what key was pressed in this case)
 *-event propagation system  -order of response to the event. which object receives this event first etc
 *-QDebug
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //create an item to put into the scene
    QGraphicsRectItem* rect = new QGraphicsRectItem();

    //rectitem is a rectangle of 0 length 0 width. use setRect() method(python)/member function (the c++ equivalent) to give it size and position
    rect->setRect(0,0,100, 100);

    //add the item to the scene using member function addItem

    scene->addItem(rect);

    // create a view to see the scene
    QGraphicsView * view = new QGraphicsView(scene);

    //the view is a widget, it is invisible by default, make it visible by calling its show member function:
    view->show();

    return a.exec();
}
