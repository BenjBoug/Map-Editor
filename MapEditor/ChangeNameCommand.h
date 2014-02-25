#ifndef CHANGENAMECOMMAND_H
#define CHANGENAMECOMMAND_H

#include "ICommand.h"
#include "QString"
#include "Map.h"

class ChangeNameCommand : public ICommand
{
public:
    ChangeNameCommand(Model::Map * map, QString newName);

    void execute();
    void undo();

private:
    QString newName;
    QString nameMemento;
    Model::Map * map;
};

#endif // CHANGENAMECOMMAND_H
