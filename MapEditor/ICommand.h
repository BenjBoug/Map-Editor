#ifndef COMMAND_H
#define COMMAND_H

#include <QDebug>

class ICommand
{
public:
    ICommand()
    {
        id=idCMD;
    }

    virtual void execute() = 0;
    virtual void undo() = 0;
    int getId()
    {
        return id;
    }
    void setId(int id)
    {
        this->id=id;
    }

    static void begin()
    {

    }

    static void end()
    {
        idCMD++;
    }

protected:
    int id;
    static int idCMD;
};
#endif // COMMAND_H
