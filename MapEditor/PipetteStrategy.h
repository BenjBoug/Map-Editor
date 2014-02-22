#ifndef PIPETTESTRATEGY_H
#define PIPETTESTRATEGY_H

#include "MapView.h"
#include "ChipsetView.h"

class PipetteStrategy : public PaintStrategy
{
public:
    PipetteStrategy(MapView * mapView, ChipsetView * chipsetView);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
};

#endif // PIPETTESTRATEGY_H
