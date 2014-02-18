#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    chipsetView = new ChipsetView();
    ui->graphicsViewChipset->setScene(chipsetView);

    mapView = new MapView();
    ui->graphicsViewMap->setScene(mapView);

    map = NULL;

    mapView->setPaintStrategy(new BrushStrategy(mapView,chipsetView));
    mapView->setDisplayStrategy(new DisplayLowerLayerStrategy(mapView));

    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openMap()));
    connect(ui->actionZoom_1_1,SIGNAL(triggered()),this,SLOT(minimizeMap()));
    connect(ui->actionZoom_1_2,SIGNAL(triggered()),this,SLOT(maximizeMap()));

    connect(ui->actionLawer_layer,SIGNAL(triggered()),this,SLOT(lowerLayer()));
    connect(ui->actionHigh_layer,SIGNAL(triggered()),this,SLOT(higherLayer()));
    connect(ui->actionCollision_layer,SIGNAL(triggered()),this,SLOT(collisionLayer()));
    connect(ui->actionVisualization,SIGNAL(triggered()),this,SLOT(visuaLayer()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete chipsetView;
    delete mapView;
    if (map != NULL)
        delete map;
}

void MainWindow::openMap()
{
    QString file = QFileDialog::getOpenFileName(this, "Open a map", QString(), "Map Zelda (*.k2x)");
    if (file != "")
    {
        map = new Model::Map(file);
        QFile fileMap(file);
        fileMap.open(QIODevice::ReadOnly);
        QDataStream stream(&fileMap);
        stream >> map;
        map->setNameMap(file);
        fileMap.close();
        QString title = "Zelda Map Editor - " + file;
        setWindowTitle(title);
        mapView->setMap(map);
        chipsetView->loadChipset(map->getChipset());

    }
}

void MainWindow::maximizeMap()
{
    QTransform matrix;
    matrix.scale(0.5,0.5);
    ui->graphicsViewMap->setTransform(matrix);
    ui->actionZoom_1_1->setChecked(false);
}

void MainWindow::minimizeMap()
{
    QTransform matrix;
    matrix.scale(1,1);
    ui->graphicsViewMap->setTransform(matrix);
    ui->actionZoom_1_2->setChecked(false);
}

void MainWindow::lowerLayer()
{
    ui->actionHigh_layer->setChecked(false);
    ui->actionVisualization->setChecked(false);
    ui->actionCollision_layer->setChecked(false);
    mapView->setDisplayStrategy(new DisplayLowerLayerStrategy(mapView));
    mapView->displayMap();
}

void MainWindow::higherLayer()
{
    ui->actionLawer_layer->setChecked(false);
    ui->actionVisualization->setChecked(false);
    ui->actionCollision_layer->setChecked(false);
    mapView->setDisplayStrategy(new DisplayHigherLayerStrategy(mapView));
    mapView->displayMap();
}

void MainWindow::collisionLayer()
{
    ui->actionLawer_layer->setChecked(false);
    ui->actionHigh_layer->setChecked(false);
    ui->actionVisualization->setChecked(false);
    mapView->setDisplayStrategy(new DisplayCollisionLayerStrategy(mapView));
    mapView->displayMap();
}

void MainWindow::visuaLayer()
{
    ui->actionHigh_layer->setChecked(false);
    ui->actionLawer_layer->setChecked(false);
    ui->actionCollision_layer->setChecked(false);
    mapView->setDisplayStrategy(new DisplayVisuaLayerStrategy(mapView));
    mapView->displayMap();
}
