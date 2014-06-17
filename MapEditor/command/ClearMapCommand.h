#ifndef CLEARMAPCOMMAND_H
#define CLEARMAPCOMMAND_H

#include "ICommand.h"
#include "MapView.h"
#include <QDebug>

class ClearMapCommand : public ICommand
{
public:
	ClearMapCommand(Model::Map * map);

    void execute();
    void undo();

private:
	Model::Map * map;
    Model::Map mapMemento;
};

#endif // CLEARMAPCOMMAND_H
