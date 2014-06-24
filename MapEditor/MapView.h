
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
#include "layer/LayerStrategy.h"
#include "painter/PaintStrategy.h"
#include "command/ICommand.h"
#include "QGraphicsTileItem.h"
#include <QStack>
#include "Blocmap.h"
#include <stdexcept>

class MapView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MapView();
    explicit MapView(Model::Map *);

	Model::Map* getMap();
	void setMap(Model::Map * map);

    void setPaintStrategy(PaintStrategy * stra);
    void setDisplayStrategy(LayerStrategy * stra);
    void setGridStrategy(IStrategy * stra);

	LayerStrategy* getCurrentLayerStrategy();
	int getCurrentLayer();
    PaintStrategy *getCurrentPaint();

    void removeLayer(ZIndex index);
	void removeLayer(int index);
    QList<QGraphicsItem *> getLayer(int zindex);
    QList<QGraphicsItem*> getLayer(QList<QGraphicsItem*> list,int layer);

    void blitTile(int i, int j, int bl, int layer, float opacity=1);
    void blitTile(int i,int j, Model::BlocMap * bloc,int layer, float opacity=1);

    void removeTile(int i,int j,int layer);

	void setCursorPos(int i, int j, int width=1, int height=1);
	void setEnableCursor(bool ena);

	bool isModified();
	void setModified(bool modified);

	QPixmap getPixmap(QRect rect=QRect());


protected:
	void initCursor();

	void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
	void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
	void contextMenuEvent ( QGraphicsSceneContextMenuEvent * contextMenuEvent );

signals:
	void contensChanged();
    
public slots:
	void mapModified();
    void displayMap();
    void displayBackground();
	void clearMap();

	void mapResized(QSize size);
	void chipsetChanged(QPixmap  pix);

private:
	bool modified;
	Model::Map * map;
	QPixmap chipset;
    PaintStrategy * paintStrategy;
    LayerStrategy * displayStrategy;
    IStrategy * gridStrategy;
    QGraphicsRectItem * cursorRect;
};

#endif // MAPVIEW_H
