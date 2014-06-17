#include "PaintStrategy.h"
#include "MapView.h"
#include "ChipsetView.h"

PaintStrategy::PaintStrategy(MapView *mapView, ChipsetView *chipsetView)
{
    this->mapView=mapView;
	this->chipsetView=chipsetView;
}

void PaintStrategy::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	QVector<QVector<int> > selectedTile = chipsetView->getSelectedTile();
	if (mapView->sceneRect().contains(mouseEvent->scenePos()))
	{
		mapView->setCursorPos(((int)mouseEvent->scenePos().x()/BLOCSIZE),
					  ((int)mouseEvent->scenePos().y()/BLOCSIZE),
					  selectedTile.size(),
					  selectedTile[0].size());
	}


    IMouseMove::mouseMoveEvent(mouseEvent);
}
