
#include "GameDriver.h"
#include "Bullet.h"
#include "GameWindow.h"

#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QAudioOutput>
#include <QBrush>
#include <QPixmap>
#include <QDebug>
#include "SpriteSelector.h"
#include "Player.h"
#include "enemy.h"
#include "Score.h"
#include "health.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>
#include "bulletsystem.h"
#include "enemysystem.h"

GameDriver::GameDriver(GameWindow* window)
    : QObject(window),
    window(window),
    scene(window->scene()),
    bulletSystem(scene),
    enemySystem(scene)

{


    // Create the player
    player = new Player();
    player->setRect(0,0,100,100);
    scene->addItem(player);

    //Connect playerrs shoot bullet signals. Connect works like   connect(sender, signal, receiver, slot)

    // object A → sends A::signal → object B → calls function B::slot()


    connect(
        player,                 //SENDER -  a pointer to the emitter object, in this case the instance of my class "MyRect
        &Player::shootBullet,   //SIGNAL - & is the memory address of Player::shootBullet which is the signal function. so it knows which signal is being referred to.
        this,                   //RECEIVER - pointer to GameDriver (the receiver of the players emission)
        &GameDriver::onPlayerShoot); //SLOT - create bullet

    //trying to stop the frzen bug
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    player->setPos(
        (scene->width() - player->rect().width()) / 2,      //put rect(scene width + player width) /2
        scene->height() - player->rect().height()           //set the top of the rect a player length above the bottom
        );

    // Score & health
    score = new Score();
    health = new Health();
    health->setPos(0, 25);
    scene->addItem(score);
    scene->addItem(health);


    // Central game loop timer (frame clock)
    clockTimer = new QTimer(this);
    connect(                            //connect(sender, signal, receiver, slot) / connect(a, &A::signal, b, &B::slot); The sender and receiver are already pointers, the signal and slot must be made pointers using the &
        clockTimer,             //SENDER - clockTimer is the emitter
        &QTimer::timeout,       //SIGNAL - the memory address of the timeout signal function
        this,                   //RECEIVER - the gameDriver is received the function
        &GameDriver::onClock    //SLOT - the receiver's function, the onClock function
        );

    clockTimer->start(16);   // ≈ 60 FPS - QTimer will emit the timeout() signal every time its internal interval elapses, this will now trigger gameDriver's onClock


    // Enemy spawner
    QTimer* enemyTimer = new QTimer(this);
    connect(
        enemyTimer,                 //SENDER
        &QTimer::timeout,           //SIGNAL
        this,                       //RECEIVER
        &GameDriver::spawnEnemy);   //SLOT

    enemyTimer->start(2000);


    // Music
    music = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    music->setSource(QUrl("qrc:/New/Sounds/theme.mp3"));
    music->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.25);
    music->play();
}




void GameDriver::onClock() {
    bulletSystem.moveAllBullets();
    checkBulletCollisions();
    enemySystem.moveAllEnemies();
    // collisionSystem.update();
}



void GameDriver::checkBulletCollisions()
{
    std::vector<Bullet*> toDelete;

    for ( Bullet* bullet : bulletSystem.bulletRegistry)
    {
        if (!bullet) continue;

        QList<QGraphicsItem*> hits = bullet->collidingItems();

        for (QGraphicsItem* item : hits)
        {
            Enemy* enemy = dynamic_cast<Enemy*>(item);
            if (!enemy) continue;

            // hit!


            bullet->inJelly = true;
            bullet->setCollidedJelly(enemy);


            // // remove both if not jelly
            //score->increase();
            // toDelete.push_back(bullet);
            // scene->removeItem(enemy);
            // enemy->deleteLater(); //should probs turn this into a destroy function in the enemy system


            // bullet pointer auto-nullifies (QPointer) → safe
            break;
        }
    }
    for (Bullet* bullet : toDelete)
        bulletSystem.destroyBullet(bullet);
}
void GameDriver::onPlayerShoot()
{
    Bullet* bullet = new Bullet(SpriteSelector::getRandomSprite(SpriteSelector::Cutlery));
    bullet->setPos(
        player->x() + player->rect().width()/2, //X ->accesses player's members, ->x() calls QGraphicsItem::x(). positioning bullet mid-player
        player->y());                           //Y

    bulletSystem.registerBullet(bullet);
    scene->addItem(bullet);
}
void GameDriver::spawnEnemy()
{
    Enemy* enemy = new Enemy();
    scene->addItem(enemy);
    enemySystem.registerEnemy(enemy);
}
