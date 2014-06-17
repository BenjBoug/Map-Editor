#ifndef LAYERSTRATEGY_H
#define LAYERSTRATEGY_H

#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include "command/ICommand.h"
#include "IMouseMove.h"
class MapView;

class LayerStrategy : public IMouseMove
{
public:
    LayerStrategy(MapView * mapView);
    virtual void display() =0;
    virtual int getLayer() = 0;

protected:
    MapView * mapView;
    QPixmap chipset;
};

#endif // LAYERSTRATEGY_H
