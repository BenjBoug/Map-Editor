#ifndef ICHARACTER_H
#define ICHARACTER_H

#include "Object.h"
#include "IMoveable.h"
#include "IManager.h"
#include "IDisplayable.h"
namespace Model
{
class ICharacter : public Object, public IManager, public IMoveable, public IDisplayable
{
    virtual int getHp() = 0;
    virtual int getHpMax() = 0;
    virtual int getSpeed() = 0;

};
}

#endif // ICHARACTER_H
