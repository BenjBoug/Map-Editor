#include "ChipsetView.h"

ChipsetView::ChipsetView():
    QGraphicsScene()
{
    init();
}

ChipsetView::ChipsetView(QString chip) :
    QGraphicsScene()
{
    loadChipset(chip);
    init();
}

void ChipsetView::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    selection.setLeft((int)mouseEvent->scenePos().x()/BLOCSIZE*BLOCSIZE);
    selection.setTop((int)mouseEvent->scenePos().y()/BLOCSIZE*BLOCSIZE);
    selection.setWidth(BLOCSIZE);
    selection.setHeight(BLOCSIZE);
    itemRectSelected->setRect(selection);
}

void ChipsetView::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    selection = selectionArea().boundingRect();
    selection.setLeft((int)selection.left()/BLOCSIZE*BLOCSIZE);
    selection.setTop((int)selection.top()/BLOCSIZE*BLOCSIZE);
    selection.setWidth(((int)selection.width()/BLOCSIZE*BLOCSIZE)+BLOCSIZE);
    selection.setHeight(((int)selection.height()/BLOCSIZE*BLOCSIZE)+BLOCSIZE);
    itemRectSelected->setRect(selection);
}

void ChipsetView::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    if (this->selectionArea() != QPainterPath())
    {
        selection = selectionArea().boundingRect();
        selection.setLeft((int)selection.left()/BLOCSIZE*BLOCSIZE);
        selection.setTop((int)selection.top()/BLOCSIZE*BLOCSIZE);
        selection.setWidth(((int)selection.width()/BLOCSIZE*BLOCSIZE)+BLOCSIZE);
        selection.setHeight(((int)selection.height()/BLOCSIZE*BLOCSIZE)+BLOCSIZE);
        QRectF rectScene = this->sceneRect();
        if (!rectScene.contains(selection)) {
            selection.setLeft(qMin(rectScene.right(), qMax(selection.left(), rectScene.left())));
            selection.setTop(qMin(rectScene.bottom(), qMax(selection.top(), rectScene.top())));
            selection.setRight(qMin(rectScene.right(), qMax(selection.right(), rectScene.left())));
            selection.setBottom(qMin(rectScene.bottom(), qMax(selection.bottom(), rectScene.top())));
        }
        this->clearSelection();
        this->setSelectionArea(QPainterPath(), QTransform());
        itemRectSelected->setRect(selection);
    }
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void ChipsetView::init()
{
    selectedTile.resize(1);
    selectedTile[0].resize(1);
    selectedTile[0][0] = 0;
    selection.setX(0);
    selection.setY(0);
    selection.setWidth(BLOCSIZE);
    selection.setHeight(BLOCSIZE);

}

void ChipsetView::loadChipset(QString chip)
{
    chipset.load(chip);
    QGraphicsPixmapItem * chipsetItem = this->addPixmap(chipset);
    chipsetItem->setZValue(0);
    setSceneRect(chipsetItem->sceneBoundingRect());
    itemRectSelected = this->addRect(selection);
    itemRectSelected->setZValue(100);
}

