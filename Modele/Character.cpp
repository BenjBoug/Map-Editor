#include "Character.h"

using namespace Model;
Character::Character()
{
    speed = 5;
    hp = 5;
    hpMax = 5;
}

Character::~Character()
{
}

void Character::goLeft()
{
    coord.setX(coord.x()-speed);
}

void Character::goRight()
{
    coord.setX(coord.x()+speed);
}

void Character::goUp()
{
    coord.setY(coord.y()-speed);
}

void Character::goDown()
{
    coord.setY(coord.y()+speed);
}


void Character::manage(const IGame * game)
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

void Character::display(IGui *, ICamera *)
{
}
