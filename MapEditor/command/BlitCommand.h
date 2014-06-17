#ifndef BLITCOMMAND_H
#define BLITCOMMAND_H

#include "ICommand.h"
#include "Map.h"

using namespace Model;

class BlitCommand : public ICommand
{
public:
	BlitCommand(Map * map, int i, int j,int layer, int bloc);
    virtual void execute();
    virtual void undo();


private:
	Map * map;
    int i,j,bloc;
    int layerMemento;
    int blocMemento;
};

#endif // BLITCOMMAND_H
