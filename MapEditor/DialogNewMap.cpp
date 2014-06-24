#include "DialogNewMap.h"
#include "ui_DialogNewMap.h"

DialogNewMap::DialogNewMap(Model::Map *map, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogNewMap)
{
	ui->setupUi(this);
	this->map = map;

	ui->widthBox->setValue(map->getSize().width());
	ui->heightBox->setValue(map->getSize().height());
	connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(checkValues()));
	connect(ui->browseButton,SIGNAL(clicked()),this,SLOT(getChipsetFile()));
}

DialogNewMap::~DialogNewMap()
{
	delete ui;
}

void DialogNewMap::accept()
{
	map->setChipset(chipset);
	map->setSize(ui->widthBox->value(),ui->heightBox->value());
	QDialog::accept();
}


void DialogNewMap::checkValues()
{
	if (!ui->browseLineEdit->text().isEmpty() && chipset.load(ui->browseLineEdit->text()))
		accept();
	else
		(void) QMessageBox::information(this, tr("No chipset"), tr("Please select a chipset."), QMessageBox::Cancel);

}

void DialogNewMap::getChipsetFile()
{
	QString file = QFileDialog::getOpenFileName(this, tr("Open Chipset"), QSettings().value("chipsetDir",QString()).toString(), tr("Images (*.png *.bmp *.jpg)"));
	if (!file.isEmpty())
	{
		QFileInfo infos(file);
		QSettings().setValue("chipsetDir",infos.absoluteDir().absolutePath());
		ui->browseLineEdit->setText(file);
	}
}
