#include "ChangeDimensionCommand.h"

ChangeDimensionCommand::ChangeDimensionCommand(MapView *mapView, QSize newSize)
{
    this->newSize=newSize;
    this->mapView=mapView;
}

void ChangeDimensionCommand::execute()
{
    Model::Map *map = mapView->getMap();
    mapMemento  = *map;

    sizeMemento = mapView->getMap()->getSize();
    mapView->getMap()->setSize(newSize);
    mapView->displayBackground();
    mapView->displayMap();
}

void ChangeDimensionCommand::undo()
{
    Model::Map *map = mapView->getMap();
    map->setSize(sizeMemento);
    for(int i=0;i<map->getSize().width();i++)
    {
        for(int j=0;j<map->getSize().height();j++)
        {
            map->getBloc(i,j)->setLowLayer(mapMemento.getBloc(i,j)->getLowLayer());
            map->getBloc(i,j)->setHighLayer(mapMemento.getBloc(i,j)->getHighLayer());
            map->getBloc(i,j)->setCollisionLayer(mapMemento.getBloc(i,j)->getCollisionLayer());
        }
    }
    mapView->displayBackground();
    mapView->displayMap();
}
