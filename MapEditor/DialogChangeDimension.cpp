#include "DialogChangeDimension.h"
#include "ui_DialogChangeDimension.h"

DialogChangeDimension::DialogChangeDimension(MapView * mapView,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChangeDimension)
{
    this->mapView=mapView;
    ui->setupUi(this);
    ui->widthEdit->setMinimum(NB_BLOCS_LARGEUR);
    ui->heightEdit->setMinimum(NB_BLOCS_HAUTEUR);
    ui->widthEdit->setValue(mapView->getMap()->getSize().width());
    ui->heightEdit->setValue(mapView->getMap()->getSize().height());
}

DialogChangeDimension::~DialogChangeDimension()
{
    delete ui;
}

void DialogChangeDimension::accept()
{
    QSize newSize(ui->widthEdit->value(),ui->heightEdit->value());
	EXECUTE_CMD(new ChangeDimensionCommand(mapView,newSize));
    QDialog::accept();
}
