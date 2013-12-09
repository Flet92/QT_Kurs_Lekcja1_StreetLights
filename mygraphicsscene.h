#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyGraphicsScene(QObject *parent = 0);

signals:
    void mouseClicked(QGraphicsSceneMouseEvent *event);
    void keyPressed(QKeyEvent *event);
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // MYGRAPHICSSCENE_H
