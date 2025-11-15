#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsView>

class QGraphicsScene;

class GameWindow : public QGraphicsView {
    Q_OBJECT

public:
    explicit GameWindow(QWidget* parent = nullptr);

    QGraphicsScene* scene() const { return m_scene; }

private:
    QGraphicsScene* m_scene;
};

#endif // GAMEWINDOW_H
