#ifndef SELECTIONSTRATEGY_H
#define SELECTIONSTRATEGY_H

#include "PaintStrategy.h"
#include "MapView.h"
#include "ChipsetView.h"
#include "command/BlitCommand.h"
#include "command/EraseCommand.h"
#include "ClipBoardSingleton.h"
#include <QMenu>

#define SELECT CURSOR+1
#define SELECT_TILE CURSOR-1

class SelectionStrategy : public PaintStrategy
{
public:
	SelectionStrategy(MapView * mapView, ChipsetView * chipsetView);

	QVector< QVector<int> >  getSelectedTiles() const;

protected:
	virtual void init();
	virtual void restore();

	virtual void leftButtonPressEvent(int i, int j);

	virtual void leftButtonMoveEvent(int i,int j);

	virtual void leftButtonReleaseEvent(int i,int j);


	virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent);

	void cut();
	void copy();
	void paste(QPoint contextPoint);

private:

	void clearZoneSelected();
	void blitTileSelected();
	void blitTileSelectLayer();

	void fillTileSelected();
	void selectionOn();
	void selectionOff();

	bool inMove;
	QRectF selection, initSelection;
	QPoint deb;
	QGraphicsRectItem * itemRectSelected;

	QVector< QVector<int> > tileSelected;

};

#endif // SELECTIONSTRATEGY_H
