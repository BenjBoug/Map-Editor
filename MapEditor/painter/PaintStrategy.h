#ifndef PAINTSTRATEGY_H
#define PAINTSTRATEGY_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include "IMouseMove.h"
class MapView;
class ChipsetView;

class PaintStrategy : public IMouseMove
{
public:
    PaintStrategy(MapView * mapView,ChipsetView * chipsetView);

	virtual void init();
	virtual void restore();

    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);

protected:
    MapView * mapView;
	ChipsetView * chipsetView;
};

#endif // PAINTSTRATEGY_H
