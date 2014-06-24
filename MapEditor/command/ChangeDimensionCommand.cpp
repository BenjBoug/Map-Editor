#include "ChangeDimensionCommand.h"

ChangeDimensionCommand::ChangeDimensionCommand(Model::Map * map, QSize newSize)
{
    this->newSize=newSize;
	this->map=map;
}

void ChangeDimensionCommand::execute()
{
	//save the map
    mapMemento  = *map;
	//sav the previous size
	sizeMemento = map->getSize();
	//set the size of the map
	map->setSize(newSize);
}

void ChangeDimensionCommand::undo()
{
	//set the size with the memento
    map->setSize(sizeMemento);
	//restore the map
	for(int i=0;i<map->getSize().width();i++)
    {
		for(int j=0;j<map->getSize().height();j++)
        {
            map->getBloc(i,j)->setLowLayer(mapMemento.getBloc(i,j)->getLowLayer());
            map->getBloc(i,j)->setHighLayer(mapMemento.getBloc(i,j)->getHighLayer());
            map->getBloc(i,j)->setCollisionLayer(mapMemento.getBloc(i,j)->getCollisionLayer());
        }
	}
}
