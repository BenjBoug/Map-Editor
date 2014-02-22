#include "IMouseMove.h"

IMouseMove::IMouseMove()
{
    inSelectLeft=false;
    inSelectRight=false;
}

void IMouseMove::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button()==Qt::LeftButton)
    {
        inSelectLeft=true;
        leftButtonPressEvent(mouseEvent);
    }

    if (mouseEvent->button()==Qt::RightButton)
    {
        inSelectRight=true;
        rightButtonPressEvent(mouseEvent);
    }
}
void IMouseMove::leftButtonPressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{

}

void IMouseMove::rightButtonPressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{

}

void IMouseMove::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (inSelectLeft)
        leftButtonMoveEvent(mouseEvent);
    if (inSelectRight)
        rightButtonMoveEvent(mouseEvent);
}
void IMouseMove::leftButtonMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{

}

void IMouseMove::rightButtonMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{

}

void IMouseMove::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button()==Qt::LeftButton)
    {
        inSelectLeft=false;
        leftButtonReleaseEvent(mouseEvent);
    }
    if (mouseEvent->button()==Qt::RightButton)
    {
        inSelectRight=false;
        rightButtonReleaseEvent(mouseEvent);
    }
    ICommand::end();
}
void IMouseMove::leftButtonReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent)
{

}

void IMouseMove::rightButtonReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent)
{

}

void IMouseMove::contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent)
{

}
