#include "DisplayCollisionLayerStrategy.h"

DisplayCollisionLayerStrategy::DisplayCollisionLayerStrategy(MapView * mapView)
    : LayerStrategy(mapView)
{
}

void DisplayCollisionLayerStrategy::display()
{
    Model::Map * map = mapView->getMap();
    for(int i=0;i<map->getSize().width();i++)
    {
        for(int j=0;j<map->getSize().height();j++)
        {

            BlocMap * bloc = map->getBloc(i,j);
            mapView->blitTile(i,j,bloc,LOW);
            mapView->blitTile(i,j,bloc,HIGH);

            int collide = map->getBloc(i,j)->getCollisionLayer();
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

void DisplayCollisionLayerStrategy::leftButtonPressEvent(int i, int j)
{
	EXECUTE_CMD(new CollideCommand(mapView,i,j,1));
}

void DisplayCollisionLayerStrategy::leftButtonMoveEvent(int i, int j)
{
	EXECUTE_CMD(new CollideCommand(mapView,i,j,1));
}
