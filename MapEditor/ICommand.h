#ifndef COMMAND_H
#define COMMAND_H

class ICommand
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
    //virtual int getId() = 0;
};

#endif // COMMAND_H
