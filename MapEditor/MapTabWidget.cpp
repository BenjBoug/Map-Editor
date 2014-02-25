#include "MapTabWidget.h"
#include "ui_MapTabWidget.h"

MapTabWidget::MapTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::MapTabWidget)
{
    ui->setupUi(this);
    connect(this,SIGNAL(currentChanged(int)),this,SLOT(changeCurrentMap()));
}

MapTabWidget::~MapTabWidget()
{
    delete ui;
}

void MapTabWidget::init(Map *map)
{

}

MapView *MapTabWidget::currentMapView()
{
    return ((MapView*)((QGraphicsView*)currentWidget())->scene());
}

void MapTabWidget::addMap(Map *map)
{
    QGraphicsView* view = new QGraphicsView(this);
    MapView * scene = new MapView(map);
    view->setScene(scene);
    //this->addTab(view);
}
ChipsetView *MapTabWidget::getChipsetView() const
{
    return chipsetView;
}

void MapTabWidget::setChipsetView(ChipsetView *value)
{
    chipsetView = value;
    connect(this,SIGNAL(mapChanged(QString)),chipsetView,SLOT(loadChipset(QString)));
}

void MapTabWidget::changeCurrentMap()
{
    //emit mapChanged(currentMapView()->getChipset());
}

