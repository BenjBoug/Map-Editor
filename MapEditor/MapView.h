#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <Map.h>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QBitmap>
#include "IStrategy.h"

class MapView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MapView();
    explicit MapView(Model::Map *);

    void setMap(Model::Map * map);

    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

    void setPaintStrategy(IStrategy * stra);
    void setDisplayStrategy(IStrategy * stra);

    QPixmap getChipset();
    Model::Map* getMap();
    void displayMap();

signals:
    
public slots:



private:

    int zoom;

    Model::Map * map;

    QPixmap chipset;

    IStrategy * paintStrategy;

    IStrategy * displayStrategy;


    
};

#endif // MAPVIEW_H
