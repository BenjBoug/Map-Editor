#ifndef LAYERSTRATEGY_H
#define LAYERSTRATEGY_H

class MapView;
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>

class LayerStrategy
{
public:
    LayerStrategy(MapView * mapView);
    virtual void display() =0;
    virtual int getLayer() = 0;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

protected:
    MapView * mapView;
    QPixmap chipset;
};

#endif // LAYERSTRATEGY_H
