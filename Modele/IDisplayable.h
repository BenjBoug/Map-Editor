#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include "ICamera.h"
#include "IGui.h"
namespace Model
{
class IDisplayable
{

public:
    virtual void display(IGui*,ICamera*) = 0;


};
}

#endif // DISPLAYABLE_H
