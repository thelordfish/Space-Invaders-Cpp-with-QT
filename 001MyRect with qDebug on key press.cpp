#include "MyRect.h"
#include <QDebug>

void MyRect::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< "MyRect knows that you pressed a key";
}
