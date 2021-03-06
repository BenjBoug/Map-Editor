#ifndef DISPLAYLOWERLAYERSTRATEGY_H
#define DISPLAYLOWERLAYERSTRATEGY_H

#include "MapView.h"
#include "command/EraseCommand.h"

class DisplayLowerLayerStrategy : public LayerStrategy
{
public:
    DisplayLowerLayerStrategy(MapView * mapView);

    virtual void display();
	virtual int getLayer();

private:
};

#endif // DISPLAYLOWERLAYERSTRATEGY_H
