#include "LayerStrategy.h"
#include "MapView.h"

LayerStrategy::LayerStrategy(MapView *mapView)
{
    this->mapView=mapView;
}

void LayerStrategy::blitBloc(int i, int j, int bloc, int layer, float opacity)
{
    chipset = mapView->getChipset();
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

void LayerStrategy::eraseBloc(int i, int j, int layer)
{
    QList<QGraphicsItem *> item = mapView->items(QRect((i*BLOCSIZE),(j*BLOCSIZE),BLOCSIZE,BLOCSIZE));
    item = mapView->getLayer(item,layer);
    QList<QGraphicsItem *>::iterator it;
    for(it=item.begin();it!=item.end();it++)
    {
        mapView->removeItem(*it);
    }
}

void LayerStrategy::eraseAndBlitBloc(int i, int j, int bloc, int layer, float opacity)
{
    eraseBloc(i,j,layer);
    blitBloc(i,j,bloc,layer,opacity);
}
