#ifndef BULLET_H
#define BULLET_H
//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

//class Bullet: public QObject, public QGraphicsRectItem{   //to add rectangle item
class Bullet: public QObject, public QGraphicsPixmapItem{             //to add graphics images
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent=0);

public slots:
    void move();
};

#endif // BULLET_H
