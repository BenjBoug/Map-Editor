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
    mapView->getMap()->setChipset(file);
    chipsetView->loadChipset(file);
    mapView->loadChipset(file);
    mapView->displayMap();
    mapView->displayBackground();
}

void ChangeChipsetCommand::undo()
{
    mapView->getMap()->setChipset(fileMemento);
    chipsetView->loadChipset(fileMemento);
    mapView->loadChipset(fileMemento);
    mapView->displayMap();
    mapView->displayBackground();
}
