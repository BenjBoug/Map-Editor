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
    {
        blocMemento = mapView->getMap()->getBloc(i,j)->getCouche1();
        mapView->getMap()->getBloc(i,j)->setCouche1(0);
    }
    else if (layer==HIGH)
    {
        blocMemento = mapView->getMap()->getBloc(i,j)->getCouche2();
        mapView->getMap()->getBloc(i,j)->setCouche2(0);
    }
}

void EraseCommand::undo()
{
    int bloc = blocMemento;
    if (layer==LOW)
    {
        blocMemento = mapView->getMap()->getBloc(i,j)->getCouche1();
        mapView->getMap()->getBloc(i,j)->setCouche1(bloc);
    }
    else if (layer==HIGH)
    {
        blocMemento = mapView->getMap()->getBloc(i,j)->getCouche2();
        mapView->getMap()->getBloc(i,j)->setCouche2(bloc);
    }
    QPixmap chipset = mapView->getChipset();
    int valueMax = (chipset.width()/BLOCSIZE)*(chipset.height()/BLOCSIZE);
    if (bloc!=0 && bloc < valueMax)
    {
        QPixmap tile = chipset.copy((bloc%(chipset.width()/BLOCSIZE))*BLOCSIZE,(bloc/(chipset.width()/BLOCSIZE))*BLOCSIZE,BLOCSIZE,BLOCSIZE);
        QGraphicsPixmapItem * tileItem = mapView->addPixmap(tile);
        tileItem->setPos(i*BLOCSIZE,j*BLOCSIZE);
        tileItem->setZValue(layer);
    }
}

void EraseCommand::redo()
{
    execute();
}
