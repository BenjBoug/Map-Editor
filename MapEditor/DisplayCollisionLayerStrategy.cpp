#include "DisplayCollisionLayerStrategy.h"

DisplayCollisionLayerStrategy::DisplayCollisionLayerStrategy(MapView * mapView)
    : LayerStrategy(mapView)
{
}

void DisplayCollisionLayerStrategy::display()
{
    Model::Map * map = mapView->getMap();
    for(int i=0;i<map->getDim().width();i++)
    {
        for(int j=0;j<map->getDim().height();j++)
        {

            int couche1 = map->getBloc(i,j)->getCouche1();
            blitBloc(i,j,couche1,LOW);
            int couche2 = map->getBloc(i,j)->getCouche2();
            blitBloc(i,j,couche2,HIGH);

            int collide = map->getBloc(i,j)->getCollision();
            QFont font("Helvetica", 20, QFont::Bold);
            QGraphicsSimpleTextItem * collisionItem = mapView->addSimpleText(QString("%1").arg(collide),font);
            collisionItem->setBrush(Qt::lightGray);
            collisionItem->setPos(i*BLOCSIZE,j*BLOCSIZE);
            collisionItem->setZValue(COLLIDE);
        }
    }
}

int DisplayCollisionLayerStrategy::getLayer()
{
    return COLLIDE;
}

