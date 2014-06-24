#ifndef ERASECOMMAND_H
#define ERASECOMMAND_H

#include "ICommand.h"
#include "Map.h"

class EraseCommand : public ICommand
{
public:
	EraseCommand(Model::Map *map, int i, int j, int layer);
    virtual void execute();
    virtual void undo();

private:
	Model::Map *map;
    int i,j;
	int blocMemento, layer;
};

#endif // ERASECOMMAND_H
