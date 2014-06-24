#include "CircleStrategy.h"

CircleStrategy::CircleStrategy(MapView *mapView, ChipsetView * chipsetView) : PaintStrategy(mapView,chipsetView)
{
}

void CircleStrategy::leftButtonPressEvent(int i, int j)
{
	layer = mapView->getCurrentLayer()+1;
}

void CircleStrategy::rightButtonPressEvent(int i, int j)
{
	layer = mapView->getCurrentLayer()+1;
	deb.setX(i);
	deb.setY(j);
	blit(i,j,0);
}

void CircleStrategy::leftButtonMoveEvent(int i, int j)
{
}

void CircleStrategy::rightButtonMoveEvent(int i, int j)
{
	fin.setX(i);
	fin.setY(j);
	mapView->removeLayer(ZIndex(layer));

	int height = qAbs(deb.y()-fin.y());
	int width = qAbs(deb.x()-fin.x());
	QPoint origin(qMin(deb.x(),fin.x())+width/2,qMin(deb.y(),fin.y())+height/2);
	int hh = height * height;
	int ww = width * width;
	int hhww = hh * ww;
	int x0 = width;
	int dx = 0;

	for (int y = 1; y <= height; y++)
	{
		int x1 = x0 - (dx - 1);
		for ( ; x1 > 0; x1--)
			if (x1*x1*hh + y*y*ww <= hhww)
				break;
		dx = x0 - x1;
		x0 = x1;

		for (int x = -x0/2; x <= x0/2; x++)
		{
			blit(origin.x() + x, origin.y() - y/2,0);
			blit(origin.x() + x, origin.y() + y/2,0);
		}
	}

	for (int x = -width/2; x <= width/2; x++)
		blit(origin.x() + x, origin.y(),0);

}

void CircleStrategy::leftButtonReleaseEvent(int i, int j)
{
}

void CircleStrategy::rightButtonReleaseEvent(int i, int j)
{
	fin.setX(i);
	fin.setY(j);
	mapView->removeLayer(ZIndex(layer));	

	int height = qAbs(deb.y()-fin.y());
	int width = qAbs(deb.x()-fin.x());
	QPoint origin(qMin(deb.x(),fin.x())+width/2,qMin(deb.y(),fin.y())+height/2);
	int hh = height * height;
	int ww = width * width;
	int hhww = hh * ww;
	int x0 = width;
	int dx = 0;

	for (int y = 1; y <= height; y++)
	{
		int x1 = x0 - (dx - 1);
		for ( ; x1 > 0; x1--)
			if (x1*x1*hh + y*y*ww <= hhww)
				break;
		dx = x0 - x1;
		x0 = x1;

		for (int x = -x0/2; x <= x0/2; x++)
		{
			EXECUTE_CMD(new EraseCommand(mapView->getMap(),origin.x() + x,origin.y() - y/2,mapView->getCurrentLayer()));
			EXECUTE_CMD(new EraseCommand(mapView->getMap(),origin.x() + x,origin.y() + y/2,mapView->getCurrentLayer()));
		}
	}

	for (int x = -width/2; x <= width/2; x++)
		EXECUTE_CMD(new EraseCommand(mapView->getMap(),origin.x() + x,origin.y(),mapView->getCurrentLayer()));
}

void CircleStrategy::blit(int i, int j, int bloc)
{
	mapView->removeTile(i,j,layer);
	mapView->blitTile(i,j,bloc,layer);
}
