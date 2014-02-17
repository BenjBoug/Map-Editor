#ifndef ENNEMIMODEL_H
#define ENNEMIMODEL_H

#include "IEvent.h"
#include "Character.h"
#include <QDebug>
namespace Model
{
class Ennemi : public IEvent, public IDisplayable
{
public:
    Ennemi();

    virtual void onKeySpace(IGame*);
    virtual void onKeyX(IGame*);
    virtual void onEvent(IGame* h);
    virtual void manage(const IGame *game);
    virtual void display(IGui* gui,ICamera* cam);

private:
    Character * character;
};
}
Q_DECLARE_METATYPE(Model::Ennemi)

#endif // ENNEMI_H
