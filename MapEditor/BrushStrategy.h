#ifndef BRUSHSTRATEGY_H
#define BRUSHSTRATEGY_H

#include "MapStrategy.h"
#include <QVector>

class BrushStrategy : public MapStrategy
{
public:
    BrushStrategy(MapView * mapView, ChipsetView * chipsetView);

    virtual void execute();

private:
};

#endif // BRUSHSTRATEGY_H
