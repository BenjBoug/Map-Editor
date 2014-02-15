#ifndef ENNEMIMODEL_H
#define ENNEMIMODEL_H

#include "IEvent.h"
#include "Character.h"
namespace Model
{
class Ennemi : public IEvent, public IDisplayable
{
public:
    Ennemi();

    virtual void onKeySpace(IGame*);
    virtual void onKeyX(IGame*);
    virtual void onEvent(IGame* h);
    virtual void manage(const IGame *);

private:
    Character * character;
};
}

#endif // ENNEMI_H
