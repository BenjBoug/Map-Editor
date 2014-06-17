#include "IMouseMove.h"

IMouseMove::IMouseMove()
{
    inSelectLeft=false;
    inSelectRight=false;
}

void IMouseMove::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	UndoSingleton::getInstance()->beginGroup();
    if (mouseEvent->button()==Qt::LeftButton)
    {
        inSelectLeft=true;
        leftButtonPressEvent(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
    }

    if (mouseEvent->button()==Qt::RightButton)
    {
        inSelectRight=true;
        rightButtonPressEvent(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
    }
}
void IMouseMove::leftButtonPressEvent(int i, int j)
{

}

void IMouseMove::rightButtonPressEvent(int i, int j)
{

}

void IMouseMove::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (inSelectLeft)
        leftButtonMoveEvent(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
    if (inSelectRight)
        rightButtonMoveEvent(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
}
void IMouseMove::leftButtonMoveEvent(int i, int j)
{

}

void IMouseMove::rightButtonMoveEvent(int i, int j)
{

}

void IMouseMove::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button()==Qt::LeftButton)
    {
        inSelectLeft=false;
        leftButtonReleaseEvent(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
    }
    if (mouseEvent->button()==Qt::RightButton)
    {
        inSelectRight=false;
        rightButtonReleaseEvent(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
	}
	UndoSingleton::getInstance()->endGroup();
}
void IMouseMove::leftButtonReleaseEvent(int i, int j)
{

}

void IMouseMove::rightButtonReleaseEvent(int i, int j)
{

}

void IMouseMove::contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent)
{

}
