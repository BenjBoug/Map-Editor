#include "BlitCommand.h"


BlitCommand::BlitCommand(MapView *mapView, int i, int j, int bloc, int layer, float opacity)
{
    this->mapView = mapView;
    this->i=i;
    this->j=j;
    this->bloc=bloc;
    this->layer=layer;
    this->opacity=opacity;
}

void BlitCommand::execute()
{
    blocMemento=mapView->getMap()->getBloc(i,j)->getLayer(layer);
    layerMemento=layer;
    opacityMemento=opacity;
    mapView->blitTile(i,j,bloc,layer,opacity);
}

void BlitCommand::undo()
{
    bloc = blocMemento;
    layer = layerMemento;
    opacity = opacityMemento;

    mapView->removeTile(i,j,layer);
    execute();
}
