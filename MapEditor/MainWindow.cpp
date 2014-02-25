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
/*
    lowLayerStrategy = new DisplayLowerLayerStrategy(mapView);
    highLayerStrategy = new DisplayHigherLayerStrategy(mapView);
    collideLayerStrategy = new DisplayCollisionLayerStrategy(mapView);
    visuaLayerStrategy = new DisplayVisuaLayerStrategy(mapView);
    gridLayerStrategy = new GridLayerStratgey(mapView);

    ui->graphicsViewMap->setBackgroundBrush(QBrush(QColor(107, 189, 107)));

    brushStrategy = new BrushStrategy(mapView,chipsetView);
    paintPotStrategy = new PaintPotStrategy(mapView,chipsetView);
    pipetteStrategy = new PipetteStrategy(mapView,chipsetView);
    //mapView->setPaintStrategy(brushStrategy);
    //mapView->setDisplayStrategy(lowLayerStrategy);
    //mapView->setMap(map);
*/
    groupZoom.addAction(ui->actionZoom_1_1);
    groupZoom.addAction(ui->actionZoom_1_2);

    groupLayers.addAction(ui->actionLawer_layer);
    groupLayers.addAction(ui->actionHigh_layer);
    groupLayers.addAction(ui->actionCollision_layer);
    groupLayers.addAction(ui->actionVisualization);

    groupTools.addAction(ui->actionBrush);
    groupTools.addAction(ui->actionCircle);
    groupTools.addAction(ui->actionRectangle);
    groupTools.addAction(ui->actionPipette);
    groupTools.addAction(ui->actionPaint_pot);

    connect(UndoSingleton::getInstance(),SIGNAL(redoEmpty(bool)),ui->actionRedo,SLOT(setEnabled(bool)));
    connect(UndoSingleton::getInstance(),SIGNAL(undoEmpty(bool)),ui->actionUndo,SLOT(setEnabled(bool)));

    connect(ui->actionRedo,SIGNAL(triggered()),UndoSingleton::getInstance(),SLOT(redo()));
    connect(ui->actionUndo,SIGNAL(triggered()),UndoSingleton::getInstance(),SLOT(undo()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete chipsetView;
    //delete mapView;
}

void MainWindow::newMap()
{
    MdiChild *child = createMdiChild();
    child->newMap();
    child->show();
}

MdiChild *MainWindow::createMdiChild()
{
    MdiChild *child = new MdiChild(chipsetView);
    ui->mdiArea->addSubWindow(child);
    return child;
}
void MainWindow::openMap()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a map", QString(), "Map Zelda (*.k2x)");
    if (!fileName.isEmpty()) {
        /*
        QMdiSubWindow *existing = findMdiChild(fileName);
        if (existing) {
            mdiArea->setActiveSubWindow(existing);
            return;
        }*/

        MdiChild *child = createMdiChild();
        child->openMap(fileName);
        child->show();
        /*
        if (child->openMap(fileName)) {
            statusBar()->showMessage(tr("File loaded"), 2000);
            child->show();
        } else {
            child->close();
        }*/
    }
}

void MainWindow::maximizeMap()
{
    QTransform matrix;
    matrix.scale(0.5,0.5);
    //ui->graphicsViewMap->setTransform(matrix);
}

void MainWindow::minimizeMap()
{
    QTransform matrix;
    matrix.scale(1,1);
    //ui->graphicsViewMap->setTransform(matrix);
}

void MainWindow::lowerLayer()
{/*
    mapView->setDisplayStrategy(lowLayerStrategy);
    mapView->displayMap();*/
}

void MainWindow::higherLayer()
{/*
    mapView->setDisplayStrategy(highLayerStrategy);
    mapView->displayMap();*/
}

void MainWindow::collisionLayer()
{/*
    mapView->setDisplayStrategy(collideLayerStrategy);
    mapView->displayMap();*/
}

void MainWindow::visuaLayer()
{/*
    mapView->setDisplayStrategy(visuaLayerStrategy);
    mapView->displayMap();*/
}

void MainWindow::changeChipset()
{/*
    QString fichier = QFileDialog::getOpenFileName(this, "Load a chipset", QString(), "Chipset (*.bmp)");
    if (fichier != "")
    {
        UndoSingleton::getInstance()->execute(new ChangeChipsetCommand(mapView,chipsetView,fichier));
    }*/
}

void MainWindow::clearMap()
{
    //UndoSingleton::getInstance()->execute(new ClearMapCommand(mapView));
}

void MainWindow::brushTool()
{
    //mapView->setPaintStrategy(brushStrategy);
}

void MainWindow::paintPotTool()
{
    //mapView->setPaintStrategy(paintPotStrategy);
}

void MainWindow::pipetteTool()
{
    //mapView->setPaintStrategy(pipetteStrategy);
}

void MainWindow::save()
{
    /*
    QFile file(map->getName());
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << map;
    file.close();*/
}

void MainWindow::changeName()
{
    /*
    DialogChangeName * fen = new DialogChangeName(map,this);
    fen->show();*/
}

void MainWindow::gridLayer(bool enable)
{/*
    if(enable)
    {
        mapView->setGridStrategy(new GridLayerStratgey(mapView));
    }
    else
    {
        mapView->setGridStrategy(NULL);
    }
    mapView->displayMap();*/
}
