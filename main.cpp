

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "myRect.h"
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
    MyRect * rect = new MyRect();
    //QGraphicsRectItem* rect = new QGraphicsRectItem();

    //rectitem is a rectangle of 0 length 0 width. use setRect() method(python)/member function (the c++ equivalent) to give it size and position
    rect->setRect(0,0,100, 100);

    //add the item to the scene using member function addItem

    scene->addItem(rect);

    // make rect focusable (for whatever reason only one object can be focussed/affected by the keypress, isnt automatically selected even if there only is one
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();


    // create a view to see the scene
    QGraphicsView * view = new QGraphicsView(scene);

    //the view is a widget, it is invisible by default, make it visible by calling its show member function:
    view->show();

    return a.exec();
}
