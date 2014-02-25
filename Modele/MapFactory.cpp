#include "MapFactory.h"

using namespace Model;
MapFactory::MapFactory()
{
}

Map *MapFactory::build(QString &file)
{
    if (!mapHash.contains(file))
    {
        Map * map = new Map(file);
        mapHash[file] = map;
    }

    return mapHash[file];
}
