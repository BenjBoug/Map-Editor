#include "ClipBoardSingleton.h"

ClipBoardSingleton * ClipBoardSingleton::instance = NULL;

ClipBoardSingleton::ClipBoardSingleton()
{
	emit pasteReady(false);
}


void ClipBoardSingleton::copy(MapView *mapView, QRect tiles)
{
	this->rect=tiles;
	tileCopied.clear();
	for(int i=tiles.left()/BLOCSIZE;i<=tiles.right()/BLOCSIZE;i++)
	{
		QVector<int> vec;
		for(int j=tiles.top()/BLOCSIZE;j<=tiles.bottom()/BLOCSIZE;j++)
		{
			vec.append(mapView->getMap()->getBloc(i,j)->getAtLayer(mapView->getCurrentLayer()));
		}
		tileCopied.append(vec);
	}
	emit pasteReady(true);


	QApplication::clipboard()->setPixmap(mapView->getPixmap(tiles));
}

void ClipBoardSingleton::paste(MapView *mapView, int i, int j)
{
	CMD_BEGIN();

	for(int x=0;x<tileCopied.size();x++)
	{
		for(int y=0;y<tileCopied[0].size();y++)
		{
			EXECUTE_CMD(new BlitCommand(mapView->getMap(),i+x,j+y,mapView->getCurrentLayer(),tileCopied[x][y]));
		}
	}

	CMD_END();
}

QRect ClipBoardSingleton::getRectSelected() const
{
	return rect;
}
