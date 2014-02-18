#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ChipsetView.h"
#include <Map.h>
#include <QFileDialog>
#include <QDataStream>
#include "MapView.h"
#include "BrushStrategy.h"
#include "DisplayLowerLayerStrategy.h"
#include "DisplayHigherLayerStrategy.h"
#include "DisplayVisuaLayerStrategy.h"
#include "DisplayCollisionLayerStrategy.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openMap();
    void maximizeMap();
    void minimizeMap();

    void lowerLayer();
    void higherLayer();
    void collisionLayer();
    void visuaLayer();

    
private:
    Ui::MainWindow *ui;
    Model::Map *map;
    MapView * mapView;
    ChipsetView * chipsetView;
};

#endif // MAINWINDOW_H
