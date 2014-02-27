#ifndef DIALOGCHANGEDIMENSION_H
#define DIALOGCHANGEDIMENSION_H

#include <QDialog>

#include "UndoSingleton.h"
#include "ChangeDimensionCommand.h"
#include "MapView.h"
#include "Constantes.h"

namespace Ui {
class DialogChangeDimension;
}

class DialogChangeDimension : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChangeDimension(MapView * mapView,QWidget *parent = 0);
    ~DialogChangeDimension();

public slots:
    void accept();

private:
    Ui::DialogChangeDimension *ui;

    MapView * mapView;
};

#endif // DIALOGCHANGEDIMENSION_H
