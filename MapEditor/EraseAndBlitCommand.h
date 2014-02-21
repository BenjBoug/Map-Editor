#ifndef ERASEANDBLITCOMMAND_H
#define ERASEANDBLITCOMMAND_H

#include "BlitCommand.h"
#include "EraseCommand.h"

class EraseAndBlitCommand : public ICommand
{
public:
    EraseAndBlitCommand(MapView * mapView, int i,int j, int bloc, int layer, int opacity=1);
    virtual void execute();
    virtual void undo();
    virtual void redo();

private:
    BlitCommand * blitCmd;
    EraseCommand * eraseCmd;
};

#endif // ERASEANDBLITCOMMAND_H
