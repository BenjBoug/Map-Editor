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


    virtual void display(IGui*,ICamera*);


    int getSpeed() const;
    void setSpeed(int value);

    int getHpMax() const;
    void setHpMax(int value);

    int getHp() const;
    void setHp(int value);

    Direction getDirection() const;
    void setDirection(const Direction &value);

private:
    int speed;
    int hpMax;
    int hp;
    Direction direction;
};
}
Q_DECLARE_METATYPE(Model::Character)
#endif // CHARACTER_H
