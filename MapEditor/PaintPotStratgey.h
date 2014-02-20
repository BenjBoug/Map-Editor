#ifndef PAINTPOTSTRATGEY_H
#define PAINTPOTSTRATGEY_H

#include "PaintStrategy.h"
#include <QDebug>

class PaintPotStratgey : public PaintStrategy
{
public:
    PaintPotStratgey(MapView * mapView, ChipsetView * chipsetView);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
};

#endif // PAINTPOTSTRATGEY_H
