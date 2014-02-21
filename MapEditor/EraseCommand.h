#ifndef ERASECOMMAND_H
#define ERASECOMMAND_H

#include "ICommand.h"
#include "MapView.h"

class EraseCommand : public ICommand
{
public:
    EraseCommand(MapView * mapView, int i, int j, int layer);
    virtual void execute();
    virtual void undo();
    virtual void redo();

private:
    MapView * mapView;
    int i,j,layer;
};

#endif // ERASECOMMAND_H
