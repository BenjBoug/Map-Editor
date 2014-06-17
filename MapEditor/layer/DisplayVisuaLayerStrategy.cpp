#include "DisplayVisuaLayerStrategy.h"

DisplayVisuaLayerStrategy::DisplayVisuaLayerStrategy(MapView *mapView)
    : LayerStrategy(mapView)
{
}

void DisplayVisuaLayerStrategy::display()
{
    Model::Map * map = mapView->getMap();
    for(int i=0;i<map->getSize().width();i++)
    {
        for(int j=0;j<map->getSize().height();j++)
        {
            BlocMap * bloc = map->getBloc(i,j);
            mapView->blitTile(i,j,bloc,LOW);
            mapView->blitTile(i,j,bloc,HIGH);
        }
    }
}

int DisplayVisuaLayerStrategy::getLayer()
{
	return EVENT;
}
