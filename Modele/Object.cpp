#include "Object.h"

using namespace Model;
Object::Object()
{
    //ctor
}

Object::~Object()
{
    //dtor
}

bool Object::collision(Object* obj)
{
    if (this==obj)
        return false;
    return this->collisionBox.contains((obj->collisionBox));
}

bool Object::collision(QRect obj)
{
    return obj.contains(this->collisionBox);
}


