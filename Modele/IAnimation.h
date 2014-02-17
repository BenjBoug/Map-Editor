#ifndef IANIMATION_H
#define IANIMATION_H

#include "IDisplayable.h"
#include "IManager.h"

namespace Model
{

    class IAnimation  : public IDisplayable, public IManager
    {
        virtual void prepare() = 0;
        virtual void play() = 0;
        virtual void stop() = 0;

    };

}

#endif // IANIMATION_H
