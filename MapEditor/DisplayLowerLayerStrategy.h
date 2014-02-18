#ifndef DISPLAYLOWERLAYERSTRATEGY_H
#define DISPLAYLOWERLAYERSTRATEGY_H

#include "MapView.h"

class DisplayLowerLayerStrategy : public IStrategy
{
public:
    DisplayLowerLayerStrategy(MapView * mapView);

    virtual void execute();

private:
    MapView * mapView;
};

#endif // DISPLAYLOWERLAYERSTRATEGY_H
