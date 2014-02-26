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

    createGroupButtons();

    connect(UndoSingleton::getInstance(),SIGNAL(redoEmpty(bool)),ui->actionRedo,SLOT(setEnabled(bool)));
    connect(UndoSingleton::getInstance(),SIGNAL(undoEmpty(bool)),ui->actionUndo,SLOT(setEnabled(bool)));

    connect(ui->actionRedo,SIGNAL(triggered()),UndoSingleton::getInstance(),SLOT(redo()));
    connect(ui->actionUndo,SIGNAL(triggered()),UndoSingleton::getInstance(),SLOT(undo()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete chipsetView;
}

MdiChild *MainWindow::activeMdiChild()
{
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0;
}

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

void MainWindow::setActiveSubWindow(QWidget *window)
{
    if (!window)
        return;
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
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

        QMdiSubWindow *existing = findMdiChild(fileName);
        if (existing) {
            ui->mdiArea->setActiveSubWindow(existing);
            return;
        }

        MdiChild *child = createMdiChild();
        if (child->openMap(fileName)) {
            statusBar()->showMessage(tr("File loaded"), 2000);
            child->show();
        } else {
            child->close();
        }
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
void MainWindow::changeName()
{
    if (activeMdiChild())
        activeMdiChild()->changeName();
}

void MainWindow::gridLayer(bool enable)
{
    if (activeMdiChild())
        activeMdiChild()->gridLayer(enable);
}

void MainWindow::createGroupButtons()
{
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
}
