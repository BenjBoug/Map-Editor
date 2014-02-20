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
            blitBloc(i,j,couche1,LOW);
            int couche2 = map->getBloc(i,j)->getCouche2();
            blitBloc(i,j,couche2,HIGH);
        }
    }
}


void DisplayVisuaLayerStrategy::setBloc(int i, int j, int bloc)
{

}
