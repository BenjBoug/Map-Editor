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
    blited.setX(i);
    blited.setY(j);
    blited.setWidth(1);
    blited.setHeight(1);
    UndoSingleton::getInstance()->execute(new EraseCommand(mapView,i,j));
}

void BrushStrategy::leftButtonMoveEvent(int i, int j)
{
    QVector<QVector<int> > selectedTile = chipsetView->getSelectedTile();
    QRect newBlit;
    newBlit.setX(i);
    newBlit.setY(j);
    newBlit.setWidth(selectedTile.size());
    newBlit.setHeight(selectedTile[0].size());
    if (!newBlit.intersects(blited))
    {
        blit(i,j);
    }
}

void BrushStrategy::rightButtonMoveEvent(int i, int j)
{
    QRect newBlit;
    newBlit.setX(i);
    newBlit.setY(j);
    newBlit.setWidth(BLOCSIZE);
    newBlit.setHeight(BLOCSIZE);
    if (!newBlit.intersects(blited))
        UndoSingleton::getInstance()->execute(new EraseCommand(mapView,i,j));

}

void BrushStrategy::blit(int x, int y)
{
    QVector<QVector<int> > selectedTile = chipsetView->getSelectedTile();

    for(int i=0;i<selectedTile.size();i++)
    {
        for(int j=0;j<selectedTile[i].size();j++)
        {
            UndoSingleton::getInstance()->execute(new BlitCommand(mapView,i+x,j+y,selectedTile[i][j]));
        }
    }
    blited.setX(x);
    blited.setY(y);
    blited.setWidth(selectedTile.size());
    blited.setHeight(selectedTile[0].size());
}
