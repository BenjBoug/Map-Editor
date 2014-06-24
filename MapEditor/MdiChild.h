#ifndef MDICHILD_H
#define MDICHILD_H

#include <QGraphicsView>
#include "MapView.h"
#include "ChipsetView.h"
#include "painter/BrushStrategy.h"
#include "painter/PaintPotStratgey.h"
#include "painter/PipetteStrategy.h"
#include "painter/RectangleStrategy.h"
#include "painter/CircleStrategy.h"
#include "painter/SelectionStrategy.h"
#include "layer/DisplayLowerLayerStrategy.h"
#include "layer/DisplayHigherLayerStrategy.h"
#include "layer/DisplayVisuaLayerStrategy.h"
#include "layer/DisplayCollisionLayerStrategy.h"
#include "layer/GridLayerStratgey.h"
#include "ClipBoardSingleton.h"
#include "command/ChangeChipsetCommand.h"
#include "command/ClearMapCommand.h"
#include "command/CutCommand.h"
#include "command/PasteCommand.h"
#include "DialogChangeDimension.h"
#include "DialogNewMap.h"
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

	void closeEvent(QCloseEvent *event);
	bool maybeSave();
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
	bool newMap();
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
	void selectionTool();

	void copy();
	void cut();
	void paste();

    bool save();
    bool saveAs();
	void gridLayer(bool enable);
	void changeBackground();

	void mapWasModified();

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
	RectangleStrategy * rectangleStrategy;
	CircleStrategy * circleStrategy;
	SelectionStrategy * selectionStrategy;

    QList<bool> listActions;
};

#endif // MDICHILD_H
