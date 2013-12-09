#include "mygraphicsscene.h"
MyGraphicsScene::MyGraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
}
void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event){

    emit mouseClicked(event);
}
void MyGraphicsScene::keyPressEvent(QKeyEvent *event){
    emit keyPressed(event);
}
