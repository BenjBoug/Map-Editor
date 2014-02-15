#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H
#include <QDataStream>
#include <QVariant>
namespace Model
{
class ISerializable {
    virtual QDataStream & operator << (QDataStream & out) =0;
    virtual QDataStream & operator >> (QDataStream & in) =0;

};

}
#endif // ISERIALIZABLE_H
