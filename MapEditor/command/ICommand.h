#ifndef COMMAND_H
#define COMMAND_H

#include <QDebug>

class ICommand
{
public:
	ICommand() {}

    virtual void execute() = 0;
    virtual void undo() = 0;
};
#endif // COMMAND_H
