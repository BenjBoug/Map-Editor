#include "BlitCommand.h"


BlitCommand::BlitCommand(MapView *mapView, int i, int j, int bloc, int layer, int opacity)
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
        tileItem->setOpacity(opacity);
    }
}

void BlitCommand::undo()
{
    bloc = blocMemento;
    execute();
}

void BlitCommand::redo()
{
    bloc = blocMemento;
    execute();
}
