#ifndef IMOUSEMOVE_H
#define IMOUSEMOVE_H

#include <QGraphicsSceneMouseEvent>
#include "ICommand.h"
#include "Constantes.h"

class IMouseMove
{
public:
    IMouseMove();

    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void leftButtonPressEvent(int i, int j);
    virtual void rightButtonPressEvent(int i,int j);

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void leftButtonMoveEvent(int i,int j);
    virtual void rightButtonMoveEvent(int i,int j);

    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void leftButtonReleaseEvent(int i,int j);
    virtual void rightButtonReleaseEvent(int i,int j);

    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent);

private:
    bool inSelectLeft,inSelectRight;
};

#endif // IMOUSEMOVE_H
