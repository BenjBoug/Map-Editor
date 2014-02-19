#include "PaintPotStratgey.h"

PaintPotStratgey::PaintPotStratgey(MapView * mapView, ChipsetView * chipsetView)
    : PaintStrategy(mapView,chipsetView)
{
}

void PaintPotStratgey::execute()
{
    qDebug() << "paint pot";
}
