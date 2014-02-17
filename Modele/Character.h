#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.h"
#include "IGame.h"
#include <QVariant>
namespace Model
{
class Character : public ICharacter
{
public:
    Character();
    virtual ~Character();

    virtual void goLeft();
    virtual void goRight();
    virtual void goUp();
    virtual void goDown();

    virtual void manage(const IGame *game);

    int getSpeed()
    {
        return speed;
    }

    virtual void display(IGui*,ICamera*);


    virtual int getHp()
    {
        return hp;
    }

    virtual int getHpMax()
    {
        return hpMax;
    }


private:
    int speed;
    int hpMax;
    int hp;
    Direction direction;
};
}
Q_DECLARE_METATYPE(Model::Character)
#endif // CHARACTER_H
