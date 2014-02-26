#include "MdiChild.h"

MdiChild::MdiChild(ChipsetView *chipsetView, QWidget *parent) :
    QGraphicsView(parent)
{
    this->chipsetView=chipsetView;
    this->setBackgroundBrush(QBrush(QColor(107, 189, 107)));
    this->setMouseTracking(true);
    isUntitled = true;
}

void MdiChild::newMap()
{
    map = new Map();
    mapView = new MapView();
    initTool();
    mapView->setDisplayStrategy(lowLayerStrategy);
    mapView->setPaintStrategy(brushStrategy);
    mapView->setMap(map);
    this->setScene(mapView);
    this->setWindowTitle(map->getName());
    isUntitled = true;
}

bool MdiChild::openMap(QString fileName)
{
    map = new Map();
    if (!map->load(fileName))
    {
        QMessageBox::warning(this, tr("K1X"),
                             tr("Cannot read file %.")
                             .arg(fileName));
        return false;
    }
    mapView = new MapView();

    initTool();

    mapView->setDisplayStrategy(lowLayerStrategy);
    mapView->setPaintStrategy(brushStrategy);
    mapView->setMap(map);
    mapView->displayMap();

    this->setScene(mapView);
    this->chipsetView->loadChipset(map->getChipset());
    this->setWindowTitle(map->getName());

    setCurrentFile(fileName);

    return true;
}

void MdiChild::lowerLayer()
{
    mapView->setDisplayStrategy(lowLayerStrategy);
    mapView->displayMap();
}

void MdiChild::higherLayer()
{
    mapView->setDisplayStrategy(highLayerStrategy);
    mapView->displayMap();
}

void MdiChild::collisionLayer()
{
    mapView->setDisplayStrategy(collideLayerStrategy);
    mapView->displayMap();
}

void MdiChild::visuaLayer()
{
    mapView->setDisplayStrategy(visuaLayerStrategy);
    mapView->displayMap();
}

void MdiChild::changeChipset()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Load a chipset", QString(), "Chipset (*.bmp)");
    if (fichier != "")
    {
        UndoSingleton::getInstance()->execute(new ChangeChipsetCommand(mapView,chipsetView,fichier));
    }
}

void MdiChild::clearMap()
{
    UndoSingleton::getInstance()->execute(new ClearMapCommand(mapView));
}

void MdiChild::brushTool()
{
    mapView->setPaintStrategy(brushStrategy);
}

void MdiChild::paintPotTool()
{
    mapView->setPaintStrategy(paintPotStrategy);
}

void MdiChild::pipetteTool()
{
    mapView->setPaintStrategy(pipetteStrategy);
}

void MdiChild::changeName()
{
    DialogChangeName * fen = new DialogChangeName(map,this);
    fen->show();
}

void MdiChild::gridLayer(bool enable)
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


bool MdiChild::save()
{
    if (isUntitled) {
        return saveAs();
    } else {
        return saveMap(curFile);
    }
}

bool MdiChild::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    curFile);
    if (fileName.isEmpty())
        return false;

    return saveMap(fileName);
}

bool MdiChild::saveMap(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::warning(this, tr("K2X"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QDataStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << map;
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    return true;
}


void MdiChild::initTool()
{
    lowLayerStrategy = new DisplayLowerLayerStrategy(mapView);
    highLayerStrategy = new DisplayHigherLayerStrategy(mapView);
    collideLayerStrategy = new DisplayCollisionLayerStrategy(mapView);
    visuaLayerStrategy = new DisplayVisuaLayerStrategy(mapView);
    gridLayerStrategy = new GridLayerStratgey(mapView);

    brushStrategy = new BrushStrategy(mapView,chipsetView);
    paintPotStrategy = new PaintPotStrategy(mapView,chipsetView);
    pipetteStrategy = new PipetteStrategy(mapView,chipsetView);

}

void MdiChild::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    setWindowModified(false);
    setWindowTitle(strippedName(curFile) + "[*]");
}

QString MdiChild::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
