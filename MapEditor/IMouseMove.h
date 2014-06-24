#ifndef IMOUSEMOVE_H
#define IMOUSEMOVE_H

#include <QGraphicsSceneMouseEvent>
#include "command/ICommand.h"
#include "UndoSingleton.h"
#include "Constantes.h"

class IMouseMove
{
public:
    IMouseMove();

    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void leftButtonPressEvent(int,int);

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void leftButtonMoveEvent(int,int);

    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void leftButtonReleaseEvent(int,int);

    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent);

private:

	bool inSelect;
	QPoint current;
};

#endif // IMOUSEMOVE_H
