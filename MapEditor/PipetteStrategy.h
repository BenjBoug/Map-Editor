#ifndef PIPETTESTRATEGY_H
#define PIPETTESTRATEGY_H

#include "MapView.h"
#include "ChipsetView.h"

class PipetteStrategy : public PaintStrategy
{
public:
    PipetteStrategy(MapView * mapView, ChipsetView * chipsetView);

    virtual void leftButtonPressEvent(int i,int j);
    virtual void leftButtonMoveEvent(int i,int j);
};

#endif // PIPETTESTRATEGY_H
