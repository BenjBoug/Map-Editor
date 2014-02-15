#ifndef IGAME_H
#define IGAME_H

#include "ICharacter.h"
#include "IMap.h"
#include "IInput.h"

namespace Model
{
class IGame{
public:
    virtual ICharacter * getHeros() const = 0;
    virtual IMap * getActualMap() const = 0;
    virtual IInput * getInput() const = 0;
};
}

#endif // GAME_H
