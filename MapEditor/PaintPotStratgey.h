#ifndef PAINTPOTSTRATGEY_H
#define PAINTPOTSTRATGEY_H

#include "PaintStrategy.h"
#include <QDebug>

class PaintPotStratgey : public PaintStrategy
{
public:
    PaintPotStratgey(MapView * mapView, ChipsetView * chipsetView);

    virtual void execute();
};

#endif // PAINTPOTSTRATGEY_H
