#ifndef GAME_H
#define GAME_H

#include "qgraphicsview.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QObject>
#include "Score.h"
#include "health.h"
#include <QAudioOutput>


class Game : public QGraphicsView{
    Q_OBJECT



public:
    Game();
    Score* score;
    Health* health;

public slots:
    void Spawn();

private:
    QGraphicsScene* scene = new QGraphicsScene(this);
    QGraphicsView* view = new QGraphicsView(this);
    QMediaPlayer* music = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);

};

extern Game* game;

#endif // GAME_H
