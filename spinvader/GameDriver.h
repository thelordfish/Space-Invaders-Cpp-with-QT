#pragma once

#include "qmediaplayer.h"
#include <QObject>
#include <QPointer>
#include <vector>

class GameWindow;
class QGraphicsScene;
class Score;
class Health;
class Enemy;
class Bullet;
class QTimer;
class Player;

class GameDriver : public QObject {
    Q_OBJECT

public:
    explicit GameDriver(GameWindow* window);

public slots:

    void spawnEnemy();
    void onClock();


private:
    GameWindow* window;
    QGraphicsScene* scene;

    Score* score;
    Health* health;

    QMediaPlayer* music = nullptr;
    QAudioOutput* audioOutput = nullptr;

    Player* player = nullptr;
    QTimer* enemySpawner;
    QTimer* clockTimer;

    std::vector<QPointer<Bullet>> bullets;

    void registerBullet(Bullet* bullet);
    void unregisterBullet(Bullet* bullet);
    void onPlayerShoot();
    void updateAllBullets();
    void checkBulletCollisions();
};
