#ifndef MDICHILD_H
#define MDICHILD_H

#include <QGraphicsView>
#include "MapView.h"
#include "ChipsetView.h"
#include "BrushStrategy.h"
#include "PaintPotStratgey.h"
#include "PipetteStrategy.h"
#include "DisplayLowerLayerStrategy.h"
#include "DisplayHigherLayerStrategy.h"
#include "DisplayVisuaLayerStrategy.h"
#include "DisplayCollisionLayerStrategy.h"
#include "GridLayerStratgey.h"

class MdiChild : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MdiChild(ChipsetView * chipsetView,QWidget *parent = 0);

signals:

public slots:

    void newMap();
    void openMap(QString filename);

private:
    Model::Map * map;
    MapView * mapView;
    ChipsetView * chipsetView;

    DisplayLowerLayerStrategy *lowLayerStrategy;
    DisplayHigherLayerStrategy *highLayerStrategy;
    DisplayVisuaLayerStrategy *visuaLayerStrategy;
    DisplayCollisionLayerStrategy * collideLayerStrategy;
    GridLayerStratgey * gridLayerStrategy;

    BrushStrategy * brushStrategy;
    PaintPotStrategy * paintPotStrategy;
    PipetteStrategy * pipetteStrategy;
};

#endif // MDICHILD_H
