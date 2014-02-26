#ifndef MDICHILD_H
#define MDICHILD_H

#include <QGraphicsView>
#include "MapView.h"
#include "ChipsetView.h"
#include "BrushStrategy.h"
#include "PaintPotStratgey.h"
#include "PipetteStrategy.h"
#include "DisplayLowerLayerStrategy.h"
#include "DisplayHigherLayerStrategy.h"
#include "DisplayVisuaLayerStrategy.h"
#include "DisplayCollisionLayerStrategy.h"
#include "GridLayerStratgey.h"
#include "ChangeChipsetCommand.h"
#include "ClearMapCommand.h"
#include "DialogChangeName.h"
#include <QMessageBox>
#include <QFileInfo>
#include <QFileDialog>
#include <QApplication>

class MdiChild : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MdiChild(ChipsetView * chipsetView,QWidget *parent = 0);

    QString currentFile() { return curFile; }
    QString userFriendlyCurrentFile();

    bool saveMap(const QString &fileName);

signals:

public slots:

    void newMap();
    bool openMap(QString fileName);

    void lowerLayer();
    void higherLayer();
    void collisionLayer();
    void visuaLayer();

    void changeChipset();
    void clearMap();

    void brushTool();
    void paintPotTool();
    void pipetteTool();

    bool save();
    bool saveAs();

    void changeName();

    void gridLayer(bool enable);

    void updateChipset();

private:
    void initTool();
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QString curFile;
    bool isUntitled;

    Model::Map * map;
    MapView * mapView;
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

#endif // MDICHILD_H
