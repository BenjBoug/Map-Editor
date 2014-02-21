#include "EraseAndBlitCommand.h"

EraseAndBlitCommand::EraseAndBlitCommand(MapView *mapView, int i, int j, int bloc, int layer, int opacity)
{
    eraseCmd = new EraseCommand(mapView,i,j,layer);
    blitCmd = new BlitCommand(mapView,i,j,bloc,layer,opacity);
}

void EraseAndBlitCommand::execute()
{
    eraseCmd->execute();
    blitCmd->execute();
}

void EraseAndBlitCommand::undo()
{
    blitCmd->undo();
    eraseCmd->undo();
}

void EraseAndBlitCommand::redo()
{
    eraseCmd->redo();
    blitCmd->redo();
}
