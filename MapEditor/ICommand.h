#ifndef COMMAND_H
#define COMMAND_H

class ICommand
{
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
};

#endif // COMMAND_H
