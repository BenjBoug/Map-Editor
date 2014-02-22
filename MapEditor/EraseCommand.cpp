#include "EraseCommand.h"

EraseCommand::EraseCommand(MapView *mapView, int i, int j, int layer, float opacity)
{
    this->mapView = mapView;
    this->i=i;
    this->j=j;
    this->layer=layer;
    this->opacityMemento=opacity;
}

void EraseCommand::execute()
{
    blocMemento=mapView->getMap()->getBloc(i,j)->getLayer(layer);
    mapView->removeTile(i,j,layer);
}

void EraseCommand::undo()
{
    mapView->removeTile(i,j,layer);
    mapView->blitTile(i,j,blocMemento,layer,opacityMemento);
}
