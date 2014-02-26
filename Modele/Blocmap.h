#ifndef BLOCMAPMODEL_H
#define BLOCMAPMODEL_H

#include"Object.h"
#include <QRect>
#include <QDataStream>
#include <QVariant>
#include <QDebug>
#include <QObject>
enum ZIndex {BGRD=-50,LOW=0,HIGH=50,COLLIDE=100,GRID=200,EVENT=300,CURSOR=500};

namespace Model
{
/**
 * @brief The BlocMap class, the model of data for a bloc in the map
 */

    class BlocMap : public QObject, public Object
    {
        Q_OBJECT
        public:
            BlocMap();
            BlocMap(const BlocMap&);
            BlocMap(int,int,int);
             ~BlocMap();
            virtual bool collision(Object*);

            int getLayer(int layer);
            void setLayer(int layer, int bl);

            int getLowLayer() const;
            void setLowLayer(int c);
            int getHighLayer() const;
            void setHighLayer(int c);
            int getCollisionLayer() const;
            void setCollisionLayer(bool c);

            friend QDataStream & operator << (QDataStream & out, const BlocMap * Valeur);
            friend QDataStream & operator >> (QDataStream & in, BlocMap * Valeur);

        signals:
            void blocModified();
            void blocLayerModified(int layer);
        protected:
        int lowLayer;
        int highLayer;
        int collisionLayer;
    };
    QDataStream & operator << (QDataStream & out, const BlocMap * Valeur);
    QDataStream & operator >> (QDataStream & in, BlocMap * Valeur);
}
Q_DECLARE_METATYPE(Model::BlocMap)
#endif // BLOCMAP_H
