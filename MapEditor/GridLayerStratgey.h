#ifndef GRIDLAYERSTRATGEY_H
#define GRIDLAYERSTRATGEY_H

#include "MapView.h"

class GridLayerStratgey : public IStrategy
{
public:
    GridLayerStratgey(MapView * mapView);

    virtual void execute();

private:
    MapView * mapView;
};

#endif // GRIDLAYERSTRATGEY_H
