#include "ChangeChipsetCommand.h"

ChangeChipsetCommand::ChangeChipsetCommand(MapView *mapView, ChipsetView *chipsetView, QString file)
{
    this->mapView=mapView;
    this->chipsetView=chipsetView;
    this->file=file;
}

void ChangeChipsetCommand::execute()
{
    fileMemento = mapView->getMap()->getChipset();
    mapView->getMap()->setNameChipset(file);
    chipsetView->loadChipset(file);
    mapView->loadChipset(file);
    mapView->displayMap();
}

void ChangeChipsetCommand::undo()
{
    mapView->getMap()->setNameChipset(fileMemento);
    chipsetView->loadChipset(fileMemento);
    mapView->loadChipset(fileMemento);
    mapView->displayMap();
}
