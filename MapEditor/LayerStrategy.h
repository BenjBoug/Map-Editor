#ifndef LAYERSTRATEGY_H
#define LAYERSTRATEGY_H

#include "IStrategy.h"
#include "Blocmap.h"

class MapView;

class LayerStrategy : public IStrategy
{
public:
    LayerStrategy(MapView * mapView);

    virtual void setBloc(int i, int j, int bloc) = 0;

protected:
    MapView * mapView;
};

#endif // LAYERSTRATEGY_H
