#ifndef MAPSTRATEGY_H
#define MAPSTRATEGY_H

#include "IStrategy.h"
#include "MapView.h"
#include "ChipsetView.h"

class MapStrategy : public IStrategy
{
public:
    MapStrategy(MapView * mapView,ChipsetView * chipsetView);

protected:
    MapView * mapView;
    ChipsetView * chipsetView;
};

#endif // MAPSTRATEGY_H
