#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    ChipsetView * chipsetView = new ChipsetView("../Resources/images/chipset/map.bmp",this);
    ui->scrollChipset->setWidget(chipsetView);


    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openMap()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openMap()
{
    QString file = QFileDialog::getOpenFileName(this, "Open a map", QString(), "Map Zelda (*.k2x)");
    if (file != "")
    {
        map = new Model::Map(file);
        QFile fileMap(file);
        fileMap.open(QIODevice::ReadOnly);
        QDataStream stream(&fileMap);
        stream >> map;
        fileMap.close();
        QString title = "Zelda Map Editor - " + file;
        setWindowTitle(title);
    }
}
