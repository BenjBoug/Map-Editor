#ifndef ICAMERA_H
#define ICAMERA_H

#include "Object.h"
#include "IManager.h"
namespace Model
{
class ICamera : public Object, public IManager
{
    virtual bool isInTheField(Object*) =0;
};
}

#endif // ICAMERA_H
