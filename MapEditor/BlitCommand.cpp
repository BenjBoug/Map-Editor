#include "BlitCommand.h"

BlitCommand::BlitCommand(MapView *mapView, int i, int j, int bloc)
{
    this->mapView=mapView;
    this->i=i;
    this->j=j;
    this->bloc=bloc;
    this->layerMemento=mapView->getCurrentLayer()->getLayer();
}

void BlitCommand::execute()
{
    blocMemento=mapView->getMap()->getBloc(i,j)->getLayer(layerMemento);
    mapView->getMap()->getBloc(i,j)->setLayer(layerMemento,bloc);
}

void BlitCommand::undo()
{
    mapView->getMap()->getBloc(i,j)->setLayer(layerMemento,blocMemento);
}
