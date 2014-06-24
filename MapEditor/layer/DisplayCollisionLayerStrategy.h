#ifndef DISPLAYCOLLISIONLAYERSTRATEGY_H
#define DISPLAYCOLLISIONLAYERSTRATEGY_H

#include "MapView.h"
#include <QFont>
#include "command/CollideCommand.h"
#include "UndoSingleton.h"

class DisplayCollisionLayerStrategy : public LayerStrategy
{
public:
    DisplayCollisionLayerStrategy(MapView * mapView);

    virtual void display();
    virtual int getLayer();

	virtual void leftButtonPressEvent(int i, int j);

	virtual void leftButtonMoveEvent(int i, int j);


private:

};

#endif // DISPLAYCOLLISIONLAYERSTRATEGY_H
