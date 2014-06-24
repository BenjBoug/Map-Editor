#include "GroupCommand.h"

GroupCommand::GroupCommand()
{
}

GroupCommand::~GroupCommand()
{
	foreach(ICommand * cmd, storedCommand)
		delete cmd;
}

void GroupCommand::execute()
{
	foreach(ICommand* cmd, storedCommand)
	{
		cmd->execute();
	}
}

void GroupCommand::undo()
{
	for(int i=storedCommand.size()-1;i>=0;i--)
	{
		storedCommand[i]->undo();
	}
}

void GroupCommand::storeCommand(ICommand * cmd)
{
	storedCommand.append(cmd);
}

int GroupCommand::getNbCommand() const
{
	return storedCommand.size();
}
