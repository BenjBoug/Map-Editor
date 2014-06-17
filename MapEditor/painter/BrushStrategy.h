#ifndef BRUSHSTRATEGY_H
#define BRUSHSTRATEGY_H

#include "PaintStrategy.h"
#include <QVector>
#include <QDebug>
#include "MapView.h"
#include "ChipsetView.h"
#include "command/EraseCommand.h"
#include "command/BlitCommand.h"
#include "UndoSingleton.h"

class BrushStrategy : public PaintStrategy
{
public:
    BrushStrategy(MapView * mapView, ChipsetView * chipsetView);

    void leftButtonPressEvent(int i, int j);
    void rightButtonPressEvent(int i, int j);

    void leftButtonMoveEvent(int i, int j);
    void rightButtonMoveEvent(int i, int j);


private:

	bool isntInBlitted(int x, int y, int w=1,int h=1) const;

    void blit(int x,int y);
    QRect blited;
    bool inSelect, inSelectRight;
    int idCmd;
};

#endif // BRUSHSTRATEGY_H
