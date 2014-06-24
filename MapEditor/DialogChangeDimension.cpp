#include "DialogChangeDimension.h"
#include "ui_DialogChangeDimension.h"

DialogChangeDimension::DialogChangeDimension(Model::Map * map,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChangeDimension)
{
	this->map=map;
    ui->setupUi(this);
	ui->widthEdit->setMinimum(1);
	ui->heightEdit->setMinimum(1);
	ui->widthEdit->setValue(map->getSize().width());
	ui->heightEdit->setValue(map->getSize().height());
}

DialogChangeDimension::~DialogChangeDimension()
{
    delete ui;
}

void DialogChangeDimension::accept()
{
	EXECUTE_CMD(new ChangeDimensionCommand(map,QSize(ui->widthEdit->value(),ui->heightEdit->value())));
    QDialog::accept();
}
