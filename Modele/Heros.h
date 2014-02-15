#ifndef HEROS_H
#define HEROS_H

#include "Map.h"
#include "Character.h"
namespace Model
{
class Heros : public Character
{
public:
    Heros();

private:
    int rubis;
};
}

#endif // HEROS_H
