#include "ChangeNameCommand.h"

ChangeNameCommand::ChangeNameCommand(Model::Map *map,QString newName)
{
    this->newName=newName;
    this->map=map;
}

void ChangeNameCommand::execute()
{
    this->nameMemento=map->getName();
    this->map->setName(newName);
}

void ChangeNameCommand::undo()
{
    this->map->setName(nameMemento);
}
