#ifndef PAINTPOTSTRATGEY_H
#define PAINTPOTSTRATGEY_H

#include "PaintStrategy.h"
#include <QDebug>
#include "MapView.h"
#include "ChipsetView.h"
#include "command/BlitCommand.h"
#include "command/EraseCommand.h"
#include "UndoSingleton.h"

class PaintPotStrategy : public PaintStrategy
{
public:
    PaintPotStrategy(MapView * mapView, ChipsetView * chipsetView);

    void leftButtonPressEvent(int i, int j);
    void rightButtonPressEvent(int i, int j);

    void paintPot(int i,int j, int blocRef);
    void erase(int i,int j,int blocRef);

private:
};

#endif // PAINTPOTSTRATGEY_H
