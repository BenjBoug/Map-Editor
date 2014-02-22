#ifndef BLITCOMMAND_H
#define BLITCOMMAND_H

#include "MapView.h"
#include "ICommand.h"

class BlitCommand : public ICommand
{
public:
    BlitCommand(MapView * mapView, int i, int j, int bloc, int layer, float opacity=1);
    virtual void execute();
    virtual void undo();


private:
    MapView * mapView;
    int i,j,bloc,layer,opacity;

    int blocMemento;
    int layerMemento;
    float opacityMemento;
};

#endif // BLITCOMMAND_H
