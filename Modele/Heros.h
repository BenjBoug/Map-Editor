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

    virtual void manage(const IGame *game);

    int getRubis() const;
    void setRubis(int value);

private:
    int rubis;
};
}

#endif // HEROS_H
