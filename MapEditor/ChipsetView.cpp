#include "ChipsetView.h"

ChipsetView::ChipsetView(QWidget *parent):
    QSFMLCanvas(parent)
{
    this->move(QPoint(0,0));
}

ChipsetView::ChipsetView(QString chip, QWidget *parent) :
    QSFMLCanvas(parent)
{
    this->move(QPoint(0,0));
    loadChipset(chip);
    inSelect = false;

    selectedTile.resize(1);
    selectedTile[0].resize(1);
    selectedTile[0][0] = 0;
    selection.setX(0);
    selection.setY(0);
    selection.setWidth(BLOCSIZE);
    selection.setHeight(BLOCSIZE);
}

void ChipsetView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (!inSelect)
        {
            selection.setLeft((event->x()/BLOCSIZE)*BLOCSIZE);
            selection.setTop((event->y()/BLOCSIZE)*BLOCSIZE);
            selection.setWidth(BLOCSIZE);
            selection.setHeight(BLOCSIZE);
            for (int i=0; i<selectedTile.size(); i++)
            {
                selectedTile[i].clear();
            }
            selectedTile.clear();
            inSelect = true;
        }
    }
}

void ChipsetView::mouseMoveEvent(QMouseEvent *event)
{
    if (inSelect)
    {
        selection.setRight((event->x()/BLOCSIZE)*BLOCSIZE + BLOCSIZE);
        selection.setBottom((event->y()/BLOCSIZE)*BLOCSIZE + BLOCSIZE);
    }
}

void ChipsetView::mouseReleaseEvent(QMouseEvent * event)
{
    Q_UNUSED(event);
    if (inSelect)
    {

        for (int i=0; i<selection.height()/BLOCSIZE; i++)
        {
            selectedTile.push_back( QVector<int>() );
            for (int j=0; j<selection.width()/BLOCSIZE; j++)
            {
                selectedTile[i].push_back(((selection.x()/BLOCSIZE)+j) + ((selection.y()/BLOCSIZE)+i)*(chipset.GetWidth()/BLOCSIZE));
            }
        }
    }

    inSelect = false;
}

void ChipsetView::drawSelection()
{
    sf::Shape Rect = sf::Shape::Rectangle(selection.left(), selection.top(),selection.right(), selection.bottom(), sf::Color(0, 0, 0,0),2,sf::Color(0, 0, 0));
    Draw(Rect);
}

void ChipsetView::loadChipset(QString & chip)
{
    chipset.LoadFromFile(chip.toStdString().c_str());
    sprite.SetImage(chipset);
    this->resize(chipset.GetWidth(),chipset.GetHeight());
}

void ChipsetView::OnInit()
{
}

void ChipsetView::OnUpdate()
{
    // Clear screen
    Clear(sf::Color(0, 0, 180));
    // Draw
    Draw(sprite);
    drawSelection();

    SetFramerateLimit(40);
}
