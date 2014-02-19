#ifndef DISPLAYCOLLISIONLAYERSTRATEGY_H
#define DISPLAYCOLLISIONLAYERSTRATEGY_H

#include "MapView.h"
#include <QFont>

class DisplayCollisionLayerStrategy : public LayerStrategy
{
public:
    DisplayCollisionLayerStrategy(MapView * mapView);

    virtual void execute();
    virtual void setBloc(int i, int j, int bloc);

private:
};

#endif // DISPLAYCOLLISIONLAYERSTRATEGY_H
