#include "DialogChangeName.h"
#include "ui_DialogChangeName.h"

DialogChangeName::DialogChangeName(Model::Map *map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChangeName)
{
    ui->setupUi(this);
    this->map=map;
    ui->lineEdit->setText(map->getName());
}

DialogChangeName::~DialogChangeName()
{
    delete ui;
}

void DialogChangeName::accept()
{
    UndoSingleton::getInstance()->execute(new ChangeNameCommand(map,ui->lineEdit->text()));
    QDialog::accept();
}
