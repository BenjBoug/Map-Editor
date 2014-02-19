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
#include "LayerStrategy.h"
#include "PaintStrategy.h"

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

    void setPaintStrategy(PaintStrategy * stra);
    void setDisplayStrategy(LayerStrategy * stra);
    void setGridStrategy(IStrategy * stra);

    QPixmap getChipset();
    Model::Map* getMap();
    LayerStrategy* getLayerStrategy();

signals:
    
public slots:

    void displayMap();


private:

    int zoom;

    Model::Map * map;

    QPixmap chipset;

    PaintStrategy * paintStrategy;

    LayerStrategy * displayStrategy;

    IStrategy * gridStrategy;


    
};

#endif // MAPVIEW_H
