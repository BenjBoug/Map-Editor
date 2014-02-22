#ifndef ERASEANDBLITCOMMAND_H
#define ERASEANDBLITCOMMAND_H

#include "BlitCommand.h"
#include "EraseCommand.h"
#include "MapView.h"

class EraseAndBlitCommand : public ICommand
{
public:
    EraseAndBlitCommand(MapView * mapView, int i,int j, int bloc, int layer, float opacity=1);
    virtual void execute();
    virtual void undo();

private:
    BlitCommand * blitCmd;
    EraseCommand * eraseCmd;
    MapView * mapView;
    int i,j;
    int blocMemento;
    int layerMemento;
    float opacityMemento;
};

#endif // ERASEANDBLITCOMMAND_H
