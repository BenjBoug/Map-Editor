#ifndef GROUPCOMMAND_H
#define GROUPCOMMAND_H

#include "ICommand.h"

class GroupCommand : public ICommand
{
public:
	GroupCommand();

	virtual void execute();
	virtual void undo();

	void storeCommand(ICommand*);

private:
	QList<ICommand*> storedCommand;
};

#endif // GROUPCOMMAND_H
