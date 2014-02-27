#ifndef ICAMERA_H
#define ICAMERA_H

#include "Object.h"
#include "IManager.h"
namespace Model
{
class ICamera : public Object, public IManager
{
    /**
     * @brief isInTheField this method return true if the specific object is in the field of the camera
     * @param o the object to test
     * @return
     */
    virtual bool isInTheField(Object* o) =0;
};
}

#endif // ICAMERA_H
