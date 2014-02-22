#include "QGraphicsTileItem.h"

QGraphicsTileItem::QGraphicsTileItem(QPixmap tile, QPointF pos, qreal layer, qreal opacity)
{
    this->setPixmap(tile);
    this->setPos(pos);
    this->setZValue(layer);
    this->setOpacity(opacity);
}
