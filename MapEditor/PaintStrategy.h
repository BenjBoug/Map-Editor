#ifndef PAINTSTRATEGY_H
#define PAINTSTRATEGY_H

#include "IStrategy.h"
class MapView;
class ChipsetView;

class PaintStrategy : public IStrategy
{
public:
    PaintStrategy(MapView * mapView,ChipsetView * chipsetView);

protected:
    MapView * mapView;
    ChipsetView * chipsetView;
};

#endif // PAINTSTRATEGY_H
