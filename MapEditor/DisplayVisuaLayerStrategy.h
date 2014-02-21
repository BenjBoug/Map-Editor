#ifndef DISPLAYVISUALAYERSTRATEGY_H
#define DISPLAYVISUALAYERSTRATEGY_H

#include "MapView.h"

class DisplayVisuaLayerStrategy : public LayerStrategy
{
public:
    DisplayVisuaLayerStrategy(MapView * mapView);

    virtual void display();
    virtual int getLayer();

private:
};

#endif // DISPLAYVISUALAYERSTRATEGY_H
