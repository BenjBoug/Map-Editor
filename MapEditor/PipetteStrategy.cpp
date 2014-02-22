#include "PipetteStrategy.h"

PipetteStrategy::PipetteStrategy(MapView * mapView, ChipsetView * chipsetView)
    : PaintStrategy(mapView,chipsetView)
{
}

void PipetteStrategy::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    chipsetView->selectTile(mapView->getMap()->getBloc(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE)->getLayer(mapView->getLayerStrategy()->getLayer()));
}


void PipetteStrategy::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}
