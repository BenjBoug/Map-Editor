#include "MapView.h"

MapView::MapView():
    QGraphicsScene()
{
    zoom = 1;
    this->map = new Model::Map();
    gridStrategy = NULL;
    //this->setSceneRect(10,0,SCREEN_WIDTH,SCREEN_HEIGHT);
}

MapView::MapView(Model::Map * m) :
    QGraphicsScene()
{
    zoom = 1;
    gridStrategy = NULL;
    setMap(m);
}

void MapView::setMap(Model::Map *map)
{
    this->map = map;
    loadChipset(map->getChipset());
    displayMap();
}

void MapView::loadChipset(QString f)
{
    chipset.load(f);
    QBitmap mask = chipset.createMaskFromColor(QColor(255, 103, 139));
    chipset.setMask(mask);
}

void MapView::undo()
{
    ICommand * cmdUndid = stackUndoCommand.pop();
    cmdUndid->undo();
    stackRedoCommand.push(cmdUndid);
    int id=cmdUndid->getId();
    while (!stackUndoCommand.isEmpty() && stackUndoCommand.top()->getId()==id)
    {
        cmdUndid = stackUndoCommand.pop();
        cmdUndid->undo();
        stackRedoCommand.push(cmdUndid);
    }

    emit redoEmpty(!stackRedoCommand.isEmpty());
    emit undoEmpty(!stackUndoCommand.isEmpty());
}

void MapView::redo()
{
    ICommand * cmdRedid = stackRedoCommand.pop();
    cmdRedid->execute();
    stackUndoCommand.push(cmdRedid);
    int id=cmdRedid->getId();
    while (!stackRedoCommand.isEmpty() && stackRedoCommand.top()->getId()==id)
    {
        cmdRedid = stackRedoCommand.pop();
        cmdRedid->execute();
        stackUndoCommand.push(cmdRedid);
    }

    emit redoEmpty(!stackRedoCommand.isEmpty());
    emit undoEmpty(!stackUndoCommand.isEmpty());
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

void MapView::setPaintStrategy(PaintStrategy *stra)
{
    paintStrategy=stra;
}

void MapView::setDisplayStrategy(LayerStrategy *stra)
{
    displayStrategy = stra;
    stackRedoCommand.clear();
    stackUndoCommand.clear();
    emit redoEmpty(!stackRedoCommand.isEmpty());
    emit undoEmpty(!stackUndoCommand.isEmpty());
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

void MapView::executeCmd(ICommand *cmd)
{
    cmd->execute();
    stackUndoCommand.push(cmd);
    emit redoEmpty(!stackRedoCommand.isEmpty());
    emit undoEmpty(!stackUndoCommand.isEmpty());
}

void MapView::blitTile(int i, int j, int bloc, int layer, float opacity)
{
    map->getBloc(i,j)->setLayer(layer,bloc);
    int valueMax = (chipset.width()/BLOCSIZE)*(chipset.height()/BLOCSIZE);
    if (bloc!=0 && bloc < valueMax)
    {
        QPixmap tile = chipset.copy((bloc%(chipset.width()/BLOCSIZE))*BLOCSIZE,(bloc/(chipset.width()/BLOCSIZE))*BLOCSIZE,BLOCSIZE,BLOCSIZE);
        QGraphicsPixmapItem * tileItem = this->addPixmap(tile);
        tileItem->setPos(i*BLOCSIZE,j*BLOCSIZE);
        tileItem->setZValue(layer);
        tileItem->setOpacity(opacity);
    }
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

    map->getBloc(i,j)->setLayer(layer,0);
}

void MapView::displayMap()
{
    clearMap();
    displayStrategy->display();
    if (gridStrategy != NULL)
        gridStrategy->execute();
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
