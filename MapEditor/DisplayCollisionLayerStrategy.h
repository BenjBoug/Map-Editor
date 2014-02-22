#ifndef DISPLAYCOLLISIONLAYERSTRATEGY_H
#define DISPLAYCOLLISIONLAYERSTRATEGY_H

#include "MapView.h"
#include <QFont>
#include "CollideCommand.h"

class DisplayCollisionLayerStrategy : public LayerStrategy
{
public:
    DisplayCollisionLayerStrategy(MapView * mapView);

    virtual void display();
    virtual int getLayer();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

private:

    bool inSelectLeft,inSelectRight;
};

#endif // DISPLAYCOLLISIONLAYERSTRATEGY_H
