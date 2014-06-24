#ifndef CIRCLESTRATEGY_H
#define CIRCLESTRATEGY_H

#include "PaintStrategy.h"
#include "ChipsetView.h"
#include "MapView.h"
#include "command/EraseCommand.h"
#include "command/BlitCommand.h"
#include "qmath.h"

class CircleStrategy : public PaintStrategy
{
public:
	CircleStrategy(MapView * mapView, ChipsetView * chipsetView);


protected:
	virtual void leftButtonPressEvent(int i, int j);
	virtual void rightButtonPressEvent(int i,int j);

	virtual void leftButtonMoveEvent(int i,int j);
	virtual void rightButtonMoveEvent(int i,int j);

	virtual void leftButtonReleaseEvent(int i,int j);
	virtual void rightButtonReleaseEvent(int i,int j);

private:
	void blit(int i, int j, int bloc);
	int layer;
	QPoint deb,fin;
};

#endif // CIRCLESTRATEGY_H
