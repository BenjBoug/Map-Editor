#ifndef DISPLAYLOWERLAYERSTRATEGY_H
#define DISPLAYLOWERLAYERSTRATEGY_H

#include "MapView.h"
#include "EraseCommand.h"
#include "EraseAndBlitCommand.h"

class DisplayLowerLayerStrategy : public LayerStrategy
{
public:
    DisplayLowerLayerStrategy(MapView * mapView);

    virtual void display();
    virtual int getLayer();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

private:
};

#endif // DISPLAYLOWERLAYERSTRATEGY_H
