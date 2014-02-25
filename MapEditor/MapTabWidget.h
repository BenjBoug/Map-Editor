#ifndef MAPTABWIDGET_H
#define MAPTABWIDGET_H

#include <QTabWidget>
#include "MapView.h"
#include "ChipsetView.h"

namespace Ui {
class MapTabWidget;
}

class MapTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit MapTabWidget(QWidget *parent = 0);
    ~MapTabWidget();

    void init(Map *map);

    MapView *currentMapView();
    void addMap(Model::Map* map);

    ChipsetView *getChipsetView() const;
    void setChipsetView(ChipsetView *value);

signals:
    void mapChanged(QString chipset);

public slots:
    void changeCurrentMap();

private:
    Ui::MapTabWidget *ui;
    ChipsetView * chipsetView;
};

#endif // MAPTABWIDGET_H
