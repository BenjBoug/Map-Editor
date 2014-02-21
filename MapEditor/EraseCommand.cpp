#include "EraseCommand.h"

EraseCommand::EraseCommand(MapView *mapView, int i, int j, int layer)
{
    this->mapView = mapView;
    this->i=i;
    this->j=j;
    this->layer=layer;
}

void EraseCommand::execute()
{
    QList<QGraphicsItem *> item = mapView->items(QRect((i*BLOCSIZE),(j*BLOCSIZE),BLOCSIZE,BLOCSIZE));
    item = mapView->getLayer(item,layer);
    QList<QGraphicsItem *>::iterator it;
    for(it=item.begin();it!=item.end();it++)
    {
        mapView->removeItem(*it);
    }
    if (layer==LOW)
        mapView->getMap()->getBloc(i,j)->setCouche1(0);
    else if (layer==HIGH)
        mapView->getMap()->getBloc(i,j)->setCouche2(0);
}

void EraseCommand::undo()
{

}

void EraseCommand::redo()
{

}
