#include "DisplayLowerLayerStrategy.h"

DisplayLowerLayerStrategy::DisplayLowerLayerStrategy(MapView * mapView)
    : LayerStrategy(mapView)
{
}

void DisplayLowerLayerStrategy::display()
{
    Model::Map * map = mapView->getMap();
    for(int i=0;i<map->getSize().width();i++)
    {
        for(int j=0;j<map->getSize().height();j++)
        {
            BlocMap * bloc = map->getBloc(i,j);
            mapView->blitTile(i,j,bloc,LOW);
            mapView->blitTile(i,j,bloc,HIGH,0.3);
        }
    }
}

int DisplayLowerLayerStrategy::getLayer()
{
    return LOW;
}
