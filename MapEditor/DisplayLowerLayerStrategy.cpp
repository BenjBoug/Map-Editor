#include "DisplayLowerLayerStrategy.h"

DisplayLowerLayerStrategy::DisplayLowerLayerStrategy(MapView * mapView)
    : LayerStrategy(mapView)
{
}

void DisplayLowerLayerStrategy::display()
{
    Model::Map * map = mapView->getMap();
    for(int i=0;i<map->getDim().width();i++)
    {
        for(int j=0;j<map->getDim().height();j++)
        {
            int couche1 = map->getBloc(i,j)->getCouche1();
            mapView->blitTile(i,j,couche1,LOW);
            int couche2 = map->getBloc(i,j)->getCouche2();
            mapView->blitTile(i,j,couche2,HIGH,0.3);
        }
    }
}

int DisplayLowerLayerStrategy::getLayer()
{
    return LOW;
}


void DisplayLowerLayerStrategy::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mapView->getCurrentPaint()->mousePressEvent(mouseEvent);
}

void DisplayLowerLayerStrategy::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mapView->getCurrentPaint()->mouseMoveEvent(mouseEvent);
}

void DisplayLowerLayerStrategy::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mapView->getCurrentPaint()->mouseReleaseEvent(mouseEvent);
}
