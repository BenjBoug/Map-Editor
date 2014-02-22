
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
    LayerStrategy* getCurrentLayer();
    PaintStrategy *getCurrentPaint();

    void removeLayer(ZIndex index);

    QList<QGraphicsItem *> getLayer(int zindex);
    QList<QGraphicsItem*> getLayer(QList<QGraphicsItem*> list,int layer);

    void executeCmd(ICommand* cmd);

    void blitTile(int i, int j, int bloc, int layer, float opacity=1);
    void removeTile(int i,int j,int layer);


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
