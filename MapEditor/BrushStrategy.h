#ifndef BRUSHSTRATEGY_H
#define BRUSHSTRATEGY_H

#include "PaintStrategy.h"
#include <QVector>
#include <QDebug>
#include "MapView.h"
#include "ChipsetView.h"

class BrushStrategy : public PaintStrategy
{
public:
    BrushStrategy(MapView * mapView, ChipsetView * chipsetView);

    virtual void execute();

private:
};

#endif // BRUSHSTRATEGY_H
