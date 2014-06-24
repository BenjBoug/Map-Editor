#ifndef GROUPCOMMAND_H
#define GROUPCOMMAND_H

#include "ICommand.h"

class GroupCommand : public ICommand
{
public:
	GroupCommand();
	~GroupCommand();

	virtual void execute();
	virtual void undo();

	void storeCommand(ICommand*);

	int getNbCommand() const;

private:
	QList<ICommand*> storedCommand;
};

#endif // GROUPCOMMAND_H
