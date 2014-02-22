#include "BrushStrategy.h"

BrushStrategy::BrushStrategy(MapView *mapView, ChipsetView *chipsetView)
    : PaintStrategy(mapView,chipsetView)
{
    inSelect = false;
    inSelectRight = false;
    idCmd = 0;
}

void BrushStrategy::leftButtonPressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    blit(mouseEvent->scenePos());
}

void BrushStrategy::rightButtonPressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    blited.setX(mouseEvent->scenePos().x()/BLOCSIZE);
    blited.setY(mouseEvent->scenePos().y()/BLOCSIZE);
    blited.setWidth(1);
    blited.setHeight(1);
    UndoSingleton::getInstance()->execute(new EraseCommand(mapView,mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE));
}

void BrushStrategy::leftButtonMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QVector<QVector<int> > selectedTile = chipsetView->getSelectedTile();
    QRect newBlit;
    int xMouse = mouseEvent->scenePos().x() / BLOCSIZE;
    int yMouse = mouseEvent->scenePos().y() / BLOCSIZE;
    newBlit.setX(xMouse);
    newBlit.setY(yMouse);
    newBlit.setWidth(selectedTile.size());
    newBlit.setHeight(selectedTile[0].size());
    if (!newBlit.intersects(blited))
    {
        blit(mouseEvent->scenePos());
    }
}

void BrushStrategy::rightButtonMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QRect newBlit;
    int xMouse = mouseEvent->scenePos().x() / BLOCSIZE;
    int yMouse = mouseEvent->scenePos().y() / BLOCSIZE;
    newBlit.setX(xMouse);
    newBlit.setY(yMouse);
    newBlit.setWidth(BLOCSIZE);
    newBlit.setHeight(BLOCSIZE);
    if (!newBlit.intersects(blited))
        UndoSingleton::getInstance()->execute(new EraseCommand(mapView,mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE));

}

void BrushStrategy::blit(QPointF pos)
{
    int xMouse = pos.x() / BLOCSIZE;
    int yMouse = pos.y() / BLOCSIZE;
    QVector<QVector<int> > selectedTile = chipsetView->getSelectedTile();

    for(int i=0;i<selectedTile.size();i++)
    {
        for(int j=0;j<selectedTile[i].size();j++)
        {
            UndoSingleton::getInstance()->execute(new BlitCommand(mapView,i+xMouse,j+yMouse,selectedTile[i][j]));
        }
    }
    blited.setX(xMouse);
    blited.setY(yMouse);
    blited.setWidth(selectedTile.size());
    blited.setHeight(selectedTile[0].size());
}
