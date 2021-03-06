#include "ClearMapCommand.h"

ClearMapCommand::ClearMapCommand(Map *map)
{
	this->map = map;
}

void ClearMapCommand::execute()
{
    mapMemento  = *map;
    for(int i=0;i<map->getSize().width();i++)
    {
        for(int j=0;j<map->getSize().height();j++)
        {
            map->getBloc(i,j)->setLowLayer(0);
            map->getBloc(i,j)->setHighLayer(0);
            map->getBloc(i,j)->setCollisionLayer(0);
        }
    }
}

void ClearMapCommand::undo()
{
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
