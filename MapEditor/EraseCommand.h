#ifndef ERASECOMMAND_H
#define ERASECOMMAND_H

#include "ICommand.h"
#include "MapView.h"

class EraseCommand : public ICommand
{
public:
    EraseCommand(MapView * mapView, int i, int j, int layer,float opacity = 1);
    virtual void execute();
    virtual void undo();

private:
    MapView * mapView;
    int i,j,layer;
    float opacityMemento;
    int blocMemento;
};

#endif // ERASECOMMAND_H
