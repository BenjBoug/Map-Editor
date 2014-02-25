#include "MdiChild.h"

MdiChild::MdiChild(ChipsetView *chipsetView, QWidget *parent) :
    QGraphicsView(parent)
{
    this->chipsetView=chipsetView;
    this->setBackgroundBrush(QBrush(QColor(107, 189, 107)));
}

void MdiChild::newMap()
{
    mapView = new MapView();
    this->setScene(mapView);
}

void MdiChild::openMap(QString filename)
{
    map = new Map(filename);
    mapView = new MapView();
    lowLayerStrategy = new DisplayLowerLayerStrategy(mapView);
    brushStrategy = new BrushStrategy(mapView,chipsetView);
    mapView->setDisplayStrategy(lowLayerStrategy);
    mapView->setPaintStrategy(brushStrategy);
    mapView->setMap(map);
    this->setScene(mapView);
    this->chipsetView->loadChipset(map->getChipset());
}
