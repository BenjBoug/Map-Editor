#ifndef PAINTSTRATEGY_H
#define PAINTSTRATEGY_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
class MapView;
class ChipsetView;

class PaintStrategy
{
public:
    PaintStrategy(MapView * mapView,ChipsetView * chipsetView);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

protected:
    MapView * mapView;
    ChipsetView * chipsetView;
    QGraphicsRectItem * rectItem;
};

#endif // PAINTSTRATEGY_H
