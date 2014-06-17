#include "CollideCommand.h"


CollideCommand::CollideCommand(MapView *mapView, int i, int j, int collide)
{
    this->mapView=mapView;
    this->i=i;
    this->j=j;
    this->collide=collide;
}

void CollideCommand::execute()
{
    collideMemento = mapView->getMap()->getBloc(i,j)->getCollisionLayer();
    mapView->removeTile(i,j,COLLIDE);
    QFont font("Helvetica", 20, QFont::Bold);
    QGraphicsSimpleTextItem * collisionItem = mapView->addSimpleText(QString("%1").arg(collide),font);
    collisionItem->setBrush(Qt::lightGray);
    collisionItem->setPos(i*BLOCSIZE,j*BLOCSIZE);
    collisionItem->setZValue(COLLIDE);
    mapView->getMap()->getBloc(i,j)->setCollisionLayer(collide);
}

void CollideCommand::undo()
{
    collide=collideMemento;
    execute();
}
