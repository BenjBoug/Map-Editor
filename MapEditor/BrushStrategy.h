#ifndef BRUSHSTRATEGY_H
#define BRUSHSTRATEGY_H

#include "PaintStrategy.h"
#include <QVector>
#include <QDebug>
#include "MapView.h"
#include "ChipsetView.h"
#include "EraseCommand.h"
#include "BlitCommand.h"
#include "UndoSingleton.h"

class BrushStrategy : public PaintStrategy
{
public:
    BrushStrategy(MapView * mapView, ChipsetView * chipsetView);

    void leftButtonPressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void rightButtonPressEvent(QGraphicsSceneMouseEvent * mouseEvent);

    void leftButtonMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void rightButtonMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);


private:

    void blit(QPointF pos);
    QRect blited;
    bool inSelect, inSelectRight;
    int idCmd;
};

#endif // BRUSHSTRATEGY_H
