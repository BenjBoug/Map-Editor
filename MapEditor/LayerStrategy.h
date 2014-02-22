#ifndef LAYERSTRATEGY_H
#define LAYERSTRATEGY_H

class MapView;
#include <QPixmap>

class LayerStrategy
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
