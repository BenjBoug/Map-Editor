#include "UndoSingleton.h"

UndoSingleton * UndoSingleton::instance = NULL;

/**
 * @brief Execute the command immediatly, and store it in the Undo Stack.
 * @param cmd the command to execute
 */
void UndoSingleton::execute(ICommand * cmd)
{
    cmd->execute();
	if (!inGroup)
	{
		cmdExecuted(cmd);
	}
	else
	{
		groupCmd->storeCommand(cmd);
	}
}

void UndoSingleton::beginGroup()
{
	if (!inGroup)
	{
		groupCmd=new GroupCommand();
		inGroup=true;
	}
}

void UndoSingleton::endGroup()
{
	if (groupCmd!=NULL && inGroup)
	{
		cmdExecuted(groupCmd);
		groupCmd=NULL;
		inGroup=false;
	}
}

void UndoSingleton::clearUndo()
{
    stackUndoCommand.clear();
    emit undoEmpty(!stackUndoCommand.isEmpty());
}

void UndoSingleton::clearRedo()
{
    stackRedoCommand.clear();
    emit redoEmpty(!stackRedoCommand.isEmpty());
}

void UndoSingleton::undo()
{
    ICommand * cmdUndid = stackUndoCommand.pop();
	cmdUndid->undo();
	cmdCanceled(cmdUndid);
}

void UndoSingleton::redo()
{
    ICommand * cmdRedid = stackRedoCommand.pop();
	cmdRedid->execute();
	cmdExecuted(cmdRedid);
}

void UndoSingleton::cmdExecuted(ICommand *cmd)
{
	stackUndoCommand.push(cmd);
	emit redoEmpty(!stackRedoCommand.isEmpty());
	emit undoEmpty(!stackUndoCommand.isEmpty());
}

void UndoSingleton::cmdCanceled(ICommand *cmd)
{
	stackRedoCommand.push(cmd);
	emit redoEmpty(!stackRedoCommand.isEmpty());
	emit undoEmpty(!stackUndoCommand.isEmpty());
}

UndoSingleton::UndoSingleton()
{
	groupCmd=NULL;
	inGroup = false;
}
