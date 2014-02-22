#ifndef DISPLAYCOLLISIONLAYERSTRATEGY_H
#define DISPLAYCOLLISIONLAYERSTRATEGY_H

#include "MapView.h"
#include <QFont>
#include "CollideCommand.h"
#include "UndoSingleton.h"

class DisplayCollisionLayerStrategy : public LayerStrategy
{
public:
    DisplayCollisionLayerStrategy(MapView * mapView);

    virtual void display();
    virtual int getLayer();

    virtual void leftButtonPressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void rightButtonPressEvent(QGraphicsSceneMouseEvent * mouseEvent);

    virtual void leftButtonMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void rightButtonMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);


private:

};

#endif // DISPLAYCOLLISIONLAYERSTRATEGY_H
