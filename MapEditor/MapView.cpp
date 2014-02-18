#include "MapView.h"

MapView::MapView():
    QGraphicsScene()
{
    zoom = 1;
    this->map = new Model::Map();
}

MapView::MapView(Model::Map * m) :
    QGraphicsScene()
{
    zoom = 1;
    setMap(m);
}

void MapView::setMap(Model::Map *map)
{
    this->map = map;
    chipset.load(map->getChipset());
    QBitmap mask = chipset.createMaskFromColor(QColor(255, 103, 139));
    chipset.setMask(mask);
    displayMap();
}

void MapView::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    paintStrategy->execute();
}

void MapView::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}

void MapView::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}

void MapView::setPaintStrategy(IStrategy *stra)
{
    paintStrategy=stra;
}

void MapView::setDisplayStrategy(IStrategy *stra)
{
    displayStrategy = stra;
}

QPixmap MapView::getChipset()
{
    return chipset;
}

Model::Map *MapView::getMap()
{
    return map;
}

void MapView::displayMap()
{
    displayStrategy->execute();
}

