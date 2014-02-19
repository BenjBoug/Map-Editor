#include "MapView.h"

MapView::MapView():
    QGraphicsScene()
{
    zoom = 1;
    this->map = new Model::Map();
    gridStrategy = NULL;
}

MapView::MapView(Model::Map * m) :
    QGraphicsScene()
{
    zoom = 1;
    gridStrategy = NULL;
    setMap(m);
}

void MapView::setMap(Model::Map *map)
{
    this->map = map;
    chipset.load(map->getChipset());
    QBitmap mask = chipset.createMaskFromColor(QColor(255, 103, 139));
    chipset.setMask(mask);
    //connect(map,SIGNAL(mapChanged()),this,SLOT(displayMap()));
    displayMap();
}

void MapView::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    paintStrategy->execute();
}

void MapView::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    paintStrategy->execute();
}

void MapView::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}

void MapView::setPaintStrategy(PaintStrategy *stra)
{
    paintStrategy=stra;
}

void MapView::setDisplayStrategy(LayerStrategy *stra)
{
    displayStrategy = stra;
}

void MapView::setGridStrategy(IStrategy *stra)
{
    gridStrategy = stra;
}

QPixmap MapView::getChipset()
{
    return chipset;
}

Model::Map *MapView::getMap()
{
    return map;
}

LayerStrategy *MapView::getLayerStrategy()
{
    return displayStrategy;
}

void MapView::displayMap()
{
    displayStrategy->execute();
    if (gridStrategy != NULL)
        gridStrategy->execute();
}

