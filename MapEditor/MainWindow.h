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
    void setActiveSubWindow(QWidget *window);

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

    void changeName();

    void gridLayer(bool enable);

    
private:
    void createGroupButtons();

    GroupeCheckBox groupZoom,groupLayers,groupTools;
    Ui::MainWindow *ui;
    ChipsetView * chipsetView;
};

#endif // MAINWINDOW_H
