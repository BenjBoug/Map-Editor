#ifndef DISPLAYCOLLISIONLAYERSTRATEGY_H
#define DISPLAYCOLLISIONLAYERSTRATEGY_H

#include "MapView.h"
#include <QFont>

class DisplayCollisionLayerStrategy : public LayerStrategy
{
public:
    DisplayCollisionLayerStrategy(MapView * mapView);

    virtual void display();
    virtual int getLayer();

private:
};

#endif // DISPLAYCOLLISIONLAYERSTRATEGY_H
