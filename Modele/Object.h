#ifndef OBJECTMODEL_H
#define OBJECTMODEL_H

#include"Constantes.h"
#include <QRect>
namespace Model
{
class Object
{
    public:
        Object();
        virtual ~Object();

        virtual bool collision(Object*);
        virtual bool collision(QRect obj);

        virtual QRect getCoordBox() const
        {
            return coord;
        }

        virtual QRect getCollisionBox() const
        {
            return collisionBox;
        }

    protected:

    QRect hitBox, collisionBox;
    QRect coord;
};

}
#endif // OBJECT_H
