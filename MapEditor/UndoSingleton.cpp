#include "UndoSingleton.h"

UndoSingleton * UndoSingleton::instance = NULL;

void UndoSingleton::execute(ICommand * cmd)
{
    cmd->execute();
    stackUndoCommand.push(cmd);
    emit redoEmpty(!stackRedoCommand.isEmpty());
    emit undoEmpty(!stackUndoCommand.isEmpty());
}

void UndoSingleton::undo()
{
    ICommand * cmdUndid = stackUndoCommand.pop();
    cmdUndid->undo();
    stackRedoCommand.push(cmdUndid);
    int id=cmdUndid->getId();
    while (!stackUndoCommand.isEmpty() && stackUndoCommand.top()->getId()==id)
    {
        cmdUndid = stackUndoCommand.pop();
        cmdUndid->undo();
        stackRedoCommand.push(cmdUndid);
    }

    emit redoEmpty(!stackRedoCommand.isEmpty());
    emit undoEmpty(!stackUndoCommand.isEmpty());
}

void UndoSingleton::redo()
{
    ICommand * cmdRedid = stackRedoCommand.pop();
    cmdRedid->execute();
    stackUndoCommand.push(cmdRedid);
    int id=cmdRedid->getId();
    while (!stackRedoCommand.isEmpty() && stackRedoCommand.top()->getId()==id)
    {
        cmdRedid = stackRedoCommand.pop();
        cmdRedid->execute();
        stackUndoCommand.push(cmdRedid);
    }

    emit redoEmpty(!stackRedoCommand.isEmpty());
    emit undoEmpty(!stackUndoCommand.isEmpty());
}

UndoSingleton::UndoSingleton()
{
}
