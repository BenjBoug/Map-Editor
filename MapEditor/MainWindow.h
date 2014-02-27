#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ChipsetView.h"
#include <Map.h>
#include <QFileDialog>
#include <QDataStream>
#include "GroupeCheckBox.h"
#include "UndoSingleton.h"
#include "MdiChild.h"
#include <QMdiSubWindow>

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
    MdiChild *activeMdiChild();
    QMdiSubWindow *findMdiChild(const QString &fileName);
    void initCheckBoxMenu();

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
    void saveAs();

    void changeDimension();

    void gridLayer(bool enable);

    void updateMenus();
    void updateChipset();
    void updateWindowMenu();
    void saveActionMdi();
    void updateActionMdi();
    void setActiveSubWindow(QWidget *window);

    
private:
    QList<QAction*> getActionsCheckable();
    void createGroupButtons();

    GroupeCheckBox groupZoom,groupLayers,groupTools;
    Ui::MainWindow *ui;
    ChipsetView * chipsetView;
    QSignalMapper * windowMapper;
};

#endif // MAINWINDOW_H
