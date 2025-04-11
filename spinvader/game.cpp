#include "game.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include "Enemies.h"
#include "MyRect.h"
#include "Score.h"
#include "health.h"
#include <QMediaPlayer>
#include <QDebug>
#include <QAudioOutput>
#include "spriteselector.h"
#include <QPixmap>

extern Game* game; //makes it global and usable by any other file

Game::Game() : view(new QGraphicsView()), scene(new QGraphicsScene())  {


    scene->setSceneRect(0, 0, 800, 600); // Set the size of the scene
    view->setScene(scene); // Set the scene to the view
  //  QPixmap bg = SpriteSelector::getRandomSprite(SpriteSelector::Background);
    QPixmap bg(":/New/images/gardenbackground.png");
    scene->setBackgroundBrush(QBrush(bg.scaled(scene->sceneRect().size().toSize())));




    // create a view to see the scene (done in header), no scroll bar,
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //the view is a widget, it is invisible by default, make it visible by calling its show member function:
    view->show();
    //3 sets of coordinates in QT the QGraphicsScene, the QGraphicsView, the thing/MyRect. We didn't set the size of the scene so they can expand infinitely
    view->setFixedSize(800,600);

    //create an item called player, set size & position, add to scene using member function additem:
    MyRect* player = new MyRect();
    player->setRect(0,0,100, 100);
    scene->addItem(player);
    // make rect focusable (for whatever reason only one object can be focussed/affected by the keypress, isnt automatically selected even if there only is one
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(view->width()/2, view->height()- player->rect().height());

    //create the score & health

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(x(), y()+25);
    scene->addItem(health);

    //spawn enemies
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::Spawn); // Connect the timer's timeout signal to Game::Spawn
    timer->start(2000);

    // Play music
    music->setSource(QUrl("qrc:/New/Sounds/theme.mp3"));
    music->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.25);
    qDebug() << "music->setSource" << music->source();
    music->play();
    qDebug() << "played";

}

void Game::Spawn()
    {
        //create an enemy
        Enemy *enemy = new Enemy();
        scene->addItem(enemy);



    }



