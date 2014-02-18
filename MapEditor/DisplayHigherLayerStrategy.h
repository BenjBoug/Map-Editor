#ifndef DISPLAYHIGHERLAYERSTRATEGY_H
#define DISPLAYHIGHERLAYERSTRATEGY_H

#include "MapView.h"

class DisplayHigherLayerStrategy : public IStrategy
{
public:
    DisplayHigherLayerStrategy(MapView * mapView);

    virtual void execute();

private:
    MapView * mapView;
};

#endif // DISPLAYHIGHERLAYERSTRATEGY_H
