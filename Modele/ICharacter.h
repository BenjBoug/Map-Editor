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
    virtual int getHp() const = 0;
    virtual int getHpMax() const = 0;
    virtual int getSpeed() const = 0;

};
}

#endif // ICHARACTER_H
