#include "MapView.h"

MapView::MapView():
    QGraphicsScene()
{
    gridStrategy = NULL;
	displayStrategy = NULL;
	paintStrategy = NULL;
	initCursor();
	modified = false;
}

MapView::MapView(Model::Map * m) :
    QGraphicsScene()
{
    gridStrategy = NULL;
    displayStrategy = NULL;
	paintStrategy = NULL;
	setMap(m);
	initCursor();
	modified = false;
}

/**
 * @brief Getter of the map
 * @return the Map object
 */
Model::Map *MapView::getMap()
{
	return map;
}

/**
 * @brief Setter for the map
 * @param map the map to display
 */
void MapView::setMap(Model::Map *map)
{
    this->map = map;

    this->setSceneRect(0,0,map->getSize().width()*BLOCSIZE,map->getSize().height()*BLOCSIZE);
	this->chipset = map->getChipset();
	QBitmap mask = this->chipset.createMaskFromColor(QColor(255, 103, 139));
	this->chipset.setMask(mask);

	connect(this->map,SIGNAL(chipsetChanged(QPixmap)),this,SLOT(chipsetChanged(QPixmap)));
	connect(this->map,SIGNAL(sizeChanged(QSize)),this,SLOT(mapResized(QSize)));
	connect(this->map,SIGNAL(mapChanged()),this,SLOT(mapModified()));
	connect(this->map,SIGNAL(mapChanged()),this,SIGNAL(contensChanged()));


	modified = false;

}

void MapView::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (this->sceneRect().contains(mouseEvent->scenePos()))
        displayStrategy->mousePressEvent(mouseEvent);
}

void MapView::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (this->sceneRect().contains(mouseEvent->scenePos()))
        displayStrategy->mouseMoveEvent(mouseEvent);
}

void MapView::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (this->sceneRect().contains(mouseEvent->scenePos()))
        displayStrategy->mouseReleaseEvent(mouseEvent);
}

void MapView::contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent)
{
	if (this->sceneRect().contains(contextMenuEvent->scenePos()))
		displayStrategy->contextMenuEvent(contextMenuEvent);
}
/**
 * @brief Setter of the PaintStrategy
 * @param stra
 */
void MapView::setPaintStrategy(PaintStrategy *stra)
{
	if (paintStrategy!=NULL)
		paintStrategy->restore();
    paintStrategy=stra;
	paintStrategy->init();
}
/**
 * @brief Setter of the LayerStrategy
 * @param stra
 */
void MapView::setDisplayStrategy(LayerStrategy *stra)
{
    displayStrategy = stra;
}
/**
 * @brief Setter of the GridStrategy, if NULL is given, nothing is displyed.
 * @param stra
 */
void MapView::setGridStrategy(IStrategy *stra)
{
    gridStrategy = stra;
    if (stra==NULL)
    {
        removeLayer(GRID);
    }
}

LayerStrategy *MapView::getCurrentLayerStrategy()
{
	return displayStrategy;
}
/**
 * @brief Get the number of the current layer
 * @return
 */
int MapView::getCurrentLayer()
{
	return displayStrategy->getLayer();
}

PaintStrategy *MapView::getCurrentPaint()
{
    return paintStrategy;
}
/**
 * @brief Remove all the tile at the specified layer.
 * @param index
 */
void MapView::removeLayer(ZIndex index)
{
    QList<QGraphicsItem *>::iterator it;
    QList<QGraphicsItem *> layer = getLayer(index);

    for(it=layer.begin();it!=layer.end();it++)
    {
        this->removeItem(*it);
	}
}

void MapView::removeLayer(int index)
{
	this->removeLayer(ZIndex(index));
}
/**
 * @brief Get all the tile at the specified layer
 * @param list
 * @param layer
 * @return a list with all the tile
 */
QList<QGraphicsItem *> MapView::getLayer(int zindex)
{
	QList<QGraphicsItem *>itemsRes =  this->items();
	QList<QGraphicsItem *>::iterator it = itemsRes.begin();

	for(;it!=itemsRes.end();)
	{
		if ((*it)->zValue() != zindex)
			it = itemsRes.erase(it);
		else
			it++;
	}

	return itemsRes;
}

QList<QGraphicsItem *> MapView::getLayer(QList<QGraphicsItem *> list, int layer)
{
    QList<QGraphicsItem *> res;
    QList<QGraphicsItem *>::iterator it;

    for(it=list.begin();it!=list.end();it++)
    {
        if ((*it)->zValue()==layer)
        {
            res.push_back(*it);
        }
    }

    return res;
}
/**
 * @brief MapView::blitTile
 * @param i
 * @param j
 * @param bl
 * @param layer
 * @param opacity
 */
void MapView::blitTile(int i, int j, int bl, int layer, float opacity)
{
    QPixmap tile = chipset.copy((bl%(chipset.width()/BLOCSIZE))*BLOCSIZE,(bl/(chipset.width()/BLOCSIZE))*BLOCSIZE,BLOCSIZE,BLOCSIZE);
    QGraphicsItem * item = this->addPixmap(tile);
    item->setZValue(layer);
    item->setOpacity(opacity);
    item->setPos(i*BLOCSIZE,j*BLOCSIZE);
}

void MapView::blitTile(int i, int j, BlocMap *bloc, int layer, float opacity)
{
    QGraphicsTileItem * tileItem = new QGraphicsTileItem(bloc,chipset,layer);
    tileItem->setPos(i*BLOCSIZE,j*BLOCSIZE);
    tileItem->setOpacity(opacity);
    this->addItem(tileItem);
}

void MapView::removeTile(int i, int j, int layer)
{
    QList<QGraphicsItem *> item = this->items(QRect((i*BLOCSIZE),(j*BLOCSIZE),BLOCSIZE,BLOCSIZE));
    item = this->getLayer(item,layer);
    QList<QGraphicsItem *>::iterator it;
    for(it=item.begin();it!=item.end();it++)
    {
        this->removeItem(*it);
	}
}

void MapView::setCursorPos(int i, int j, int width, int height)
{
	cursorRect->setRect(i*BLOCSIZE,j*BLOCSIZE,width*BLOCSIZE,height*BLOCSIZE);
}

bool MapView::isModified()
{
	return modified;
}

void MapView::setModified(bool modified)
{
	this->modified=modified;
}

QPixmap MapView::getPixmap(QRect rect)
{

	QSize size = this->getMap()->getSize()*BLOCSIZE;
	if (rect != QRect())
	{
		size = rect.size();
	}
	QPixmap collaspe(size);
	QPainter painter;

	painter.begin(&collaspe);
	this->render(&painter,QRect(),rect);
	painter.end();

	return collaspe;
}

void MapView::setEnableCursor(bool ena)
{
	if (ena)
	{
		removeLayer(CURSOR);
		initCursor();
	}
	else
	{
		removeLayer(CURSOR);
	}
}

void MapView::initCursor()
{
	QPen pen(Qt::lightGray, 3, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);
	cursorRect = this->addRect(0,0,0,0,pen,QBrush());
	cursorRect->setZValue(CURSOR);
}

void MapView::displayMap()
{
    clearMap();
    if (displayStrategy != NULL)
        displayStrategy->display();
    if (gridStrategy != NULL)
        gridStrategy->execute();
    this->setSceneRect(0,0,map->getSize().width()*BLOCSIZE,map->getSize().height()*BLOCSIZE);
}

void MapView::displayBackground()
{
    this->removeLayer(BGRD);
    for(int i=0;i<map->getSize().width();i++)
    {
        for(int j=0;j<map->getSize().height();j++)
        {
            blitTile(i,j,0,BGRD);
        }
    }
}

void MapView::clearMap()
{
    removeLayer(LOW);
    removeLayer(HIGH);
	removeLayer(COLLIDE);
}

void MapView::mapResized(QSize size)
{
	displayBackground();
	displayMap();
}

void MapView::chipsetChanged(QPixmap pix)
{
	this->chipset = pix;
	QBitmap mask = this->chipset.createMaskFromColor(QColor(255, 103, 139));
	this->chipset.setMask(mask);
	this->displayMap();
}

void MapView::mapModified()
{
	setModified(true);
}
