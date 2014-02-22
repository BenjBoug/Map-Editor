#include "PaintStrategy.h"
#include "MapView.h"
#include "ChipsetView.h"

PaintStrategy::PaintStrategy(MapView *mapView, ChipsetView *chipsetView)
{
    this->mapView=mapView;
    this->chipsetView=chipsetView;
    rectItem = mapView->addRect(0,0,50,50);
    rectItem->setZValue(CURSOR);
}

void PaintStrategy::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}

void PaintStrategy::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
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
}

void PaintStrategy::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}
