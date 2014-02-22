#include "EraseAndBlitCommand.h"

EraseAndBlitCommand::EraseAndBlitCommand(MapView *mapView, int i, int j, int bloc, int layer, float opacity)
{
    this->mapView=mapView;
    eraseCmd = new EraseCommand(mapView,i,j,layer,opacity);
    blitCmd = new BlitCommand(mapView,i,j,bloc,layer,opacity);
    this->i=i;
    this->j=j;
    layerMemento=layer;
    opacityMemento=opacity;
}

void EraseAndBlitCommand::execute()
{
    blocMemento = mapView->getMap()->getBloc(i,j)->getLayer(layerMemento);
    eraseCmd->execute();
    blitCmd->execute();
}

void EraseAndBlitCommand::undo()
{
    //blitCmd->undo();
    eraseCmd->undo();
}
