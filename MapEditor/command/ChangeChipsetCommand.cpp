#include "ChangeChipsetCommand.h"

ChangeChipsetCommand::ChangeChipsetCommand(Model::Map* map, QString file)
{
	this->map=map;
	this->chipset.load(file);
	this->chipsetMemento=map->getChipset();
}

void ChangeChipsetCommand::execute()
{
	map->setChipset(chipset);
}

void ChangeChipsetCommand::undo()
{
	map->setChipset(chipsetMemento);
}
