#ifndef CHANGEDIMENSIONCOMMAND_H
#define CHANGEDIMENSIONCOMMAND_H

#include "ICommand.h"
#include "MapView.h"

class ChangeDimensionCommand : public ICommand
{
public:
    ChangeDimensionCommand(MapView * mapView, QSize newSize);

    virtual void execute();
    virtual void undo();

private:
    MapView * mapView;
    Model::Map mapMemento;
    QSize newSize;
    QSize sizeMemento;
};

#endif // CHANGEDIMENSIONCOMMAND_H
