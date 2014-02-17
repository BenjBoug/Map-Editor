#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ChipsetView.h"
#include <Map.h>
#include <QFileDialog>
#include <QDataStream>

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
    
private:
    Ui::MainWindow *ui;
    Model::Map *map;
};

#endif // MAINWINDOW_H
