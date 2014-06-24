#ifndef RECTANGLESTRATEGY_H
#define RECTANGLESTRATEGY_H

#include "PaintStrategy.h"
#include "MapView.h"
#include "ChipsetView.h"
#include "QPoint"
#include "command/EraseCommand.h"
#include "command/BlitCommand.h"

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
	void blit(int i, int j, int bloc);
	QPoint deb,fin;
	int layer;
};

#endif // RECTANGLESTRATEGY_H
