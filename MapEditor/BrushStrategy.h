#ifndef BRUSHSTRATEGY_H
#define BRUSHSTRATEGY_H

#include "PaintStrategy.h"
#include <QVector>
#include <QDebug>
#include "MapView.h"
#include "ChipsetView.h"
#include "EraseAndBlitCommand.h"

class BrushStrategy : public PaintStrategy
{
public:
    BrushStrategy(MapView * mapView, ChipsetView * chipsetView);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

private:

    void blit(QPointF pos);
    QRect blited;
    bool inSelect, inSelectRight;
    QGraphicsRectItem * rectItem;
};

#endif // BRUSHSTRATEGY_H
