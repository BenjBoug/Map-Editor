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

    /**
     * @brief load load the map from a file
     * @param filename the file of the map
     * @return false if the loading has failed
     */
    virtual bool load(QString filename);

    /**
     * @brief setName set the name of the map
     * @param name the new name
     */
    void setName(QString & name);
    /**
     * @brief getName get the name of the map
     * @return a QString with the name of the map
     */
    QString getName();


    /**
     * @brief setChipset set the filename of the chipset
     * @param chipset the filename
     */
	void loadChipset(QString &chipsetfile);
    /**
     * @brief getChipset get the filename of the chipset
     * @return the filename
     */
	QPixmap getChipset() const;

	void setChipset(QPixmap chipset);

    /**
     * @brief getBloc get the bloc at the specific coordonnates
     * @param coord the coordonates in number of blocs
     * @return a pointer to the bloc
     */
    BlocMap * getBloc(QPoint& coord) const;
    BlocMap * getBloc(int i,int j) const;


    /**
     * @brief getSize get the size of the map in number of blocs
     * @return the size
     */
    QSize getSize() const;
    void setSize(QSize &d);
    void setSize(int w, int);

    /**
     * @brief manage
     * @param game
     */
    void manage(const IGame *game);
    /**
     * @brief display Display the map
     * @param gui the Gui to display it
     * @param cam
     */
    virtual void display(IGui* gui,ICamera*cam);

    friend QDataStream & operator << (QDataStream & out, const Map * Valeur);
    friend QDataStream & operator >> (QDataStream & in, Map * Valeur);

signals:
    /**
	 * @brief mapChanged emit when one of the bloc is modified
     */
    void mapChanged();
    /**
     * @brief nameChanged emit when the name change
     */
    void nameChanged();
    void chipsetChanged();
    void sizeChanged();
protected:
    int convert2Dto1D(int i,int j) const;

    /**
     * @brief name the name of the map
     */
    QString name;
    /**
     * @brief map a vector of the blocs in the map
     */
    QVector<BlocMap*> map;
    /**
     * @brief events a vector of all the events in the map
     */
    QVector<IEvent*> events;
    /**
     * @brief size the size of the map in number of blocs
     */
    QSize size;
    /**
     * @brief chipset the filename of the chipset
     */
	QPixmap chipset;
};

QDataStream & operator << (QDataStream & out, const Map * Valeur);
QDataStream & operator >> (QDataStream & in, Map * Valeur);

}
Q_DECLARE_METATYPE(Model::Map)
#endif // CARTE_H
