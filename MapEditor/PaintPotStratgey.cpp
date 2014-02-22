#include "PaintPotStratgey.h"

PaintPotStrategy::PaintPotStrategy(MapView * mapView, ChipsetView * chipsetView)
    : PaintStrategy(mapView,chipsetView)
{
    this->mapView=mapView;
    this->chipsetView=chipsetView;
}

void PaintPotStrategy::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    int blocRef = mapView->getMap()->getBloc(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE)->getLayer(mapView->getLayerStrategy()->getLayer());
    paintPot(mouseEvent->scenePos().x()/BLOCSIZE,mouseEvent->scenePos().y()/BLOCSIZE,blocRef);
}


void PaintPotStrategy::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    ICommand::end();
}

void PaintPotStrategy::paintPot(int i, int j, int blocRef)
{
    if (mapView->getMap()->getBloc(i,j)->getLayer(mapView->getLayerStrategy()->getLayer())==blocRef)
    {
        QVector<QVector<int> > selectedTile = chipsetView->getSelectedTile();

        for(int x=0;x<selectedTile.size();x++)
        {
            for(int y=0;y<selectedTile[x].size();y++)
            {
                mapView->executeCmd(new EraseAndBlitCommand(mapView,i+x,j+y,selectedTile[x][y],mapView->getLayerStrategy()->getLayer()));
            }
        }

        if (i-selectedTile.size()>=0)
            paintPot(i-selectedTile.size(),j,blocRef);
        if (i+selectedTile.size()<mapView->getMap()->getDim().width())
            paintPot(i+selectedTile.size(),j,blocRef);
        if (j-selectedTile[0].size()>=0)
            paintPot(i,j-selectedTile[0].size(),blocRef);
        if (j+selectedTile[0].size()<mapView->getMap()->getDim().height())
            paintPot(i,j+selectedTile[0].size(),blocRef);
    }
}
