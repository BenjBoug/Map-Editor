#include "PaintPotStratgey.h"

PaintPotStratgey::PaintPotStratgey(MapView * mapView, ChipsetView * chipsetView)
    : MapStrategy(mapView,chipsetView)
{
}

void PaintPotStratgey::execute()
{
    qDebug() << "paint pot";
}
