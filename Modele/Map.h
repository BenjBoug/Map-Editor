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
#include <QPixmap>
#include "Ennemi.h"

namespace Model
{
/**
 * @brief The Map class, the model of data for a map
 */
class Map : public QObject, public IMap
{
    Q_OBJECT
public:
    Map();
    Map(const Map&);
    ~Map();

    Map &operator=(const Map&);


    virtual bool load(QString filename);

    void setName(QString & name);
    QString getName();


	void loadChipset(QString &chipsetfile);
	QPixmap getChipset() const;

	void setChipset(QPixmap chipset);

    BlocMap * getBloc(QPoint& coord) const;
    BlocMap * getBloc(int i,int j) const;

	QRect getRect() const;
    QSize getSize() const;
    void setSize(QSize &d);
    void setSize(int w, int);

    void manage(const IGame *game);
    virtual void display(IGui* gui,ICamera*cam);

    friend QDataStream & operator << (QDataStream & out, const Map * Valeur);
    friend QDataStream & operator >> (QDataStream & in, Map * Valeur);

signals:

    void mapChanged();

	void nameChanged(QString);
	void chipsetChanged(QPixmap);
	void sizeChanged(QSize);
protected:
    int convert2Dto1D(int i,int j) const;

    QString name;
    QVector<BlocMap*> map;
    QVector<IEvent*> events;
    QSize size;
	QPixmap chipset;
};

QDataStream & operator << (QDataStream & out, const Map * Valeur);
QDataStream & operator >> (QDataStream & in, Map * Valeur);

}
Q_DECLARE_METATYPE(Model::Map)
#endif // CARTE_H
