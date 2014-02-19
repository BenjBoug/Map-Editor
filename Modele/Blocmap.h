#ifndef BLOCMAPMODEL_H
#define BLOCMAPMODEL_H

#include"Object.h"
#include <QRect>
#include <QDataStream>
#include <QVariant>
#include <QDebug>
#include <QObject>
/**
 * @brief The BlocMap class, the model of data for a bloc in the map
 */

namespace Model
{
    class BlocMap : public QObject, public Object
    {
        Q_OBJECT
        public:
            BlocMap();
            BlocMap(const BlocMap&);
            BlocMap(int,int,int);
             ~BlocMap();
            virtual bool collision(Object*);
            int getCouche1() const;
            void setCouche1(int c);
            int getCouche2() const;
            void setCouche2(int c);
            int getCollision() const;
            void setCollision(bool c);

            friend QDataStream & operator << (QDataStream & out, const BlocMap * Valeur);
            friend QDataStream & operator >> (QDataStream & in, BlocMap * Valeur);

        signals:
            void blocModified();
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
