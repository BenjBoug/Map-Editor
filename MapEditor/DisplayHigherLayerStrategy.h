#ifndef DISPLAYHIGHERLAYERSTRATEGY_H
#define DISPLAYHIGHERLAYERSTRATEGY_H

#include "MapView.h"

class DisplayHigherLayerStrategy : public LayerStrategy
{
public:
    DisplayHigherLayerStrategy(MapView * mapView);

    virtual void execute();
    virtual void setBloc(int i, int j, int bloc);

private:
};

#endif // DISPLAYHIGHERLAYERSTRATEGY_H
