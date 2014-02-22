#include "DisplayVisuaLayerStrategy.h"

DisplayVisuaLayerStrategy::DisplayVisuaLayerStrategy(MapView *mapView)
    : LayerStrategy(mapView)
{
}

void DisplayVisuaLayerStrategy::display()
{
    Model::Map * map = mapView->getMap();
    for(int i=0;i<map->getDim().width();i++)
    {
        for(int j=0;j<map->getDim().height();j++)
        {
            int couche1 = map->getBloc(i,j)->getCouche1();
            mapView->blitTile(i,j,couche1,LOW);
            int couche2 = map->getBloc(i,j)->getCouche2();
            mapView->blitTile(i,j,couche2,HIGH);
        }
    }
}

int DisplayVisuaLayerStrategy::getLayer()
{
    return 999;
}
