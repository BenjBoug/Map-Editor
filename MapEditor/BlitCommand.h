#ifndef BLITCOMMAND_H
#define BLITCOMMAND_H

#include "MapView.h"
#include "ICommand.h"

class BlitCommand : public ICommand
{
public:
    BlitCommand(MapView * mapView, int i,int j, int bloc, int layer, int opacity=0.3);
    virtual void execute();
    virtual void undo();
    virtual void redo();

private:
    MapView * mapView;
    int i,j,bloc,layer,opacity;
};

#endif // BLITCOMMAND_H
