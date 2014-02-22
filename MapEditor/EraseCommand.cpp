#include "EraseCommand.h"

EraseCommand::EraseCommand(MapView *mapView, int i, int j)
{
    this->mapView = mapView;
    this->i=i;
    this->j=j;
    layerMemento = mapView->getCurrentLayer()->getLayer();
}

void EraseCommand::execute()
{
    blocMemento=mapView->getMap()->getBloc(i,j)->getLayer(layerMemento);
    mapView->getMap()->getBloc(i,j)->setLayer(layerMemento,0);
}

void EraseCommand::undo()
{
    mapView->getMap()->getBloc(i,j)->setLayer(layerMemento,blocMemento);
}
