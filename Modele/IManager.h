#ifndef MANAGER_H
#define MANAGER_H
namespace Model
{
class IGame;
class IManager
{
public:

    virtual void manage(const IGame *) = 0;

};
}

#endif // MANAGER_H
