#include "Blocmap.h"


using namespace Model;

BlocMap::BlocMap()
{
    couche1=0;
    couche2=0;
    c_collision=0;
}

BlocMap::BlocMap(const BlocMap & b)
{
    couche1=b.getCouche1();
    couche2=b.getCouche2();
    c_collision=b.getCollision();
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

void BlocMap::setCouche1(int c)
{
    couche1=c;
    emit blocModified();
}
int BlocMap::getCouche2() const
{
    return couche2;
}

void BlocMap::setCouche2(int c)
{
    couche2=c;
    emit blocModified();
}

int BlocMap::getCollision() const
{
    return c_collision;
}

void BlocMap::setCollision(bool c)
{
    c_collision=c;
    emit blocModified();
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

int BlocMap::getLayer(int layer)
{
    switch(layer)
    {
        case LOW:
            return couche1;
            break;
        case HIGH:
            return couche2;
            break;
        case COLLIDE:
            return c_collision;
            break;
        default:
            return -1;
    }
}

void BlocMap::setLayer(int layer, int bl)
{
    switch(layer)
    {
        case LOW:
            couche1 = bl;
            break;
        case HIGH:
            couche2 = bl;
            break;
        case COLLIDE:
            c_collision = bl;
            break;
    }
}

