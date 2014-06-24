#ifndef DIALOGNEWMAP_H
#define DIALOGNEWMAP_H

#include <QDialog>
#include <QMessageBox>
#include "Map.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QSettings>

namespace Ui {
class DialogNewMap;
}

class DialogNewMap : public QDialog
{
	Q_OBJECT
	
public:
	explicit DialogNewMap(Model::Map * map,QWidget *parent = 0);
	~DialogNewMap();

	void accept();

public slots:
	void checkValues();
	void getChipsetFile();
	
private:
	Model::Map *map;
	QPixmap chipset;
	Ui::DialogNewMap *ui;
};

#endif // DIALOGNEWMAP_H
