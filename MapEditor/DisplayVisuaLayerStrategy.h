#ifndef DISPLAYVISUALAYERSTRATEGY_H
#define DISPLAYVISUALAYERSTRATEGY_H

#include "MapView.h"

class DisplayVisuaLayerStrategy : public LayerStrategy
{
public:
    DisplayVisuaLayerStrategy(MapView * mapView);

    virtual void display();
    virtual void setBloc(int i, int j, int bloc);

private:
};

#endif // DISPLAYVISUALAYERSTRATEGY_H
