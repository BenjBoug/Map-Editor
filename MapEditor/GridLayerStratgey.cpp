#include "GridLayerStratgey.h"

GridLayerStratgey::GridLayerStratgey(MapView * mapView)
{
    this->mapView = mapView;
}

void GridLayerStratgey::execute()
{
    Model::Map * map = mapView->getMap();
    QPen pen;
    pen.setColor(QColor(200,200,200));

    for(int i=0;i<map->getSize().height();i++)
        mapView->addLine(0,i*BLOCSIZE,map->getSize().width()*BLOCSIZE,i*BLOCSIZE,pen)->setZValue(GRID);


    for(int i=0;i<map->getSize().width();i++)
        mapView->addLine(i*BLOCSIZE,0,i*BLOCSIZE,map->getSize().height()*BLOCSIZE,pen)->setZValue(GRID);

}
