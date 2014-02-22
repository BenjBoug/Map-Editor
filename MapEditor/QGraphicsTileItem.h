#ifndef QGRAPHICSTILEITEM_H
#define QGRAPHICSTILEITEM_H

#include <QGraphicsPixmapItem>
#include "Constantes.h"

class QGraphicsTileItem : public QGraphicsPixmapItem
{
public:
    QGraphicsTileItem(QPixmap tile, QPointF pos, qreal layer, qreal opacity=1.0);
};

#endif // QGRAPHICSTILEITEM_H
