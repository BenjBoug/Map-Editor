#ifndef MOVEABLE_H
#define MOVEABLE_H
namespace Model
{
class IMoveable
{
public:

    virtual void goLeft()=0;
    virtual void goRight()=0;
    virtual void goUp()=0;
    virtual void goDown()=0;

};
}

#endif // MOVEABLE_H
