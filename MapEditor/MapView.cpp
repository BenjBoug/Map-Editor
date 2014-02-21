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
    emit redoEmpty(!stackRedoCommand.isEmpty());
    emit undoEmpty(!stackUndoCommand.isEmpty());
}

void MapView::redo()
{
    ICommand * cmdRedid = stackRedoCommand.pop();
    cmdRedid->redo();
    stackUndoCommand.push(cmdUndid);
    emit redoEmpty(!stackRedoCommand.isEmpty());
    emit undoEmpty(!stackUndoCommand.isEmpty());
}


void MapView::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (this->sceneRect().contains(mouseEvent->scenePos()))
        paintStrategy->mousePressEvent(mouseEvent);
}

void MapView::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (this->sceneRect().contains(mouseEvent->scenePos()))
        paintStrategy->mouseMoveEvent(mouseEvent);
}

void MapView::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (this->sceneRect().contains(mouseEvent->scenePos()))
        paintStrategy->mouseReleaseEvent(mouseEvent);
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

LayerStrategy *MapView::getLayerStrategy()
{
    return displayStrategy;
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
