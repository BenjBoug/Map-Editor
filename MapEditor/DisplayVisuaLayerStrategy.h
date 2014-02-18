#ifndef DISPLAYVISUALAYERSTRATEGY_H
#define DISPLAYVISUALAYERSTRATEGY_H

#include "MapView.h"

class DisplayVisuaLayerStrategy : public IStrategy
{
public:
    DisplayVisuaLayerStrategy(MapView * mapView);

    virtual void execute();

private:
    MapView * mapView;
};

#endif // DISPLAYVISUALAYERSTRATEGY_H
