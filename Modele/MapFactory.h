#ifndef MAPFACTORY_H
#define MAPFACTORY_H

#include "Map.h"
#include <QHash>
#include <QDebug>
namespace Model
{
class MapFactory
{
public:
    MapFactory();

    Map* build(QString & name);

private:
    QHash<QString,Map*> mapHash;
};

}
#endif // MAPFACTORY_H
