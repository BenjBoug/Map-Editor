#include "MapView.h"

MapView::MapView():
    QGraphicsScene()
{
    gridStrategy = NULL;
    displayStrategy = NULL;
}

MapView::MapView(Model::Map * m) :
    QGraphicsScene()
{
    gridStrategy = NULL;
    displayStrategy = NULL;
    setMap(m);
}

void MapView::setMap(Model::Map *map)
{
    this->map = map;
    loadChipset(map->getChipset());
    this->setSceneRect(0,0,map->getSize().width()*BLOCSIZE,map->getSize().height()*BLOCSIZE);
}

void MapView::loadChipset(QString f)
{
    chipset.load(f);
    QBitmap mask = chipset.createMaskFromColor(QColor(255, 103, 139));
    chipset.setMask(mask);
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

void MapView::setPaintStrategy(PaintStrategy *stra)
{
    paintStrategy=stra;
}

void MapView::setDisplayStrategy(LayerStrategy *stra)
{
    displayStrategy = stra;
}

void MapView::setGridStrategy(IStrategy *stra)
{
    gridStrategy = stra;
    if (stra==NULL)
    {
        removeLayer(GRID);
    }
}

QPixmap MapView::getChipset()
{
    return chipset;
}

Model::Map *MapView::getMap()
{
    return map;
}

LayerStrategy *MapView::getCurrentLayer()
{
    return displayStrategy;
}

PaintStrategy *MapView::getCurrentPaint()
{
    return paintStrategy;
}

void MapView::removeLayer(ZIndex index)
{
    QList<QGraphicsItem *>::iterator it;
    QList<QGraphicsItem *> layer = getLayer(index);

    for(it=layer.begin();it!=layer.end();it++)
    {
        this->removeItem(*it);
    }
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

    //map->getBloc(i,j)->setLayer(layer,0);
}

void MapView::setCursorRect(QRect rect)
{
    cursorRect->setRect(rect);
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
