#include "BrushStrategy.h"

BrushStrategy::BrushStrategy(MapView *mapView, ChipsetView *chipsetView)
    : PaintStrategy(mapView,chipsetView)
{
    inSelect = false;
    inSelectRight = false;
    idCmd = 0;
}

void BrushStrategy::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    if (mouseEvent->button() == Qt::LeftButton)
    {
        blit(mouseEvent->scenePos());
        inSelect = true;
    }
    else if (mouseEvent->button() == Qt::RightButton)
    {

        blited.setX(mouseEvent->scenePos().x()/BLOCSIZE);
        blited.setY(mouseEvent->scenePos().y()/BLOCSIZE);
        blited.setWidth(1);
        blited.setHeight(1);
        mapView->executeCmd(new EraseCommand(mapView,mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE,mapView->getLayerStrategy()->getLayer(),1));
       inSelectRight = true;
    }
}

void BrushStrategy::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    PaintStrategy::mouseMoveEvent(mouseEvent);
    QVector<QVector<int> > selectedTile = chipsetView->getSelectedTile();

    if (inSelect)
    {
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
    else if (inSelectRight)
    {
        QRect newBlit;
        int xMouse = mouseEvent->scenePos().x() / BLOCSIZE;
        int yMouse = mouseEvent->scenePos().y() / BLOCSIZE;
        newBlit.setX(xMouse);
        newBlit.setY(yMouse);
        newBlit.setWidth(BLOCSIZE);
        newBlit.setHeight(BLOCSIZE);
        if (!newBlit.intersects(blited))
            mapView->executeCmd(new EraseCommand(mapView,mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE,mapView->getLayerStrategy()->getLayer(),1));
    }

}

void BrushStrategy::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() == Qt::LeftButton)
    {
        inSelect = false;
    }

    if (mouseEvent->button() == Qt::RightButton)
    {
        inSelectRight = false;
    }
    ICommand::end();
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
            mapView->executeCmd(new EraseAndBlitCommand(mapView,i+xMouse,j+yMouse,selectedTile[i][j],mapView->getLayerStrategy()->getLayer(),1));
        }
    }
    blited.setX(xMouse);
    blited.setY(yMouse);
    blited.setWidth(selectedTile.size());
    blited.setHeight(selectedTile[0].size());
}
