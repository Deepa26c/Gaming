#include "MyRect.h"
#include "Enemy.h"
#include "Score.h"

MyRect::MyRect(QGraphicsItem * parent):QGraphicsPixmapItem(parent){
    bulletmusic = new QMediaPlayer();
    bulletmusic->setMedia(QUrl("qrc:/music/308-Bolt-Action-Rifle.mp3"));

    setPixmap(QPixmap(":/images/fighter.png"));
}
void MyRect::keyPressEvent(QKeyEvent *event){
    if(event->key()== Qt::Key_Left){
        if(pos().x()>0)
        setPos(x()-10,y());
       }
    else if(event->key()== Qt::Key_Right){
        if (pos().x()+30<800)
        setPos(x()+10,y());
       }
    else if(event->key()==Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        if(bulletmusic->state() == QMediaPlayer::PlayingState)
        {
            bulletmusic->setPosition(0);
        }
        else if(bulletmusic->state() == QMediaPlayer::StoppedState)
        {
            bulletmusic->play();
        }
    }
}

void MyRect::spawn(){
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
