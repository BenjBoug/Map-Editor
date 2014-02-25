#ifndef DIALOGCHANGENAME_H
#define DIALOGCHANGENAME_H

#include <QDialog>
#include "UndoSingleton.h"
#include "ChangeNameCommand.h"

namespace Ui {
class DialogChangeName;
}

class DialogChangeName : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChangeName(Model::Map * map, QWidget *parent = 0);
    ~DialogChangeName();

public slots:
    void accept();

private:
    Ui::DialogChangeName *ui;
    Model::Map * map;
};

#endif // DIALOGCHANGENAME_H
