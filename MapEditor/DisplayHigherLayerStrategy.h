#ifndef DISPLAYHIGHERLAYERSTRATEGY_H
#define DISPLAYHIGHERLAYERSTRATEGY_H

#include "MapView.h"
class DisplayHigherLayerStrategy : public LayerStrategy
{
public:
    DisplayHigherLayerStrategy(MapView * mapView);

    virtual void display();
    virtual int getLayer();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

private:
};

#endif // DISPLAYHIGHERLAYERSTRATEGY_H
