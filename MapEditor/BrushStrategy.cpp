#include "BrushStrategy.h"

BrushStrategy::BrushStrategy(MapView *mapView, ChipsetView *chipsetView)
    : PaintStrategy(mapView,chipsetView)
{
}

void BrushStrategy::execute()
{
    qDebug() << "brush !";
    QVector<QVector<int> > selectedTile = chipsetView->getSelectedTile();
    for(int i=0;i<selectedTile.size();i++)
    {
        for(int j=0;j<selectedTile[i].size();j++)
        {
            mapView->getLayerStrategy()->setBloc(i,j,selectedTile[i][j]);
        }
    }
}
