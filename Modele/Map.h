#ifndef MAP_H
#define MAP_H

#include "Blocmap.h"
#include "IEvent.h"
#include "IMap.h"
#include <QString>
#include <QVector>
#include "ICamera.h"
#include <QRect>
#include <QDataStream>
#include <QVariant>
#include <QFile>
#include <QDebug>
#include "Ennemi.h"

namespace Model
{
/**
 * @brief The Map class, the model of data for a map
 */
class Map : public IMap
{
    public:
        Map();
        Map(QString name);
        ~Map();

        void load();

        void setNameMap(QString &);
        void setNameChipset(QString &);
        QString getNameMap();


        QString getChipset() const;

        const BlocMap * getBloc(QPoint&) const;
        const BlocMap * getBloc(int,int) const;

        int convert2Dto1D(int i,int j) const;

        QSize getDim() const;
        void setDim(QSize &d);
        void setDim(int,int);

        void manage(const IGame *game);
        virtual void display(IGui* gui,ICamera*cam);

        friend QDataStream & operator << (QDataStream & out, const Map * Valeur);
        friend QDataStream & operator >> (QDataStream & in, Map * Valeur);

    QString _name;
    QVector<BlocMap*> _map;
    QVector<IEvent*> events;
    QSize dim;
    QString _chipset;
};

QDataStream & operator << (QDataStream & out, const Map * Valeur);
QDataStream & operator >> (QDataStream & in, Map * Valeur);

}
Q_DECLARE_METATYPE(Model::Map)
#endif // CARTE_H
