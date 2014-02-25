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

}

void Character::display(IGui *, ICamera *)
{
}
int Character::getSpeed() const
{
    return speed;
}

void Character::setSpeed(int value)
{
    speed = value;
}
int Character::getHpMax() const
{
    return hpMax;
}

void Character::setHpMax(int value)
{
    hpMax = value;
}
int Character::getHp() const
{
    return hp;
}

void Character::setHp(int value)
{
    hp = value;
}
Direction Character::getDirection() const
{
    return direction;
}

void Character::setDirection(const Direction &value)
{
    direction = value;
}




