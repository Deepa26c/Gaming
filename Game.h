#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include "Score.h"
#include "MyRect.h"
#include "Life.h"

class Game:public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    MyRect * rect;
    Score * score;
    Life *life;

};

#endif // GAME_H
