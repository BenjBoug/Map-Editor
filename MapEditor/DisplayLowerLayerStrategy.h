#ifndef DISPLAYLOWERLAYERSTRATEGY_H
#define DISPLAYLOWERLAYERSTRATEGY_H

#include "MapView.h"

class DisplayLowerLayerStrategy : public LayerStrategy
{
public:
    DisplayLowerLayerStrategy(MapView * mapView);

    virtual void display();
    virtual void setBloc(int i, int j, int bloc);

private:
};

#endif // DISPLAYLOWERLAYERSTRATEGY_H
