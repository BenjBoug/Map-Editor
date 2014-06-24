#include "Map.h"

using namespace Model;
Map::Map() : QObject()
{

    size = QSize(NB_BLOCS_LARGEUR,NB_BLOCS_HAUTEUR);
    for(int i=0;i<size.width();i++)
    {
        for(int j=0;j<size.height();j++)
        {
			BlocMap * tmp = new BlocMap();
			connect(tmp,SIGNAL(blocModified()),this,SIGNAL(mapChanged()));
			map.push_back(tmp);
        }
    }
    name = "Untitled";
}

Map::Map(const Map &m) : QObject()
{
    name=m.name;
    QVector<BlocMap*>::const_iterator it;
    this->map.clear();
	for(it=m.map.begin();it!=m.map.end();it++)
    {
        BlocMap * tmp = new BlocMap();
		connect(tmp,SIGNAL(blocModified()),this,SIGNAL(mapChanged()));
        tmp->setLowLayer((*it)->getLowLayer());
        tmp->setHighLayer((*it)->getHighLayer());
        tmp->setCollisionLayer((*it)->getCollisionLayer());
        this->map.push_back(tmp);
    }
    events=m.events;
    size=m.size;
    chipset=m.chipset;
}

Map::~Map()
{
}

Map &Map::operator=(const Map &m)
{
    if (this!=&m)
    {
        name=m.name;
        chipset=m.chipset;
        this->map.clear();
        for(int i=0;i<m.getSize().width();i++)
        {
            for(int j=0;j<m.getSize().height();j++)
            {
                BlocMap * tmp = new BlocMap(*(m.getBloc(i,j)));
				connect(tmp,SIGNAL(blocModified()),this,SIGNAL(mapChanged()));
                this->map.push_back(tmp);
            }
        }

        events=m.events;
        size=m.size;
    }
    return *this;
}

bool Map::load(QString filename)
{
    QFile fileMap(filename);
    if (!fileMap.open(QFile::ReadOnly)) {
        return false;
    }
    QDataStream stream(&fileMap);
    stream >> this;
    fileMap.close();
    return true;
}


void Map::setName(QString & name)
{
    this->name = name;
	emit nameChanged(this->name);
}

void Map::loadChipset(QString & chipsetfile)
{
	this->chipset.load(chipsetfile);
	emit chipsetChanged(this->chipset);
}

QString Map::getName()
{
    return name;
}

QSize Map::getSize() const
{
    return size;
}
void Map::setSize(QSize& d)
{
    setSize(d.width(),d.height());
}
void Map::setSize(int w,int h)
{
    QVector<BlocMap*> newMap;
    for( int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            if (i<size.width() && j<size.height())
                newMap.push_back(map[convert2Dto1D(i,j)]);
            else
                newMap.push_back(new BlocMap());
        }
    }
    map=newMap;
    size.setHeight(h);
    size.setWidth(w);
	emit sizeChanged(size);
}

void Map::manage(const IGame *game)
{
    QVector<IEvent*>::iterator it = events.begin();
    for(;it!=events.end();it++)
        (*it)->manage(game);
}

void Map::display(IGui *gui, ICamera *cam)
{
    QPoint position;
    QRect pos_objet;
    pos_objet.setWidth(BLOCSIZE);
    pos_objet.setHeight(BLOCSIZE);

    int x = cam->getCoordBox().x(), y=cam->getCoordBox().y();

    int centrageX = (NB_BLOCS_LARGEUR - (cam->getCoordBox().width()/BLOCSIZE))/2;
    int centrageY = (NB_BLOCS_HAUTEUR - (cam->getCoordBox().height()/BLOCSIZE))/2;


    for (int j = (y/BLOCSIZE); j < (cam->getCoordBox().height()/BLOCSIZE)+(y/BLOCSIZE)+1; j++)
        for (int i = (x/BLOCSIZE); i < (cam->getCoordBox().width()/BLOCSIZE)+(x/BLOCSIZE)+1; i++)
        {
            if (i<size.width() && j<size.height())
            {
                int couche1 = map[convert2Dto1D(i,j)]->getLowLayer();
                int couche2 = map[convert2Dto1D(i,j)]->getHighLayer();
                if (couche1!=0)
                {
                    position.setX((i*BLOCSIZE-x)+(centrageX*BLOCSIZE));
                    position.setY((j*BLOCSIZE-y)+(centrageY*BLOCSIZE));
                    pos_objet.moveLeft((couche1%30)*BLOCSIZE);
                    pos_objet.moveTop((couche1/30)*BLOCSIZE);
                    gui->draw(chipset,position,pos_objet);
                }

                if (couche2!=0)
                {
                    position.setX((i*BLOCSIZE-x)+(centrageX*BLOCSIZE));
                    position.setY((j*BLOCSIZE-y)+(centrageY*BLOCSIZE));
                    pos_objet.moveLeft((couche2%30)*BLOCSIZE);
                    pos_objet.moveTop((couche2/30)*BLOCSIZE);
                    gui->draw(chipset,position,pos_objet);
                }
            }
        }

}

BlocMap *Map::getBloc(QPoint& coord) const
{
    return map[convert2Dto1D(coord.x(),coord.y())];
}

BlocMap * Map::getBloc(int i,int j) const
{
	return map[convert2Dto1D(i,j)];
}

QRect Map::getRect() const
{
	return QRect(0,0,size.width()*BLOCSIZE,size.height()*BLOCSIZE);
}

int Map::convert2Dto1D(int i, int j) const
{
    return i*size.height() + j;
}


QPixmap Map::getChipset() const
{
	return chipset;
}

void Map::setChipset(QPixmap chipset)
{
	this->chipset=chipset;
	emit chipsetChanged(this->chipset);
}

QDataStream &Model::operator <<(QDataStream &out, const Map *v)
{
    out << v->name << v->chipset << v->size;

    QVector<BlocMap*>::const_iterator it = v->map.begin();
    for (;it!=v->map.end();it++)
    {
        out << *it;
    }

    out << v->events;

    return out;
}

QDataStream &Model::operator >>(QDataStream &in, Map *v)
{
    v->map.clear();
    in >> v->name;
	in >> v->chipset;
	in >> v->size;

    for(int i=0;i<v->size.width();i++)
    {
        for(int j=0;j<v->size.height();j++)
        {
            BlocMap * tmp = new BlocMap();
            v->connect(tmp,SIGNAL(blocModified()),v,SIGNAL(mapChanged()));
            in >> tmp;
            v->map.push_back(tmp);
        }
    }

    in >> v->events;

    return in;
}
