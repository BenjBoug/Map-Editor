#ifndef CLEARMAPCOMMAND_H
#define CLEARMAPCOMMAND_H

#include "ICommand.h"
#include "MapView.h"
#include <QDebug>

class ClearMapCommand : public ICommand
{
public:
    ClearMapCommand(MapView* mapView);

    void execute();
    void undo();

private:
    MapView * mapView;
    Model::Map mapMemento;
};

#endif // CLEARMAPCOMMAND_H
