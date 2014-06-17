#ifndef MDICHILD_H
#define MDICHILD_H

#include <QGraphicsView>
#include "MapView.h"
#include "ChipsetView.h"
#include "painter/BrushStrategy.h"
#include "painter/PaintPotStratgey.h"
#include "painter/PipetteStrategy.h"
#include "layer/DisplayLowerLayerStrategy.h"
#include "layer/DisplayHigherLayerStrategy.h"
#include "layer/DisplayVisuaLayerStrategy.h"
#include "layer/DisplayCollisionLayerStrategy.h"
#include "layer/GridLayerStratgey.h"
#include "command/ChangeChipsetCommand.h"
#include "command/ClearMapCommand.h"
#include "DialogChangeDimension.h"
#include <QMessageBox>
#include <QFileInfo>
#include <QFileDialog>
#include <QApplication>
#include <QList>
#include <exception>
#include <QDebug>

class MdiChild : public QGraphicsView
{
    Q_OBJECT
public:
	explicit MdiChild(QWidget *parent = 0);

    QString currentFile() { return curFile; }
    QString userFriendlyCurrentFile();

    bool saveMap(const QString &fileName);

    QList<bool> getListactions()
    {
        return listActions;
    }

    void setListActions(QList<bool> list)
    {
        listActions = list;
    }

	ChipsetView * getChipsetView() const;

signals:

public slots:
    void newMap();
    bool openMap(QString fileName);
    void lowerLayer();
    void higherLayer();
    void collisionLayer();
    void visuaLayer();
    void changeDimension();
    void changeChipset();
    void clearMap();
    void brushTool();
    void paintPotTool();
    void pipetteTool();
	void rectangleTool();
	void circleTool();
    bool save();
    bool saveAs();
    void gridLayer(bool enable);
    void updateChipset();
    void updateChipset(QString file);
	void changeBackground();

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

    QList<bool> listActions;
};

#endif // MDICHILD_H
