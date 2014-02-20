#ifndef LAYERSTRATEGY_H
#define LAYERSTRATEGY_H

class MapView;
#include <QRect>
#include <QList>
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsPixmapItem>

class LayerStrategy
{
public:
    LayerStrategy(MapView * mapView);
    virtual void display() =0;
    virtual void setBloc(int i, int j, int bloc) = 0;
    virtual void blitBloc(int i, int j, int bloc, int layer,float opacity=1);
    virtual void eraseBloc(int i,int j,int layer);
    virtual void eraseAndBlitBloc(int i, int j, int bloc, int layer, float opacity=1);

protected:
    MapView * mapView;
    QPixmap chipset;
};

#endif // LAYERSTRATEGY_H
