#include "QGraphicsTileItem.h"

QGraphicsTileItem::QGraphicsTileItem(BlocMap *bloc, QPixmap chipset, int layer)
{
    this->bloc=bloc;
    this->chipset=chipset;
    this->layer=layer;
    int bl = bloc->getAtLayer(layer);
    QPixmap tile  = chipset.copy((bl%(chipset.width()/BLOCSIZE))*BLOCSIZE,(bl/(chipset.width()/BLOCSIZE))*BLOCSIZE,BLOCSIZE,BLOCSIZE);
    setZValue(layer);
    tileItem = new QGraphicsPixmapItem(tile);
    connect(bloc,SIGNAL(blocLayerModified(int)),this,SLOT(blocHasChange(int)));
}

void QGraphicsTileItem::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    int valueMax = (chipset.width()/BLOCSIZE)*(chipset.height()/BLOCSIZE);
    if (bloc->getAtLayer(layer)!=0 && bloc->getAtLayer(layer) < valueMax)
        tileItem->paint(painter,option,widget);
}

QRectF QGraphicsTileItem::boundingRect() const
{
    return tileItem->boundingRect();
}

void QGraphicsTileItem::blocHasChange(int layer)
{
    if (this->layer==layer)
    {
        int bl = bloc->getAtLayer(layer);
        QPixmap tile = chipset.copy((bl%(chipset.width()/BLOCSIZE))*BLOCSIZE,(bl/(chipset.width()/BLOCSIZE))*BLOCSIZE,BLOCSIZE,BLOCSIZE);
        tileItem->setPixmap(tile);
        this->update();
    }
}
