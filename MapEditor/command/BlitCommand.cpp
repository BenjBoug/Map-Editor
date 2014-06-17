#include "BlitCommand.h"

BlitCommand::BlitCommand(Map *map, int i, int j, int layer, int bloc)
{
	this->map=map;
    this->i=i;
    this->j=j;
    this->bloc=bloc;
	this->layerMemento=layer;
}

void BlitCommand::execute()
{
	blocMemento=map->getBloc(i,j)->getAtLayer(layerMemento);
	map->getBloc(i,j)->setLayer(layerMemento,bloc);
}

void BlitCommand::undo()
{
	map->getBloc(i,j)->setLayer(layerMemento,blocMemento);
}
