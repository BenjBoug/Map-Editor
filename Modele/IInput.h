#ifndef IINPUT_H
#define IINPUT_H

#include "IManager.h"

namespace Model
{
    class IInput : public IManager
    {
    public:
        virtual bool onKeyXPress() = 0;
        virtual bool onKeySpacePress() = 0;
        virtual bool onKeyPPress() = 0;
        virtual bool onKeyEscapePress() = 0;
        virtual bool onKeyUpPress() = 0;
        virtual bool onKeyDownPress() = 0;
        virtual bool onKeyLeftPress() = 0;
        virtual bool onKeyRightPress() = 0;
    };

}
#endif // IINPUT_H
