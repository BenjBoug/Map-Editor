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
    /**
     * @brief getHp abstract method to get the HP
     * @return the value of the HP
     */
    virtual int getHp() const = 0;
    /**
     * @brief getHpMax abstract method to get the maximum of the HP.
     * this function has to return a value superior to getHp().
     * @return
     */
    virtual int getHpMax() const = 0;
    /**
     * @brief getSpeed abstract method to get the speed of the character
     * @return
     */
    virtual int getSpeed() const = 0;

};
}

#endif // ICHARACTER_H
