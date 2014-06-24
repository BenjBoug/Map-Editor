#ifndef CHANGEDIMENSIONCOMMAND_H
#define CHANGEDIMENSIONCOMMAND_H

#include "ICommand.h"
#include "Map.h"

class ChangeDimensionCommand : public ICommand
{
public:
	ChangeDimensionCommand(Model::Map * map, QSize newSize);

    virtual void execute();
    virtual void undo();

private:
	Model::Map * map;
    Model::Map mapMemento;
    QSize newSize;
    QSize sizeMemento;
};

#endif // CHANGEDIMENSIONCOMMAND_H
