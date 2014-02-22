#ifndef IMOUSEMOVE_H
#define IMOUSEMOVE_H

#include <QGraphicsSceneMouseEvent>
#include "ICommand.h"

class IMouseMove
{
public:
    IMouseMove();

    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void leftButtonPressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void rightButtonPressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void leftButtonMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void rightButtonMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void leftButtonReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void rightButtonReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent);

private:
    bool inSelectLeft,inSelectRight;
};

#endif // IMOUSEMOVE_H
