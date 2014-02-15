#include "Blocmap.h"


using namespace Model;

BlocMap::BlocMap()
{
    couche1=-1;
    couche2=-1;
    c_collision=-1;
}
BlocMap::BlocMap(int _1, int _2, int _c)
{
    couche1=_1;
    couche2=_2;
    c_collision=_c;
}

BlocMap::~BlocMap()
{
    //dtor
}

int BlocMap::getCouche1() const
{
    return couche1;
}
int BlocMap::getCouche2() const
{
    return couche2;
}

int BlocMap::getCollision() const
{
    return c_collision;
}

QDataStream & Model::operator<<(QDataStream &out, const BlocMap * v)
{
    out << v->couche1 << v->couche2 << v->c_collision;
    return out;
}

QDataStream & Model::operator>>(QDataStream &in, BlocMap * v)
{
    in >> v->couche1;
    in >> v->couche2;
    in >> v->c_collision;
    return in;
}

bool BlocMap::collision(Object* )
{
    return (c_collision==1);
}

