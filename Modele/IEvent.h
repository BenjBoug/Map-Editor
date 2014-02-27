#ifndef IEVENT_H
#define IEVENT_H

#include "Object.h"
#include "IManager.h"
#include <QVariant>
#include <QObject>


namespace Model
{
class IGame;

class IEvent : public IManager
{
public:
    IEvent();
    /**
     * @brief onKeySpace call when a user press the key SPACE in front of the event
     */
    virtual void onKeySpace(IGame *) = 0;
    /**
     * @brief onKeyX call when a user press the key "x" in front of the event
     */
    virtual void onKeyX(IGame *) = 0;
    /**
     * @brief onEvent call when the character is over the event
     */
    virtual void onEvent(IGame *) = 0;

    virtual void manage(const IGame *) = 0;

    friend QDataStream & operator << (QDataStream & out, const IEvent * Valeur);
    friend QDataStream & operator >> (QDataStream & in, IEvent * Valeur);

};
    QDataStream & operator << (QDataStream & out, const IEvent * Valeur);
    QDataStream & operator >> (QDataStream & in, IEvent * Valeur);
}

#endif // EVENEMENT_H
