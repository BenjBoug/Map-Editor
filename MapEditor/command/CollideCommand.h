#ifndef COLLIDECOMMAND_H
#define COLLIDECOMMAND_H

#include "ICommand.h"
#include "MapView.h"
#include "EraseCommand.h"

class CollideCommand : public ICommand
{
public:
    CollideCommand(MapView * mapView, int i, int j, int collide);
    virtual void execute();
    virtual void undo();

private:

    MapView * mapView;
    int i,j,collide;
    int collideMemento;

};

#endif // COLLIDECOMMAND_H
