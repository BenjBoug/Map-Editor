#ifndef CHANGECHIPSETCOMMAND_H
#define CHANGECHIPSETCOMMAND_H

#include "ICommand.h"
#include "MapView.h"
#include "ChipsetView.h"
#include <QString>
#include <Map.h>

class ChangeChipsetCommand : public ICommand
{
public:
	ChangeChipsetCommand(Model::Map* map, QString file);

    virtual void execute();
    virtual void undo();

private:
	Model::Map* map;
	QPixmap chipset;
	QPixmap chipsetMemento;
};

#endif // CHANGECHIPSETCOMMAND_H
