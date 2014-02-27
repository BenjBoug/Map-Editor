#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include "ICamera.h"
#include "IGui.h"
namespace Model
{
class IDisplayable
{

public:
    /**
     * @brief display Display the object at the specific IGui and with the specific ICamera
     */
    virtual void display(IGui*,ICamera*) = 0;


};
}

#endif // DISPLAYABLE_H
