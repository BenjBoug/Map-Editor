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
            BlocMap * bloc = map->getBloc(i,j);
            mapView->blitTile(i,j,bloc,LOW);
            mapView->blitTile(i,j,bloc,HIGH);
        }
    }
}

int DisplayVisuaLayerStrategy::getLayer()
{
    return 999;
}
