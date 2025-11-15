#include "GameWindow.h"
#include <QGraphicsScene>
#include <QBrush>
#include <QPixmap>

GameWindow::GameWindow(QWidget* parent)
    : QGraphicsView(parent),
    m_scene(new QGraphicsScene(this))

{
    setScene(m_scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    m_scene->setSceneRect(0, 0, 800, 600);

    // Optional: background
    // QPixmap bg(":/New/images/gardenbackground.png");
    // m_scene->setBackgroundBrush(bg.scaled(m_scene->sceneRect().size().toSize()));
}
