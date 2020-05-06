#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "Bullet.h"
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

/* This is player class , in which item can move left and right and defeat enemy*/
//class MyRect: public QObject, public QGraphicsRectItem{
class MyRect: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT;
public:
    MyRect(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent* event);
public slots:
    void spawn();
private:
    QMediaPlayer * bulletmusic;
};

#endif // MYRECT_H
