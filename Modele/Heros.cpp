#include "Heros.h"

using namespace Model;
Heros::Heros()
{
    coord.setX(80*BLOCSIZE/2);
    coord.setY(60*BLOCSIZE/2);
}

void Heros::manage(const IGame *game)
{
    if (game->getInput()->onKeyUpPress())
        goUp();
    if (game->getInput()->onKeyDownPress())
        goDown();

    if (game->getInput()->onKeyLeftPress())
        goLeft();
    if (game->getInput()->onKeyRightPress())
        goRight();
}
int Heros::getRubis() const
{
    return rubis;
}

void Heros::setRubis(int value)
{
    rubis = value;
}

