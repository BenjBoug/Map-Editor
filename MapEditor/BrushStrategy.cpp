#include "BrushStrategy.h"

BrushStrategy::BrushStrategy(MapView *mapView, ChipsetView *chipsetView)
    : MapStrategy(mapView,chipsetView)
{
}

void BrushStrategy::execute()
{
    qDebug() << "brush !";
}
