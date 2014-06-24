#include "MdiChild.h"

MdiChild::MdiChild(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setMouseTracking(true);
    this->setBackgroundBrush(Qt::lightGray);

	isUntitled = true;

	this->chipsetView=new ChipsetView();
	this->mapView = new MapView();
	this->map = new Map();

	connect(this->map,SIGNAL(chipsetChanged(QPixmap)),this->chipsetView,SLOT(setChipset(QPixmap)));

	connect(this->mapView,SIGNAL(contensChanged()),this,SLOT(mapWasModified()));

	this->setScene(mapView);

	initTool();
}

void MdiChild::closeEvent(QCloseEvent *event)
{
	if (maybeSave()) {
		event->accept();
	} else {
		event->ignore();
	}
}
bool MdiChild::maybeSave()
{
 if (mapView->isModified()) {
	 QMessageBox::StandardButton ret;
	 ret = QMessageBox::warning(this, tr("MDI"),
				  tr("'%1' has been modified.\n"
					 "Do you want to save your changes?")
				  .arg(userFriendlyCurrentFile()),
				  QMessageBox::Save | QMessageBox::Discard
				  | QMessageBox::Cancel);
	 if (ret == QMessageBox::Save)
		 return save();
	 else if (ret == QMessageBox::Cancel)
		 return false;
 }
 return true;
}
void MdiChild::setCurrentFile(const QString &fileName)
{
	curFile = QFileInfo(fileName).canonicalFilePath();
	isUntitled = false;
	mapView->setModified(false);
	setWindowModified(false);
	setWindowTitle(userFriendlyCurrentFile() + "[*]");
}
bool MdiChild::newMap()
{
	DialogNewMap *fen = new DialogNewMap(map,this);
	if (fen->exec() == QDialog::Accepted)
	{
		//set the mapView with the new map
		mapView->setMap(map);

		//set the chipsetView with the chipset of the new map
		chipsetView->setChipset(map->getChipset());

		//display the map
		mapView->displayBackground();
		mapView->displayMap();

		this->setWindowTitle(map->getName());
		isUntitled = true;

		return true;
	}
	else
		return false;
}

bool MdiChild::openMap(QString fileName)
{
	//load the map from the file
    if (!map->load(fileName))
    {
        QMessageBox::warning(this, tr("K2X"),
                             tr("Cannot read file %.")
                             .arg(fileName));
        return false;
	}

	//init the mapView with the map
	mapView->setMap(map);

	chipsetView->setChipset(map->getChipset());
	//display the map
	mapView->displayBackground();
    mapView->displayMap();


    this->setWindowTitle(map->getName());

    setCurrentFile(fileName);

    return true;
}

QString MdiChild::userFriendlyCurrentFile()
{
    return strippedName(curFile);
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

void MdiChild::changeDimension()
{
	DialogChangeDimension * fen = new DialogChangeDimension(map,this);
    fen->show();
}

void MdiChild::changeChipset()
{
	QString file = QFileDialog::getOpenFileName(this, "Load a chipset", QString(), "Chipset (*.bmp)");
	if (file != "")
	{
		EXECUTE_CMD(new ChangeChipsetCommand(map,file));
	}
}

void MdiChild::clearMap()
{
	EXECUTE_CMD(new ClearMapCommand(map));
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

void MdiChild::rectangleTool()
{
	mapView->setPaintStrategy(rectangleStrategy);
}

void MdiChild::circleTool()
{
	mapView->setPaintStrategy(circleStrategy);
}

void MdiChild::selectionTool()
{
	mapView->setPaintStrategy(selectionStrategy);
}

void MdiChild::copy()
{

}

void MdiChild::cut()
{
	if (mapView->getCurrentPaint()==selectionStrategy)
	{

	}
}

void MdiChild::paste()
{

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


void MdiChild::changeBackground()
{

}

void MdiChild::mapWasModified()
{
	setWindowModified(mapView->isModified());
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

ChipsetView *MdiChild::getChipsetView() const
{
	return chipsetView;
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
	rectangleStrategy = new RectangleStrategy(mapView,chipsetView);
	circleStrategy = new CircleStrategy(mapView,chipsetView);
	selectionStrategy = new SelectionStrategy(mapView,chipsetView);

	lowLayerStrategy->addAllowedTool(brushStrategy);
	lowLayerStrategy->addAllowedTool(paintPotStrategy);
	lowLayerStrategy->addAllowedTool(pipetteStrategy);
	lowLayerStrategy->addAllowedTool(rectangleStrategy);
	lowLayerStrategy->addAllowedTool(circleStrategy);
	lowLayerStrategy->addAllowedTool(selectionStrategy);

	highLayerStrategy->addAllowedTool(brushStrategy);
	highLayerStrategy->addAllowedTool(paintPotStrategy);
	highLayerStrategy->addAllowedTool(pipetteStrategy);
	highLayerStrategy->addAllowedTool(rectangleStrategy);
	highLayerStrategy->addAllowedTool(circleStrategy);
	highLayerStrategy->addAllowedTool(selectionStrategy);

	collideLayerStrategy->addAllowedTool(brushStrategy);


	mapView->setDisplayStrategy(lowLayerStrategy);
	mapView->setPaintStrategy(brushStrategy);

}

QString MdiChild::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
