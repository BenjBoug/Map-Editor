#include "BrushStrategy.h"

BrushStrategy::BrushStrategy(MapView *mapView, ChipsetView *chipsetView)
    : PaintStrategy(mapView,chipsetView)
{
    inSelect = false;
    inSelectRight = false;
    rectItem = mapView->addRect(0,0,50,50);
    rectItem->setZValue(CURSOR);
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
        mapView->getLayerStrategy()->eraseBloc();
        inSelectRight = true;
    }
}

void BrushStrategy::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QVector<QVector<int> > selectedTile = chipsetView->getSelectedTile();
    if (mapView->sceneRect().contains(mouseEvent->scenePos()))
    {
    rectItem->setRect(((int)mouseEvent->scenePos().x()/BLOCSIZE)*BLOCSIZE,
                      ((int)mouseEvent->scenePos().y()/BLOCSIZE)*BLOCSIZE,
                      selectedTile.size()*BLOCSIZE,
                      selectedTile[0].size()*BLOCSIZE);
    }
    else
    {
        rectItem = mapView->addRect(0,0,0,0);
    }
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

}

void BrushStrategy::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() == Qt::LeftButton)
    {
    inSelect = false;
    }
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
            mapView->getLayerStrategy()->setBloc(i+xMouse,j+yMouse,selectedTile[i][j]);
        }
    }
    blited.setX(xMouse);
    blited.setY(yMouse);
    blited.setWidth(selectedTile.size());
    blited.setHeight(selectedTile[0].size());
}
