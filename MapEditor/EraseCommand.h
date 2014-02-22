#ifndef ERASECOMMAND_H
#define ERASECOMMAND_H

#include "ICommand.h"
#include "MapView.h"

class EraseCommand : public ICommand
{
public:
    EraseCommand(MapView * mapView, int i, int j);
    virtual void execute();
    virtual void undo();

private:
    MapView * mapView;
    int i,j;
    int blocMemento, layerMemento;
};

#endif // ERASECOMMAND_H
