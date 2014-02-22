#ifndef CHANGECHIPSETCOMMAND_H
#define CHANGECHIPSETCOMMAND_H

#include "ICommand.h"
#include "MapView.h"
#include "ChipsetView.h"
#include <QString>

class ChangeChipsetCommand : public ICommand
{
public:
    ChangeChipsetCommand(MapView * mapView,ChipsetView * chipsetView, QString file);

    virtual void execute();
    virtual void undo();

private:
    MapView * mapView;
    ChipsetView * chipsetView;
    QString file, fileMemento;
};

#endif // CHANGECHIPSETCOMMAND_H
