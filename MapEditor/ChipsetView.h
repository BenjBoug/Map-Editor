#ifndef CHIPSETVIEW_H
#define CHIPSETVIEW_H

#include <QVector>
#include <QImage>
#include <Constantes.h>
#include <QMouseEvent>
#include <QRect>
#include <QWidget>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QGraphicsView>

class ChipsetView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ChipsetView();
	explicit ChipsetView(QPixmap chipset);
    explicit ChipsetView(QString chip);

    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

    QVector< QVector<int> > getSelectedTile();

    void selectTile(int t);


protected:
    void init();
    
public slots:
	void loadChipset(QString chip);
	void setChipset(QPixmap chipset);

private:

    void setSelectedTile();

    QPixmap chipset;
    QGraphicsRectItem * itemRectSelected;

    QVector< QVector<int> > selectedTile;

    QRectF selection;

    
};

#endif // CHIPSETVIEW_H
