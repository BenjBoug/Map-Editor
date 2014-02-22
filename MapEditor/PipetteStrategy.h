#ifndef PIPETTESTRATEGY_H
#define PIPETTESTRATEGY_H

#include "MapView.h"
#include "ChipsetView.h"

class PipetteStrategy : public PaintStrategy
{
public:
    PipetteStrategy(MapView * mapView, ChipsetView * chipsetView);

    virtual void leftButtonPressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void leftButtonMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
};

#endif // PIPETTESTRATEGY_H
