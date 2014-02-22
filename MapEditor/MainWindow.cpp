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

    lowLayerStrategy = new DisplayLowerLayerStrategy(mapView);
    highLayerStrategy = new DisplayHigherLayerStrategy(mapView);
    collideLayerStrategy = new DisplayCollisionLayerStrategy(mapView);
    visuaLayerStrategy = new DisplayVisuaLayerStrategy(mapView);
    gridLayerStrategy = new GridLayerStratgey(mapView);

    map = NULL;

    ui->graphicsViewMap->setBackgroundBrush(QBrush(QColor(107, 189, 107)));

    brushStrategy = new BrushStrategy(mapView,chipsetView);
    paintPotStrategy = new PaintPotStrategy(mapView,chipsetView);
    pipetteStrategy = new PipetteStrategy(mapView,chipsetView);
    mapView->setPaintStrategy(brushStrategy);
    mapView->setDisplayStrategy(lowLayerStrategy);

    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openMap()));

    groupZoom.addAction(ui->actionZoom_1_1);
    groupZoom.addAction(ui->actionZoom_1_2);
    connect(ui->actionZoom_1_1,SIGNAL(triggered()),this,SLOT(minimizeMap()));
    connect(ui->actionZoom_1_2,SIGNAL(triggered()),this,SLOT(maximizeMap()));

    groupLayers.addAction(ui->actionLawer_layer);
    groupLayers.addAction(ui->actionHigh_layer);
    groupLayers.addAction(ui->actionCollision_layer);
    groupLayers.addAction(ui->actionVisualization);
    connect(ui->actionLawer_layer,SIGNAL(triggered()),this,SLOT(lowerLayer()));
    connect(ui->actionHigh_layer,SIGNAL(triggered()),this,SLOT(higherLayer()));
    connect(ui->actionCollision_layer,SIGNAL(triggered()),this,SLOT(collisionLayer()));
    connect(ui->actionVisualization,SIGNAL(triggered()),this,SLOT(visuaLayer()));
    connect(ui->actionShow_Grid,SIGNAL(triggered(bool)),this,SLOT(gridLayer(bool)));

    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(save()));

    connect(ui->actionChange_chipset,SIGNAL(triggered()),this,SLOT(changeChipset()));

    connect(mapView,SIGNAL(redoEmpty(bool)),ui->actionRedo,SLOT(setEnabled(bool)));
    connect(mapView,SIGNAL(undoEmpty(bool)),ui->actionUndo,SLOT(setEnabled(bool)));
    connect(ui->actionRedo,SIGNAL(triggered()),mapView,SLOT(redo()));
    connect(ui->actionUndo,SIGNAL(triggered()),mapView,SLOT(undo()));

    connect(ui->actionBrush,SIGNAL(triggered()),this,SLOT(brushTool()));
    connect(ui->actionPaint_pot,SIGNAL(triggered()),this,SLOT(painPotTool()));

    connect(ui->actionPipette,SIGNAL(triggered()),this,SLOT(pipetteTool()));

    groupTools.addAction(ui->actionBrush);
    groupTools.addAction(ui->actionCircle);
    groupTools.addAction(ui->actionRectangle);
    groupTools.addAction(ui->actionPipette);
    groupTools.addAction(ui->actionPaint_pot);
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
        qDebug() << map->getChipset();
        chipsetView->loadChipset(map->getChipset());

    }
}

void MainWindow::maximizeMap()
{
    QTransform matrix;
    matrix.scale(0.5,0.5);
    ui->graphicsViewMap->setTransform(matrix);
}

void MainWindow::minimizeMap()
{
    QTransform matrix;
    matrix.scale(1,1);
    ui->graphicsViewMap->setTransform(matrix);
}

void MainWindow::lowerLayer()
{
    mapView->setDisplayStrategy(lowLayerStrategy);
    mapView->displayMap();
}

void MainWindow::higherLayer()
{
    mapView->setDisplayStrategy(highLayerStrategy);
    mapView->displayMap();
}

void MainWindow::collisionLayer()
{
    mapView->setDisplayStrategy(collideLayerStrategy);
    mapView->displayMap();
}

void MainWindow::visuaLayer()
{
    mapView->setDisplayStrategy(visuaLayerStrategy);
    mapView->displayMap();
}

void MainWindow::changeChipset()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Load a chipset", QString(), "Chipset (*.bmp)");
    if (fichier != "")
    {
        map->setNameChipset(fichier);
        chipsetView->loadChipset(fichier);
        mapView->loadChipset(fichier);
        mapView->displayMap();
    }
}

void MainWindow::brushTool()
{
    mapView->setPaintStrategy(brushStrategy);
}

void MainWindow::painPotTool()
{
    mapView->setPaintStrategy(paintPotStrategy);
}

void MainWindow::pipetteTool()
{
    mapView->setPaintStrategy(pipetteStrategy);
}

void MainWindow::save()
{
    QFile file(map->getNameMap());
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << map;
    file.close();
}

void MainWindow::gridLayer(bool enable)
{
    if(enable)
    {
        mapView->setGridStrategy(new GridLayerStratgey(mapView));
    }
    else
    {
        mapView->setGridStrategy(NULL);
    }
    mapView->displayMap();
}
