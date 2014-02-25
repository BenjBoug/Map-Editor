#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ChipsetView.h"
#include <Map.h>
#include <QFileDialog>
#include <QDataStream>
#include "MapView.h"
#include "BrushStrategy.h"
#include "PaintPotStratgey.h"
#include "PipetteStrategy.h"
#include "DisplayLowerLayerStrategy.h"
#include "DisplayHigherLayerStrategy.h"
#include "DisplayVisuaLayerStrategy.h"
#include "DisplayCollisionLayerStrategy.h"
#include "GridLayerStratgey.h"
#include "GroupeCheckBox.h"
#include "ChangeChipsetCommand.h"
#include "ClearMapCommand.h"
#include "UndoSingleton.h"
#include "DialogChangeName.h"
#include "MdiChild.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MdiChild *createMdiChild();

public slots:
    void newMap();
    void openMap();
    void maximizeMap();
    void minimizeMap();

    void lowerLayer();
    void higherLayer();
    void collisionLayer();
    void visuaLayer();

    void changeChipset();
    void clearMap();

    void brushTool();
    void paintPotTool();
    void pipetteTool();

    void save();

    void changeName();

    void gridLayer(bool enable);

    
private:
    GroupeCheckBox groupZoom,groupLayers,groupTools;
    Ui::MainWindow *ui;
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

#endif // MAINWINDOW_H
