
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
#include "ICommand.h"
#include <QStack>

enum ZIndex {LOW=0,HIGH=50,COLLIDE=100,GRID=200,CURSOR=500};

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

    void removeLayer(ZIndex index);

    QList<QGraphicsItem *> getLayer(int zindex);
    QList<QGraphicsItem*> getLayer(QList<QGraphicsItem*> list,int layer);

    void executeCmd(ICommand* cmd);


signals:
    void undoEmpty(bool);
    void redoEmpty(bool);
    
public slots:

    void displayMap();
    void clearMap();

    void loadChipset(QString f);

    void undo();
    void redo();


private:

    QStack<ICommand*> stackUndoCommand;
    QStack<ICommand*> stackRedoCommand;

    int zoom;

    Model::Map * map;

    QPixmap chipset;

    PaintStrategy * paintStrategy;

    LayerStrategy * displayStrategy;

    IStrategy * gridStrategy;



    
};

#endif // MAPVIEW_H
