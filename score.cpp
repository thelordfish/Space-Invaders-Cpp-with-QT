#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    // initialize score to 0
    score = 0;

    //draw and describe txt
    setPlainText("Score: " +QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::darkGreen);
    setFont(QFont("times", 16));
}

void Score::increase() {
    score++;
    setPlainText("Score: " +QString::number(score)); // Score: +1

}

int Score::getScore(){
    return score;
}
