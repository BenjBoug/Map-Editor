#ifndef CHIPSETVIEW_H
#define CHIPSETVIEW_H

#include "QSFMLCanvas.hpp"
#include <QVector>
#include <QImage>
#include <Constantes.h>
#include <QMouseEvent>
#include <QRect>
#include <QWidget>
#include <QDebug>

class ChipsetView : public QSFMLCanvas
{
    Q_OBJECT
public:
    explicit ChipsetView(QWidget *parent = 0);
    explicit ChipsetView(QString chip, QWidget *parent = 0);

    void mousePressEvent( QMouseEvent * event );
    void mouseMoveEvent ( QMouseEvent * event );
    void mouseReleaseEvent ( QMouseEvent * event );

protected:
    void drawSelection();
    
signals:
    
public slots:
    void loadChipset(QString &chip);

private:
    void OnInit();
    void OnUpdate();

    sf::Image  chipset;
    sf::Sprite sprite;

    QVector< QVector<int> > selectedTile;

    QRect selection;

    bool inSelect;
    
};

#endif // CHIPSETVIEW_H
