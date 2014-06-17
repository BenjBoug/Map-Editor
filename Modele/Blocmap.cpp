#include "Blocmap.h"


using namespace Model;

BlocMap::BlocMap()
{
    lowLayer=0;
    highLayer=0;
    collisionLayer=0;
}

BlocMap::BlocMap(const BlocMap & b)
{
    lowLayer=b.getLowLayer();
    highLayer=b.getHighLayer();
    collisionLayer=b.getCollisionLayer();
}
BlocMap::BlocMap(int _1, int _2, int _c)
{
    lowLayer=_1;
    highLayer=_2;
    collisionLayer=_c;
}

BlocMap::~BlocMap()
{
    //dtor
}

int BlocMap::getLowLayer() const
{
    return lowLayer;
}

void BlocMap::setLowLayer(int c)
{
    lowLayer=c;
    emit blocLayerModified(LOW);
    emit blocModified();
}
int BlocMap::getHighLayer() const
{
    return highLayer;
}

void BlocMap::setHighLayer(int c)
{
    highLayer=c;
    emit blocLayerModified(HIGH);
    emit blocModified();
}

int BlocMap::getCollisionLayer() const
{
    return collisionLayer;
}

void BlocMap::setCollisionLayer(bool c)
{
    collisionLayer=c;
    emit blocLayerModified(COLLIDE);
    emit blocModified();
}

QDataStream & Model::operator<<(QDataStream &out, const BlocMap * v)
{
    out << v->lowLayer << v->highLayer << v->collisionLayer;
    return out;
}

QDataStream & Model::operator>>(QDataStream &in, BlocMap * v)
{
    in >> v->lowLayer;
    in >> v->highLayer;
    in >> v->collisionLayer;
    return in;
}

bool BlocMap::collision(Object* )
{
    return (collisionLayer==1);
}

int BlocMap::getAtLayer(int layer)
{
    switch(layer)
    {
        case LOW:
            return lowLayer;
            break;
        case HIGH:
            return highLayer;
            break;
        case COLLIDE:
            return collisionLayer;
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
            lowLayer = bl;
            break;
        case HIGH:
            highLayer = bl;
            break;
        case COLLIDE:
            collisionLayer = bl;
            break;
    }
    emit blocModified();
    emit blocLayerModified(layer);
}

