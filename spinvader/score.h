#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    //qgraphicsitem is the base class for all other other graphical items in a qgraphicsscene
    Score(QGraphicsItem* parent=0);
    void increase();
    int getScore();
    int score;


};

#endif // SCORE_H
