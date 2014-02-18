#ifndef DISPLAYCOLLISIONLAYERSTRATEGY_H
#define DISPLAYCOLLISIONLAYERSTRATEGY_H

#include "MapView.h"
#include <QFont>

class DisplayCollisionLayerStrategy : public IStrategy
{
public:
    DisplayCollisionLayerStrategy(MapView * mapView);

    virtual void execute();

private:
    MapView * mapView;
};

#endif // DISPLAYCOLLISIONLAYERSTRATEGY_H
