#ifndef LAYERSTRATEGY_H
#define LAYERSTRATEGY_H

#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include "command/ICommand.h"
#include "painter/PaintStrategy.h"
#include "IMouseMove.h"
class MapView;

class LayerStrategy : public IMouseMove
{
public:
    LayerStrategy(MapView * mapView);
    virtual void display() =0;
    virtual int getLayer() = 0;

	void addAllowedTool(PaintStrategy* tool);

	virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent);

protected:
	MapView * mapView;

private:

	QList<PaintStrategy*> allowedTools;
};

#endif // LAYERSTRATEGY_H
