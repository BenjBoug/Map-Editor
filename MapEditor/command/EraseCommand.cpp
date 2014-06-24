#include "EraseCommand.h"

EraseCommand::EraseCommand(Model::Map *map, int i, int j, int layer)
{
	this->map = map;
    this->i=i;
    this->j=j;
	this->layer = layer;
}

void EraseCommand::execute()
{
	blocMemento=map->getBloc(i,j)->getAtLayer(layer);
	map->getBloc(i,j)->setLayer(layer,0);
}

void EraseCommand::undo()
{
	map->getBloc(i,j)->setLayer(layer,blocMemento);
}
