#include "DisplayHigherLayerStrategy.h"

DisplayHigherLayerStrategy::DisplayHigherLayerStrategy(MapView *mapView)
    : LayerStrategy(mapView)
{
}

void DisplayHigherLayerStrategy::display()
{
    Model::Map * map = mapView->getMap();
    for(int i=0;i<map->getSize().width();i++)
    {
        for(int j=0;j<map->getSize().height();j++)
        {
            BlocMap * bloc = map->getBloc(i,j);
            mapView->blitTile(i,j,bloc,LOW,0.3);
            mapView->blitTile(i,j,bloc,HIGH);
        }
    }
}

int DisplayHigherLayerStrategy::getLayer()
{
    return HIGH;
}

void DisplayHigherLayerStrategy::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mapView->getCurrentPaint()->mousePressEvent(mouseEvent);
}

void DisplayHigherLayerStrategy::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mapView->getCurrentPaint()->mouseMoveEvent(mouseEvent);
}

void DisplayHigherLayerStrategy::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mapView->getCurrentPaint()->mouseReleaseEvent(mouseEvent);
}
