#ifndef IEVENT_H
#define IEVENT_H

#include "Object.h"
#include "IManager.h"


namespace Model
{
class IGame;

class IEvent : public IManager
{
public:

    virtual void onKeySpace(IGame *) = 0;
    virtual void onKeyX(IGame *) = 0;
    virtual void onEvent(IGame *) = 0;
    virtual void manage(const IGame *) = 0;

    IEvent();

};
}

#endif // EVENEMENT_H
