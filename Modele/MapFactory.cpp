#include "MapFactory.h"

using namespace Model;
MapFactory::MapFactory()
{
}

Map *MapFactory::build(QString &name)
{
    if (!mapHash.contains(name))
    {
        Map * map = new Map(name);
        QFile file(name);
        qDebug() << "DEBUG" << name << file.fileName() << file.exists();
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        in >> map;
        file.close();
        mapHash[name] = map;
    }

    return mapHash[name];
}
