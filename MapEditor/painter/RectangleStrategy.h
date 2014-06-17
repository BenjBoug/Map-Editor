#ifndef RECTANGLESTRATEGY_H
#define RECTANGLESTRATEGY_H

#include "PaintStrategy.h"

class RectangleStrategy : public PaintStrategy
{
public:
	RectangleStrategy(MapView * mapView, ChipsetView * chipsetView);

protected:
	virtual void leftButtonPressEvent(int i, int j);
	virtual void rightButtonPressEvent(int i,int j);

	virtual void leftButtonMoveEvent(int i,int j);
	virtual void rightButtonMoveEvent(int i,int j);

	virtual void leftButtonReleaseEvent(int i,int j);
	virtual void rightButtonReleaseEvent(int i,int j);

private:
	QRect rect;
};

#endif // RECTANGLESTRATEGY_H
