#ifndef PAINTPOTSTRATGEY_H
#define PAINTPOTSTRATGEY_H

#include "PaintStrategy.h"
#include <QDebug>
#include "MapView.h"
#include "ChipsetView.h"
#include "EraseAndBlitCommand.h"

class PaintPotStrategy : public PaintStrategy
{
public:
    PaintPotStrategy(MapView * mapView, ChipsetView * chipsetView);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

    void paintPot(int i,int j, int blocRef);

private:
};

#endif // PAINTPOTSTRATGEY_H
