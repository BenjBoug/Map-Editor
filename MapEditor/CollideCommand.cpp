#include "CollideCommand.h"


CollideCommand::CollideCommand(MapView *mapView, int i, int j, int collide)
{
    this->mapView=mapView;
    this->i=i;
    this->j=j;
    this->collide=collide;
    this->erase = new EraseCommand(mapView,i,j,COLLIDE);
}

void CollideCommand::execute()
{
    collideMemento = mapView->getMap()->getBloc(i,j)->getCollision();
    erase->execute();
    QFont font("Helvetica", 20, QFont::Bold);
    QGraphicsSimpleTextItem * collisionItem = mapView->addSimpleText(QString("%1").arg(collide),font);
    collisionItem->setBrush(Qt::lightGray);
    collisionItem->setPos(i*BLOCSIZE,j*BLOCSIZE);
    collisionItem->setZValue(COLLIDE);
    mapView->getMap()->getBloc(i,j)->setCollision(collide);
}

void CollideCommand::undo()
{
    collide=collideMemento;
    execute();
}
