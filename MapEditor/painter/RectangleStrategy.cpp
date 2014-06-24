#include "RectangleStrategy.h"

RectangleStrategy::RectangleStrategy(MapView *mapView, ChipsetView * chipsetView) : PaintStrategy(mapView,chipsetView)
{
}

void RectangleStrategy::leftButtonPressEvent(int i, int j)
{
	layer = mapView->getCurrentLayer()+1;
	deb.setX(i);
	deb.setY(j);
	QVector<QVector<int> > blocs = chipsetView->getSelectedTile();
	blit(i,j,blocs[0][0]);
}

void RectangleStrategy::rightButtonPressEvent(int i, int j)
{
	layer = mapView->getCurrentLayer()+1;
	deb.setX(i);
	deb.setY(j);
	blit(i,j,0);
}

void RectangleStrategy::leftButtonMoveEvent(int i, int j)
{
	QVector<QVector<int> > blocs = chipsetView->getSelectedTile();
	int cmpY = 0;
	int cmpX = 0;
	fin.setX(i);
	fin.setY(j);
	mapView->removeLayer(ZIndex(layer));
	int debX = qMin(deb.x(),fin.x());
	int debY = qMin(deb.y(),fin.y());
	int finX = qAbs(deb.x()-fin.x())+1;
	int finY = qAbs(deb.y()-fin.y())+1;
	for(int x=0;x<finX;x++)
	{
		for(int y=0;y<finY;y++)
		{
			int sizeX = blocs.size();
			int sizeY = blocs[0].size();
			cmpX = x % sizeX;
			cmpY = y % sizeY;
			blit(x+debX,y+debY,blocs[cmpX][cmpY]);
		}
	}
}

void RectangleStrategy::rightButtonMoveEvent(int i, int j)
{
	fin.setX(i);
	fin.setY(j);
	mapView->removeLayer(ZIndex(layer));
	int debX = qMin(deb.x(),fin.x());
	int debY = qMin(deb.y(),fin.y());
	int finX = qAbs(deb.x()-fin.x())+1;
	int finY = qAbs(deb.y()-fin.y())+1;
	for(int x=debX;x<debX+finX;x++)
	{
		for(int y=debY;y<debY+finY;y++)
		{
			blit(x,y,0);
		}
	}
}

void RectangleStrategy::leftButtonReleaseEvent(int i, int j)
{
	QVector<QVector<int> > blocs = chipsetView->getSelectedTile();
	int cmpY = 0;
	int cmpX = 0;
	fin.setX(i);
	fin.setY(j);
	mapView->removeLayer(ZIndex(layer));
	int debX = qMin(deb.x(),fin.x());
	int debY = qMin(deb.y(),fin.y());
	int finX = qAbs(deb.x()-fin.x())+1;
	int finY = qAbs(deb.y()-fin.y())+1;
	for(int x=0;x<finX;x++)
	{
		for(int y=0;y<finY;y++)
		{
			int sizeX = blocs.size();
			int sizeY = blocs[0].size();
			cmpX = x % sizeX;
			cmpY = y % sizeY;
			EXECUTE_CMD(new BlitCommand(mapView->getMap(),x+debX,y+debY,mapView->getCurrentLayer(),blocs[cmpX][cmpY]));
		}
	}
}

void RectangleStrategy::rightButtonReleaseEvent(int i, int j)
{
	fin.setX(i);
	fin.setY(j);
	mapView->removeLayer(ZIndex(layer));
	int debX = qMin(deb.x(),fin.x());
	int debY = qMin(deb.y(),fin.y());
	int finX = qAbs(deb.x()-fin.x())+1;
	int finY = qAbs(deb.y()-fin.y())+1;
	for(int x=debX;x<debX+finX;x++)
	{
		for(int y=debY;y<debY+finY;y++)
		{
			EXECUTE_CMD(new EraseCommand(mapView->getMap(),x,y,mapView->getCurrentLayer()));
		}
	}
}

void RectangleStrategy::blit(int i, int j, int bloc)
{
	mapView->removeTile(i,j,layer);
	mapView->blitTile(i,j,bloc,layer);
}
