#ifndef BLITCOMMAND_H
#define BLITCOMMAND_H

#include "ICommand.h"
#include "MapView.h"

class BlitCommand : public ICommand
{
public:
    BlitCommand(MapView * mapView, int i, int j, int bloc);
    virtual void execute();
    virtual void undo();


private:
    MapView * mapView;
    int i,j,bloc;
    int layerMemento;
    int blocMemento;
};

#endif // BLITCOMMAND_H
