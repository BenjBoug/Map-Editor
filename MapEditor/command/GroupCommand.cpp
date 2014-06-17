#include "GroupCommand.h"

GroupCommand::GroupCommand()
{
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
