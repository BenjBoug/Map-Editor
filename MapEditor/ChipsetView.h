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

class ChipsetView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ChipsetView();
    explicit ChipsetView(QString chip);

    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

protected:
    void init();
    
signals:
    void newSelection(QVector<QVector<int> >);
    
public slots:
    void loadChipset(QString chip);

private:
    QPixmap chipset;
    QGraphicsRectItem * itemRectSelected;

    QVector< QVector<int> > selectedTile;

    QRectF selection;

    
};

#endif // CHIPSETVIEW_H
