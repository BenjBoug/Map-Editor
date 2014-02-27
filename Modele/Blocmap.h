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
     * @brief getLayer get the value of the specific layer
     * @param layer the layer
     * @return the value at the layer
     */
    int getLayer(int layer);
    /**
     * @brief setLayer set the value at the specific layer
     * @param layer the layer
     * @param newBloc the new value
     */
    void setLayer(int layer, int newBloc);
    /**
     * @brief getLowLayer get the value at the LOW layer
     * @return the value
     */
    int getLowLayer() const;
    /**
     * @brief setLowLayer set the value at the layer LOW
     * @param c the new value
     */
    void setLowLayer(int newValue);
    /**
     * @brief getHighLayer get the layer at the HIGH layer
     * @return the value at the HIGH layer
     */
    int getHighLayer() const;
    /**
     * @brief setHighLayer set the value at the HIGH layer
     * @param newValue the new value
     */
    void setHighLayer(int newValue);
    /**
     * @brief getCollisionLayer get the value at the layer COLLIDE
     * @return
     */
    int getCollisionLayer() const;
    /**
     * @brief setCollisionLayer set the value at the COLLIDE layer
     * @param newValue
     */
    void setCollisionLayer(bool newValue);

    friend QDataStream & operator << (QDataStream & out, const BlocMap * Valeur);
    friend QDataStream & operator >> (QDataStream & in, BlocMap * Valeur);

signals:
    /**
     * @brief blocModified this signal is emit when the bloc has been modified
     */
    void blocModified();
    /**
     * @brief blocLayerModified this signal is emit when the value at the specific layer has been modified
     * @param layer the layer which has been modified
     */
    void blocLayerModified(int layer);
protected:
    /**
     * @brief lowLayer the value of the LOW layer
     */
    int lowLayer;
    /**
     * @brief highLayer the value at the HIGH layer
     */
    int highLayer;
    /**
     * @brief collisionLayer the value at the COLLIDE layer
     */
    int collisionLayer;
};
QDataStream & operator << (QDataStream & out, const BlocMap * Valeur);
QDataStream & operator >> (QDataStream & in, BlocMap * Valeur);
}
Q_DECLARE_METATYPE(Model::BlocMap)
#endif // BLOCMAP_H
