#include "PipetteStrategy.h"

PipetteStrategy::PipetteStrategy(MapView * mapView, ChipsetView * chipsetView)
    : PaintStrategy(mapView,chipsetView)
{
}

void PipetteStrategy::leftButtonPressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    chipsetView->selectTile(mapView->getMap()->getBloc(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE)->getLayer(mapView->getCurrentLayer()->getLayer()));
}

void PipetteStrategy::leftButtonMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    chipsetView->selectTile(mapView->getMap()->getBloc(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE)->getLayer(mapView->getCurrentLayer()->getLayer()));

}
