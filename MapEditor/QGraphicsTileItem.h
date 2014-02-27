#ifndef QGRAPHICSTILEITEM_H
#define QGRAPHICSTILEITEM_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "Constantes.h"
#include "Blocmap.h"
#include <QPainter>
#include "TileFactory.h"

using namespace Model;

class QGraphicsTileItem : public QGraphicsObject
{
    Q_OBJECT
public:
    QGraphicsTileItem(BlocMap*bloc,QPixmap chipset, int layer);


    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *  widget = 0 );
    QRectF boundingRect() const;

public slots:
    void blocHasChange(int layer);

private:
    QGraphicsPixmapItem * tileItem;
    BlocMap* bloc;
    QPixmap chipset;
    int layer;
    TileFactory factory;

};

#endif // QGRAPHICSTILEITEM_H
