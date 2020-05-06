#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget * parent){

    //create the scene, QGraphicsScene is base scene class for all the graphics games we create
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);


    //createitem to put into the scene --is by using following class which is inherited from QGraphicItem(Abstractclass)
    MyRect *rect = new MyRect();   ///by default rect is having l,w as 0,0,h,w ///player created
    //rect->setRect(0,0,100,100);
    rect->setPos(400,500);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    //add item to scene
    scene->addItem(rect);

    score = new Score();
    scene->addItem(score);

    life = new Life();
    life->setPos(life->x(),life->y()+25);
    scene->addItem(life);

    //enemy timer
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),rect,SLOT(spawn()));
    timer->start(2000);

    QMediaPlayer * player = new QMediaPlayer();
    player->setMedia(QUrl("qrc:/music/Hearbeat.mp3"));
    if(player->state() == QMediaPlayer::PlayingState)
    {
        player->setPosition(0);
    }
    else if(player->state() == QMediaPlayer::StoppedState)
    {
        player->play();
    }
    show();
}
