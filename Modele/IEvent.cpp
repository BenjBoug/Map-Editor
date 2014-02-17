#include "IEvent.h"

using namespace Model;

IEvent::IEvent()
{
}

QDataStream & Model::operator << (QDataStream & out, const IEvent * Valeur)
{
    return out;
}

QDataStream & Model::operator >> (QDataStream & in, IEvent *Valeur)
{
    return in;
}
