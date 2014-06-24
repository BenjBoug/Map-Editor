#include "BrushStrategy.h"

BrushStrategy::BrushStrategy(MapView *mapView, ChipsetView *chipsetView)
    : PaintStrategy(mapView,chipsetView)
{
    inSelect = false;
    inSelectRight = false;
    idCmd = 0;
}

void BrushStrategy::leftButtonPressEvent(int i, int j)
{
    blit(i,j);
}

void BrushStrategy::rightButtonPressEvent(int i, int j)
{
	EXECUTE_CMD(new EraseCommand(mapView->getMap(),i,j, mapView->getCurrentLayer()));
	blited.setRect(i,j,1,1);
}

void BrushStrategy::leftButtonMoveEvent(int i, int j)
{
    QVector<QVector<int> > selectedTile = chipsetView->getSelectedTile();
	if (isntInBlitted(i,j,selectedTile.size(),selectedTile[0].size()))
    {
        blit(i,j);
    }
}

void BrushStrategy::rightButtonMoveEvent(int i, int j)
{
	if (isntInBlitted(i,j))
	{
		EXECUTE_CMD(new EraseCommand(mapView->getMap(),i,j, mapView->getCurrentLayer()));
		blited.setRect(i,j,1,1);
	}
}

bool BrushStrategy::isntInBlitted(int x, int y, int w, int h) const
{
	return !QRect(x,y,w,h).intersects(blited);
}

void BrushStrategy::blit(int x, int y)
{
    QVector<QVector<int> > selectedTile = chipsetView->getSelectedTile();
    QSize size = mapView->getMap()->getSize();
    for(int i=0;i<selectedTile.size();i++)
    {
        for(int j=0;j<selectedTile[i].size();j++)
        {
			if (i+x<size.width() && j+y<size.height())
				EXECUTE_CMD(new BlitCommand(mapView->getMap(),i+x,j+y,mapView->getCurrentLayer(),selectedTile[i][j]));
        }
    }
    blited.setX(x);
    blited.setY(y);
    blited.setWidth(selectedTile.size());
    blited.setHeight(selectedTile[0].size());
}
