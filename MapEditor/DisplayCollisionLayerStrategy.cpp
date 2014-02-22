#include "DisplayCollisionLayerStrategy.h"

DisplayCollisionLayerStrategy::DisplayCollisionLayerStrategy(MapView * mapView)
    : LayerStrategy(mapView)
{
    inSelectLeft = false;
    inSelectRight=false;
}

void DisplayCollisionLayerStrategy::display()
{
    Model::Map * map = mapView->getMap();
    for(int i=0;i<map->getDim().width();i++)
    {
        for(int j=0;j<map->getDim().height();j++)
        {

            int couche1 = map->getBloc(i,j)->getCouche1();
            mapView->blitTile(i,j,couche1,LOW);
            int couche2 = map->getBloc(i,j)->getCouche2();
            mapView->blitTile(i,j,couche2,HIGH);

            int collide = map->getBloc(i,j)->getCollision();
            QFont font("Helvetica", 20, QFont::Bold);
            QGraphicsSimpleTextItem * collisionItem = mapView->addSimpleText(QString("%1").arg(collide),font);
            collisionItem->setBrush(Qt::lightGray);
            collisionItem->setPos(i*BLOCSIZE,j*BLOCSIZE);
            collisionItem->setZValue(COLLIDE);
        }
    }
}

int DisplayCollisionLayerStrategy::getLayer()
{
    return COLLIDE;
}

void DisplayCollisionLayerStrategy::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    int i=mouseEvent->scenePos().x()/BLOCSIZE;
    int j=mouseEvent->scenePos().y()/BLOCSIZE;
    if (mouseEvent->button()==Qt::LeftButton)
    {
        mapView->executeCmd(new CollideCommand(mapView,i,j,1));
        inSelectLeft = true;
    }
    else if (mouseEvent->button()==Qt::RightButton)
    {
        mapView->executeCmd(new CollideCommand(mapView,i,j,0));
        inSelectRight=true;
    }
}

void DisplayCollisionLayerStrategy::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    int i=mouseEvent->scenePos().x()/BLOCSIZE;
    int j=mouseEvent->scenePos().y()/BLOCSIZE;
    if (inSelectLeft)
    {
        mapView->executeCmd(new CollideCommand(mapView,i,j,1));
    }
    else if (inSelectRight)
    {
        mapView->executeCmd(new CollideCommand(mapView,i,j,0));
    }
}

void DisplayCollisionLayerStrategy::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    inSelectLeft = false;
    inSelectRight=false;
}


