#ifndef BLOCMAPMODEL_H
#define BLOCMAPMODEL_H

#include"Object.h"
#include <QRect>
#include <QDataStream>
#include <QVariant>
#include <QDebug>
#include <QObject>

namespace Model
{
/**
 * @brief The ZIndex enum
 */
enum ZIndex {BGRD=-50,LOW=0,HIGH=50,COLLIDE=100,GRID=200,EVENT=300,CURSOR=500};
/**
 * @brief The BlocMap class, the model of data for a bloc in the map
 */
class BlocMap : public QObject, public Object
{
    Q_OBJECT
public:
    /**
    * @brief BlocMap construct a bloc with all layers set at 0
    */
    BlocMap();
    /**
     * @brief BlocMap copy constructor
     */
    BlocMap(const BlocMap&);
    /**
     * @brief BlocMap construct bloc
     * @param low
     * @param high
     * @param collide
     */
    BlocMap(int low,int high,int collide);
    ~BlocMap();
    virtual bool collision(Object*);
    /**
	 * @brief get the value of the specific layer
     * @param layer the layer
     * @return the value at the layer
     */
	int getAtLayer(int layer);
    /**
	 * @brief set the value at the specific layer
     * @param layer the layer
     * @param newBloc the new value
     */
    void setLayer(int layer, int newBloc);
    /**
	 * @brief get the value at the LOW layer
     * @return the value
     */
    int getLowLayer() const;
    /**
	 * @brief set the value at the layer LOW
     * @param c the new value
     */
    void setLowLayer(int newValue);
    /**
	 * @brief get the layer at the HIGH layer
     * @return the value at the HIGH layer
     */
    int getHighLayer() const;
    /**
	 * @brief set the value at the HIGH layer
     * @param newValue the new value
     */
    void setHighLayer(int newValue);
    /**
	 * @brief get the value at the layer COLLIDE
     * @return
     */
    int getCollisionLayer() const;
    /**
	 * @brief set the value at the COLLIDE layer
     * @param newValue
     */
    void setCollisionLayer(bool newValue);

    friend QDataStream & operator << (QDataStream & out, const BlocMap * Valeur);
    friend QDataStream & operator >> (QDataStream & in, BlocMap * Valeur);

signals:
    /**
	 * @brief this signal is emit when the bloc has been modified
     */
    void blocModified();
    /**
	 * @brief this signal is emit when the value at the specific layer has been modified
     * @param layer the layer which has been modified
     */
    void blocLayerModified(int layer);
protected:
    /**
	 * @brief the value of the LOW layer
     */
    int lowLayer;
    /**
	 * @brief the value at the HIGH layer
     */
    int highLayer;
    /**
	 * @brief the value at the COLLIDE layer
     */
    int collisionLayer;
};
QDataStream & operator << (QDataStream & out, const BlocMap * Valeur);
QDataStream & operator >> (QDataStream & in, BlocMap * Valeur);
}
Q_DECLARE_METATYPE(Model::BlocMap)
#endif // BLOCMAP_H
