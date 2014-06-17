#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	this->showMaximized();


    createGroupButtons();

    connect(UndoSingleton::getInstance(),SIGNAL(redoEmpty(bool)),ui->actionRedo,SLOT(setEnabled(bool)));
    connect(UndoSingleton::getInstance(),SIGNAL(undoEmpty(bool)),ui->actionUndo,SLOT(setEnabled(bool)));

    connect(ui->actionRedo,SIGNAL(triggered()),UndoSingleton::getInstance(),SLOT(redo()));
    connect(ui->actionUndo,SIGNAL(triggered()),UndoSingleton::getInstance(),SLOT(undo()));

    windowMapper = new QSignalMapper(this);
    connect(windowMapper, SIGNAL(mapped(QWidget*)),this, SLOT(setActiveSubWindow(QWidget*)));

    updateMenus();
}

MainWindow::~MainWindow()
{
	delete ui;
}

/**
 * @brief Saves the settings of the window
 */
void MainWindow::writeSettings() {
	QSettings settings;

	settings.beginGroup("MainWindow");
	settings.setValue("size", size());
	settings.setValue("pos", pos());

	//settings.setValue("");

	settings.endGroup();
}

/**
 * @brief Read and set the settings of the window
 */
void MainWindow::readSettings() {
	QSettings settings;

	settings.beginGroup("MainWindow");
	resize(settings.value("size", QSize(400, 400)).toSize());
	move(settings.value("pos", QPoint(200, 200)).toPoint());


	settings.endGroup();
}

/**
 * @brief Event called when the application is closed.
 * It saves the settings
 * @param event
 */
void MainWindow::closeEvent(QCloseEvent *event) {
	Q_UNUSED(event);
	writeSettings();
}

/**
 * @brief Return the current MdiChild or 0 if no MdiChild is opened.
 * @return the current MDIChild
 */
MdiChild *MainWindow::activeMdiChild()
{
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0;
}

/**
 * @brief Find a MdiChild with the filename of the map
 * @param fileName the filenae of the map
 * @return the MdiChild of the given filename
 */
QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName)
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
        MdiChild *mdiChild = qobject_cast<MdiChild *>(window->widget());
        if (mdiChild->currentFile() == canonicalFilePath)
            return window;
    }
    return 0;
}

void MainWindow::initCheckBoxMenu()
{
    ui->actionLawer_layer->setChecked(true);
    ui->actionHigh_layer->setChecked(false);
    ui->actionCollision_layer->setChecked(false);
    ui->actionVisualization->setChecked(false);
    ui->actionShow_Grid->setChecked(false);
    ui->actionZoom_1_1->setChecked(true);
    ui->actionZoom_1_2->setChecked(false);
    ui->actionBrush->setChecked(true);
    ui->actionPaint_pot->setChecked(false);
    ui->actionPipette->setChecked(false);
    saveActionMdi();
}

QString MainWindow::getChipsetFileName()
{
    return QFileDialog::getOpenFileName(this, "Load a chipset", QString(), "Chipset (*.bmp)");
}

void MainWindow::setActiveSubWindow(QWidget *window)
{
    if (!window)
        return;
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}

QList<QAction*> MainWindow::getActionsCheckable()
{
    QList<QAction*> actions;
    actions.push_back(ui->actionLawer_layer);
    actions.push_back(ui->actionHigh_layer);
    actions.push_back(ui->actionCollision_layer);
    actions.push_back(ui->actionVisualization);
    actions.push_back(ui->actionShow_Grid);
    actions.push_back(ui->actionZoom_1_1);
    actions.push_back(ui->actionZoom_1_2);
    actions.push_back(ui->actionBrush);
    actions.push_back(ui->actionPaint_pot);
    actions.push_back(ui->actionPipette);

    return actions;
}

MdiChild *MainWindow::createMdiChild()
{
	MdiChild *child = new MdiChild();
    ui->mdiArea->addSubWindow(child);
    return child;
}

void MainWindow::newMap()
{
	QString chipsetFile;
	if ((chipsetFile=getChipsetFileName()) != "")
	{
		MdiChild *child = createMdiChild();
		child->newMap();
		child->updateChipset(chipsetFile);
		child->show();
		UndoSingleton::getInstance()->clearUndo();
		UndoSingleton::getInstance()->clearRedo();
		initCheckBoxMenu();
		updateWindowMenu();
	}
}

void MainWindow::openMap()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a map", QString(), "Map Zelda (*.k2x)");
    if (!fileName.isEmpty()) {

        QMdiSubWindow *existing = findMdiChild(fileName);
        if (existing) {
            ui->mdiArea->setActiveSubWindow(existing);
            return;
        }

        MdiChild *child = createMdiChild();
        if (child->openMap(fileName)) {
            statusBar()->showMessage(tr("File loaded"), 2000);
            child->show();
            initCheckBoxMenu();
        } else {
            child->close();
        }
		updateWindowMenu();
    }
}

void MainWindow::maximizeMap()
{
    if (activeMdiChild())
    {
        QTransform matrix;
        matrix.scale(0.5,0.5);
        activeMdiChild()->setTransform(matrix);
    }
}

void MainWindow::minimizeMap()
{
    if (activeMdiChild())
    {
        QTransform matrix;
        matrix.scale(1,1);
        activeMdiChild()->setTransform(matrix);
    }
}

void MainWindow::lowerLayer()
{
    if (activeMdiChild())
        activeMdiChild()->lowerLayer();
}

void MainWindow::higherLayer()
{
    if (activeMdiChild())
        activeMdiChild()->higherLayer();
}

void MainWindow::collisionLayer()
{
    if (activeMdiChild())
        activeMdiChild()->collisionLayer();
}

void MainWindow::visuaLayer()
{
    if (activeMdiChild())
        activeMdiChild()->visuaLayer();
}

void MainWindow::changeChipset()
{
    if (activeMdiChild())
        activeMdiChild()->changeChipset();
}

void MainWindow::clearMap()
{
    if (activeMdiChild())
        activeMdiChild()->clearMap();
}

void MainWindow::brushTool()
{
    if (activeMdiChild())
        activeMdiChild()->brushTool();
}

void MainWindow::paintPotTool()
{
    if (activeMdiChild())
        activeMdiChild()->paintPotTool();
}

void MainWindow::pipetteTool()
{
    if (activeMdiChild())
		activeMdiChild()->pipetteTool();
}

void MainWindow::rectangleTool()
{
	if (activeMdiChild())
		activeMdiChild()->rectangleTool();
}

void MainWindow::circleTool()
{
	if (activeMdiChild())
		activeMdiChild()->circleTool();
}

void MainWindow::save()
{
    if (activeMdiChild() && activeMdiChild()->save())
        statusBar()->showMessage(tr("File saved"), 2000);
}

void MainWindow::saveAs()
{
    if (activeMdiChild() && activeMdiChild()->saveAs())
        statusBar()->showMessage(tr("File saved"), 2000);
}

void MainWindow::changeDimension()
{
    if (activeMdiChild())
		activeMdiChild()->changeDimension();
}

void MainWindow::changeBackground()
{
	if (activeMdiChild())
		activeMdiChild()->changeBackground();
}

void MainWindow::gridLayer(bool enable)
{
    if (activeMdiChild())
        activeMdiChild()->gridLayer(enable);
    saveActionMdi();
}

void MainWindow::createGroupButtons()
{
    groupZoom.addAction(ui->actionZoom_1_1);
    groupZoom.addAction(ui->actionZoom_1_2);
    connect(&groupZoom,SIGNAL(groupToggle()),this,SLOT(saveActionMdi()));

    groupLayers.addAction(ui->actionLawer_layer);
    groupLayers.addAction(ui->actionHigh_layer);
    groupLayers.addAction(ui->actionCollision_layer);
    groupLayers.addAction(ui->actionVisualization);
    connect(&groupLayers,SIGNAL(groupToggle()),this,SLOT(saveActionMdi()));

    groupTools.addAction(ui->actionBrush);
    groupTools.addAction(ui->actionPipette);
    groupTools.addAction(ui->actionPaint_pot);
	groupTools.addAction(ui->actionRectangle);
	groupTools.addAction(ui->actionCircle);
    connect(&groupTools,SIGNAL(groupToggle()),this,SLOT(saveActionMdi()));
}

void MainWindow::updateMenus()
{
    bool hasMdiChild = (activeMdiChild() != 0);
    ui->actionSave->setEnabled(hasMdiChild);
    ui->actionSave_as->setEnabled(hasMdiChild);
    ui->actionClose->setEnabled(hasMdiChild);
    ui->actionClose_All->setEnabled(hasMdiChild);
    ui->actionTile->setEnabled(hasMdiChild);
    ui->actionCascade->setEnabled(hasMdiChild);
    ui->actionNext->setEnabled(hasMdiChild);
    ui->actionPrevious->setEnabled(hasMdiChild);
    ui->actionLawer_layer->setEnabled(hasMdiChild);
    ui->actionHigh_layer->setEnabled(hasMdiChild);
    ui->actionCollision_layer->setEnabled(hasMdiChild);
    ui->actionVisualization->setEnabled(hasMdiChild);
    ui->actionBrush->setEnabled(hasMdiChild);
    ui->actionPaint_pot->setEnabled(hasMdiChild);
    ui->actionPipette->setEnabled(hasMdiChild);
    ui->actionShow_Grid->setEnabled(hasMdiChild);
    ui->actionZoom_1_1->setEnabled(hasMdiChild);
    ui->actionZoom_1_2->setEnabled(hasMdiChild);
	ui->actionRectangle->setEnabled(hasMdiChild);
	ui->actionCircle->setEnabled(hasMdiChild);
}

void MainWindow::updateChipset()
{
    if (activeMdiChild())
		ui->graphicsViewChipset->setScene(activeMdiChild()->getChipsetView());
}

void MainWindow::updateWindowMenu()
{
    ui->menuWindow->clear();
    ui->menuWindow->addAction(ui->actionClose);
    ui->menuWindow->addAction(ui->actionClose_All);
    ui->menuWindow->addSeparator();
    ui->menuWindow->addAction(ui->actionTile);
    ui->menuWindow->addAction(ui->actionCascade);
    ui->menuWindow->addSeparator();
    ui->menuWindow->addAction(ui->actionNext);
    ui->menuWindow->addAction(ui->actionPrevious);
    QAction * actionSeparator = ui->menuWindow->addSeparator();

    QList<QMdiSubWindow *> windows = ui->mdiArea->subWindowList();
    actionSeparator->setVisible(!windows.isEmpty());

    for (int i = 0; i < windows.size(); ++i) {
        MdiChild *child = qobject_cast<MdiChild *>(windows.at(i)->widget());

        QString text;
        if (i < 9) {
            text = tr("&%1 %2").arg(i+1).arg(child->userFriendlyCurrentFile());
        } else {
            text = tr("%1 %2").arg(i+1).arg(child->userFriendlyCurrentFile());
        }
        QAction *action  = ui->menuWindow->addAction(text);
        action->setCheckable(true);
        action->setChecked(child == activeMdiChild());

        connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));
        windowMapper->setMapping(action, windows.at(i));
    }
}

void MainWindow::saveActionMdi()
{
    if (activeMdiChild())
    {
        QList<bool> activeAction;
        QList<QAction*> actions = this->getActionsCheckable();
        QList<QAction*>::iterator it;
        for(it=actions.begin();it!=actions.end();it++)
        {
            activeAction.push_back((*it)->isChecked());
        }

        activeMdiChild()->setListActions(activeAction);
    }
}

void MainWindow::updateActionMdi()
{
    if (activeMdiChild()!=0)
    {
        QList<bool> activeAction = activeMdiChild()->getListactions();
        QList<bool>::iterator itAct;
        QList<QAction*> actions = this->getActionsCheckable();
        QList<QAction*>::iterator it;
        for(it=actions.begin(),itAct=activeAction.begin();it!=actions.end(),itAct!=activeAction.end();it++,itAct++)
        {
            (*it)->setChecked((*itAct));
        }
    }
}
