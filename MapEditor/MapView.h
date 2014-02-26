
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
#include "QGraphicsTileItem.h"
#include <QStack>
#include "Blocmap.h"


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
    void contextMenuEvent ( QGraphicsSceneContextMenuEvent * contextMenuEvent );
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
    void blitTile(int i, int j, int bl, int layer, float opacity=1);
    void blitTile(int i,int j, Model::BlocMap * bloc,int layer, float opacity=1);
    void removeTile(int i,int j,int layer);

    void setCursorRect(QRect rect);

    
public slots:
    void displayMap();
    void displayBackground();
    void clearMap();
    void loadChipset(QString f);

private:
    Model::Map * map;
    QPixmap chipset;
    PaintStrategy * paintStrategy;
    LayerStrategy * displayStrategy;
    IStrategy * gridStrategy;
    QGraphicsRectItem * cursorRect;
};

#endif // MAPVIEW_H
