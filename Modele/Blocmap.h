#ifndef BLOCMAPMODEL_H
#define BLOCMAPMODEL_H

#include"Object.h"
#include <QRect>
#include <QDataStream>
#include <QVariant>
#include <QDebug>
/**
 * @brief The BlocMap class, the model of data for a bloc in the map
 */

namespace Model
{
    class BlocMap : public Object
    {
        public:
            BlocMap();
            BlocMap(int,int,int);
             ~BlocMap();
            virtual bool collision(Object*);
            int getCouche1() const;
            int getCouche2() const;
            int getCollision() const;
            void setCollision(bool s) {c_collision=s;}

            void debug() const
            {
                qDebug() << couche1 << couche2 << c_collision;
            }

            friend QDataStream & operator << (QDataStream & out, const BlocMap * Valeur);
            friend QDataStream & operator >> (QDataStream & in, BlocMap * Valeur);
        protected:
        int couche1;
        int couche2;
        int c_collision;
    };
    QDataStream & operator << (QDataStream & out, const BlocMap * Valeur);
    QDataStream & operator >> (QDataStream & in, BlocMap * Valeur);
}
Q_DECLARE_METATYPE(Model::BlocMap)
#endif // BLOCMAP_H
