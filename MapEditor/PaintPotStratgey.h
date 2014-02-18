#ifndef PAINTPOTSTRATGEY_H
#define PAINTPOTSTRATGEY_H

#include "MapStrategy.h"

class PaintPotStratgey : public MapStrategy
{
public:
    PaintPotStratgey(MapView * mapView, ChipsetView * chipsetView);

    virtual void execute();
};

#endif // PAINTPOTSTRATGEY_H
