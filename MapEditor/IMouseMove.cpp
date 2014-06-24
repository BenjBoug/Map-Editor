#include "IMouseMove.h"

IMouseMove::IMouseMove()
{
	inSelect=false;
}

void IMouseMove::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button()==Qt::LeftButton)
    {
		UndoSingleton::getInstance()->beginGroup();
		inSelect=true;
        leftButtonPressEvent(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
		current = QPoint(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
	}
}
void IMouseMove::leftButtonPressEvent(int,int)
{

}


void IMouseMove::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	QPoint tmp = QPoint(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
	if (tmp!=current)
	{
		if (inSelect)
		{
			leftButtonMoveEvent(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
			current = QPoint(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
		}
	}
}
void IMouseMove::leftButtonMoveEvent(int,int)
{

}


void IMouseMove::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button()==Qt::LeftButton)
    {
		inSelect=false;
        leftButtonReleaseEvent(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE);
		UndoSingleton::getInstance()->endGroup();
	}
}
void IMouseMove::leftButtonReleaseEvent(int,int)
{

}

void IMouseMove::contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent)
{

}
