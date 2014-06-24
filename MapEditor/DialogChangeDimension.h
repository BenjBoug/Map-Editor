#ifndef DIALOGCHANGEDIMENSION_H
#define DIALOGCHANGEDIMENSION_H

#include <QDialog>

#include "UndoSingleton.h"
#include "command/ChangeDimensionCommand.h"
#include "Map.h"
#include "Constantes.h"

namespace Ui {
class DialogChangeDimension;
}

class DialogChangeDimension : public QDialog
{
    Q_OBJECT

public:
	explicit DialogChangeDimension(Model::Map * map,QWidget *parent = 0);
    ~DialogChangeDimension();

public slots:
    void accept();

private:
    Ui::DialogChangeDimension *ui;

	Model::Map * map;
};

#endif // DIALOGCHANGEDIMENSION_H
