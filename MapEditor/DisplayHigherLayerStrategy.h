#ifndef DISPLAYHIGHERLAYERSTRATEGY_H
#define DISPLAYHIGHERLAYERSTRATEGY_H

#include "MapView.h"
#include "EraseAndBlitCommand.h"
class DisplayHigherLayerStrategy : public LayerStrategy
{
public:
    DisplayHigherLayerStrategy(MapView * mapView);

    virtual void display();
    virtual int getLayer();

private:
};

#endif // DISPLAYHIGHERLAYERSTRATEGY_H
