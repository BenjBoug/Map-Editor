#include "SelectionStrategy.h"

SelectionStrategy::SelectionStrategy(MapView * mapView, ChipsetView * chipsetView) : PaintStrategy(mapView,chipsetView)
{
	inMove=false;

}

QVector<QVector<int> > SelectionStrategy::getSelectedTiles() const
{
	return tileSelected;
}

void SelectionStrategy::init()
{
	selectionOn();
	selection.setX(0);
	selection.setY(0);
	selection.setWidth(0);
	selection.setHeight(0);
	itemRectSelected = mapView->addRect(selection,QPen(Qt::lightGray, 3, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));
	itemRectSelected->setZValue(SELECT);
	mapView->setEnableCursor(false);
}

void SelectionStrategy::restore()
{
	blitTileSelected();
	selectionOff();
	mapView->setEnableCursor(true);
	mapView->removeLayer(SELECT);
}

void SelectionStrategy::leftButtonPressEvent(int i, int j)
{
	if (selection.contains(i*BLOCSIZE,j*BLOCSIZE)) // move the selection
	{
		deb = selection.topLeft().toPoint() - QPoint(i*BLOCSIZE,j*BLOCSIZE);
		inMove=true;
		selectionOff();
		if (selection==initSelection)
			clearZoneSelected();
		blitTileSelectLayer();
	}
	else //strt a new selection
	{
		blitTileSelected();
		mapView->setSelectionArea(QPainterPath());
		selection.setLeft(i*BLOCSIZE);
		selection.setTop(j*BLOCSIZE);
		selection.setWidth(BLOCSIZE);
		selection.setHeight(BLOCSIZE);
		itemRectSelected->setRect(selection);
	}
}

void SelectionStrategy::leftButtonMoveEvent(int i, int j)
{
	if (!inMove)
	{
		selection = mapView->selectionArea().boundingRect();
		selection.setLeft((int)selection.left()/BLOCSIZE*BLOCSIZE);
		selection.setTop((int)selection.top()/BLOCSIZE*BLOCSIZE);
		selection.setWidth(((int)selection.width()/BLOCSIZE*BLOCSIZE)+BLOCSIZE);
		selection.setHeight(((int)selection.height()/BLOCSIZE*BLOCSIZE)+BLOCSIZE);
		itemRectSelected->setRect(selection);
	}
	else
	{
		int height = selection.height();
		int width = selection.width();

		selection.setTop(j*BLOCSIZE + deb.y());
		selection.setLeft(i*BLOCSIZE + deb.x());
		selection.setWidth(width);
		selection.setHeight(height);
		itemRectSelected->setRect(selection);
		blitTileSelectLayer();
	}
}

void SelectionStrategy::leftButtonReleaseEvent(int i, int j)
{
	if (!inMove)
	{
		if (mapView->selectionArea() != QPainterPath())
		{
			selection = mapView->selectionArea().boundingRect();
			selection.setLeft((int)selection.left()/BLOCSIZE*BLOCSIZE);
			selection.setTop((int)selection.top()/BLOCSIZE*BLOCSIZE);
			selection.setWidth(((int)selection.width()/BLOCSIZE*BLOCSIZE)+BLOCSIZE);
			selection.setHeight(((int)selection.height()/BLOCSIZE*BLOCSIZE)+BLOCSIZE);
			QRectF rectScene = mapView->sceneRect();
			if (!rectScene.contains(selection)) {
				selection.setLeft(qMin(rectScene.right(), qMax(selection.left(), rectScene.left())));
				selection.setTop(qMin(rectScene.bottom(), qMax(selection.top(), rectScene.top())));
				selection.setRight(qMin(rectScene.right(), qMax(selection.right(), rectScene.left())));
				selection.setBottom(qMin(rectScene.bottom(), qMax(selection.bottom(), rectScene.top())));
			}
			itemRectSelected->setRect(selection);
			mapView->clearSelection();
			fillTileSelected();
		}
		else
		{
			selection.setLeft(i*BLOCSIZE);
			selection.setTop(j*BLOCSIZE);
			selection.setWidth(BLOCSIZE);
			selection.setHeight(BLOCSIZE);
			itemRectSelected->setRect(selection);
			mapView->clearSelection();
			fillTileSelected();
		}
		initSelection = selection;
	}
	else
	{
		blitTileSelectLayer();
		inMove = false;
		selectionOn();
	}
}

void SelectionStrategy::contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent)
{
	QAction * cutAction = new QAction(QIcon(":cut"),"Cut",mapView);
	QAction * copyAction = new QAction(QIcon(":copy"),"Copy",mapView);
	QAction * pasteAction = new QAction(QIcon(":paste"),"Paste",mapView);

	cutAction->setEnabled(mapView->selectionArea()!=QPainterPath());
	copyAction->setEnabled(mapView->selectionArea()!=QPainterPath());

	QMenu menu;
	menu.addAction(cutAction);
	menu.addAction(copyAction);
	menu.addAction(pasteAction);
	QAction * act = menu.exec(contextMenuEvent->screenPos());

	if (act==cutAction)
		this->cut();
	else if (act==copyAction)
		this->copy();
	else if (act==pasteAction)
		this->paste(contextMenuEvent->scenePos().toPoint());
}

void SelectionStrategy::cut()
{
	//clearZoneSelected();
	copy();
	mapView->removeLayer(SELECT_TILE);
	selection.setX(0);
	selection.setY(0);
	selection.setWidth(0);
	selection.setHeight(0);
	itemRectSelected->setRect(selection);
}

void SelectionStrategy::copy()
{
	ClipBoardSingleton::getInstance()->copy(mapView,selection.toRect());
}

void SelectionStrategy::paste(QPoint contextPoint)
{
	ClipBoardSingleton::getInstance()->paste(mapView,contextPoint.x()/BLOCSIZE,contextPoint.y()/BLOCSIZE);
	selection = ClipBoardSingleton::getInstance()->getRectSelected();
	int height = selection.height();
	int width = selection.width();
	selection.setTopLeft(QPoint(contextPoint.x()/BLOCSIZE*BLOCSIZE,contextPoint.y()/BLOCSIZE*BLOCSIZE));
	selection.setWidth(width);
	selection.setHeight(height);
	itemRectSelected->setRect(selection);
}

void SelectionStrategy::clearZoneSelected()
{
	CMD_BEGIN();
	for(int i=selection.left()/BLOCSIZE;i<selection.right()/BLOCSIZE;i++)
	{
		for(int j=selection.top()/BLOCSIZE;j<selection.bottom()/BLOCSIZE;j++)
		{
			EXECUTE_CMD(new EraseCommand(mapView->getMap(),i,j,mapView->getCurrentLayer()));
		}
	}
	CMD_END();
}

void SelectionStrategy::blitTileSelected()
{
	CMD_BEGIN();
	for(int i=selection.left()/BLOCSIZE;i<selection.right()/BLOCSIZE;i++)
	{
		for(int j=selection.top()/BLOCSIZE;j<selection.bottom()/BLOCSIZE;j++)
		{
			EXECUTE_CMD(new BlitCommand(mapView->getMap(),i,j,mapView->getCurrentLayer(),tileSelected[i-selection.left()/BLOCSIZE][j-selection.top()/BLOCSIZE]));
		}
	}
	CMD_END();
	mapView->removeLayer(SELECT_TILE);
}

void SelectionStrategy::blitTileSelectLayer()
{
	mapView->removeLayer(SELECT_TILE);
	for(int i=selection.left()/BLOCSIZE;i<selection.right()/BLOCSIZE;i++)
	{
		for(int j=selection.top()/BLOCSIZE;j<selection.bottom()/BLOCSIZE;j++)
		{
			mapView->blitTile(i,j,tileSelected[i-selection.left()/BLOCSIZE][j-selection.top()/BLOCSIZE],SELECT_TILE);
		}
	}
}

void SelectionStrategy::fillTileSelected()
{
	tileSelected.clear();
	for(int i=selection.left()/BLOCSIZE;i<selection.right()/BLOCSIZE;i++)
	{
		QVector<int> vec;
		for(int j=selection.top()/BLOCSIZE;j<selection.bottom()/BLOCSIZE;j++)
		{
			vec.append(mapView->getMap()->getBloc(i,j)->getAtLayer(mapView->getCurrentLayer()));
		}
		tileSelected.append(vec);
	}
}

void SelectionStrategy::selectionOn()
{
	foreach (QGraphicsView * view, mapView->views())
	{
		view->setDragMode(QGraphicsView::RubberBandDrag);
	}
}

void SelectionStrategy::selectionOff()
{
	foreach (QGraphicsView * view, mapView->views())
	{
		view->setDragMode(QGraphicsView::NoDrag);
	}
}
