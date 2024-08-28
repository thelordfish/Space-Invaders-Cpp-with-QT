#ifndef GAME_H
#define GAME_H

#include "qgraphicsview.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include "Score.h"


class Game : public QGraphicsView{
    Q_OBJECT



public:
    Game();
    Score* score;
public slots:
    void Spawn();

private:
    QGraphicsScene* scene = new QGraphicsScene(this);
    QGraphicsView* view = new QGraphicsView(this);

};

extern Game* game;

#endif // GAME_H
