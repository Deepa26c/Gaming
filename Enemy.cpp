#include "Enemy.h"
#include "Game.h"
#include <stdlib.h>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    int random_number = rand() % 700;
    setPos(random_number,0);

   // setRect(0,0,100,100);
    setPixmap(QPixmap(":/images/Enemy.jpg"));
    setTransformOriginPoint(50,50);
    setRotation(180);
    QTimer * timer =new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

     timer->start(50); //50ms
}
void Enemy::move(){
    setPos(x(),y()+5);

    if(pos().y() > 600){
        game->life->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
