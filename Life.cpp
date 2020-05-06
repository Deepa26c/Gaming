#include "Life.h"
#include <QFont>

Life::Life(QGraphicsItem * parent): QGraphicsTextItem(parent){
    life = 3;

    setPlainText(QString("Life: ") + QString::number(life));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}
void Life::decrease(){
    life--;
    setPlainText(QString("Life: ")+ QString::number(life));
}
int Life::getLife(){
    return life;
}
