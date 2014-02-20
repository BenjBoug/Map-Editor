#include "DisplayHigherLayerStrategy.h"

DisplayHigherLayerStrategy::DisplayHigherLayerStrategy(MapView *mapView)
    : LayerStrategy(mapView)
{
}

void DisplayHigherLayerStrategy::display()
{
    Model::Map * map = mapView->getMap();
    for(int i=0;i<map->getDim().width();i++)
    {
        for(int j=0;j<map->getDim().height();j++)
        {
            int couche1 = map->getBloc(i,j)->getCouche1();
            blitBloc(i,j,couche1,LOW,0.3);
            int couche2 = map->getBloc(i,j)->getCouche2();
            blitBloc(i,j,couche2,HIGH);
        }
    }

}

void DisplayHigherLayerStrategy::setBloc(int i, int j, int bloc)
{
    mapView->getMap()->getBloc(i,j)->setCouche2(bloc);
    this->eraseAndBlitBloc(i,j,bloc,HIGH);
}
