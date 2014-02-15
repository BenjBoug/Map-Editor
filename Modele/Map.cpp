#include "Map.h"

using namespace Model;
Map::Map()
{
}

Map::Map(QString name)
{
    _name = name;
}

Map::~Map()
{
}

void Map::load()
{
    QFile file(_name);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> this;
    file.close();
}

void Map::setNameMap(QString & n)
{
    _name = n;
}

void Map::setNameChipset(QString & n)
{
    _chipset = n;
}

QString Map::getNameMap()
{
    return _name;
}

QSize Map::getDim() const
{
    return dim;
}
void Map::setDim(QSize& d)
{
    dim = d;
}
void Map::setDim(int l,int h)
{
    dim.setHeight(h);
    dim.setWidth(l);
}

void Map::manage(const IGame *game)
{
    /*QVector<IEvent*>::iterator it = events.begin();
    for(;it!=events.end();it++)
        (*it)->manage(game);*/
}

void Map::display(IGui *gui, ICamera *cam)
{
    QPoint position;
    QRect pos_objet;
    pos_objet.setWidth(TAILLE_BLOC);
    pos_objet.setHeight(TAILLE_BLOC);

    int x = cam->getCoordBox().x(), y=cam->getCoordBox().y();

    int centrageX = (NB_BLOCS_LARGEUR - (cam->getCoordBox().width()/TAILLE_BLOC))/2;
    int centrageY = (NB_BLOCS_HAUTEUR - (cam->getCoordBox().height()/TAILLE_BLOC))/2;


    for (int j = (y/TAILLE_BLOC); j < (cam->getCoordBox().height()/TAILLE_BLOC)+(y/TAILLE_BLOC)+1; j++)
        for (int i = (x/TAILLE_BLOC); i < (cam->getCoordBox().width()/TAILLE_BLOC)+(x/TAILLE_BLOC)+1; i++)
        {
            try
            {
                int couche1 = _map[convert2Dto1D(i,j)]->getCouche1();
                int couche2 = _map[convert2Dto1D(i,j)]->getCouche2();
                if (couche1!=0)
                {
                    position.setX((i*TAILLE_BLOC-x)+(centrageX*TAILLE_BLOC));
                    position.setY((j*TAILLE_BLOC-y)+(centrageY*TAILLE_BLOC));
                    pos_objet.moveLeft((couche1%30)*TAILLE_BLOC);
                    pos_objet.moveTop((couche1/30)*TAILLE_BLOC);
                    gui->blit(_chipset,position,pos_objet);
                }

                if (couche2!=0)
                {
                    position.setX((i*TAILLE_BLOC-x)+(centrageX*TAILLE_BLOC));
                    position.setY((j*TAILLE_BLOC-y)+(centrageY*TAILLE_BLOC));
                    pos_objet.moveLeft((couche2%30)*TAILLE_BLOC);
                    pos_objet.moveTop((couche2/30)*TAILLE_BLOC);
                    gui->blit(_chipset,position,pos_objet);
                }
            }
            catch(std::exception const& e)
            {
                std::cout << "ERREUR : "<< e.what() << std::endl;
            }
        }

}

const BlocMap *Map::getBloc(QPoint& coord) const
{
    return _map[convert2Dto1D(coord.x(),coord.y())];
}

const BlocMap * Map::getBloc(int x,int y) const
{
    return _map[convert2Dto1D(x,y)];
}

int Map::convert2Dto1D(int i, int j) const
{
    return i*dim.height() + j;
}

QString Map::getChipset() const
{
    return _chipset;
}

QDataStream &Model::operator <<(QDataStream &out, const Map *v)
{
    out << v->_name << v->_chipset << v->dim;

    QVector<BlocMap*>::const_iterator it = v->_map.begin();
    for (;it!=v->_map.end();it++)
    {
        out << *it;
    }

    return out;
}

QDataStream &Model::operator >>(QDataStream &in, Map *v)
{
    in >> v->_name;
    qDebug() << "name:" << v->_name;
    in >> v->_chipset;
    qDebug() << "chipset" << v->_chipset;
    in >> v->dim;

    for(int i=0;i<v->dim.width();i++)
    {
        for(int j=0;j<v->dim.height();j++)
        {
            BlocMap * tmp = new BlocMap();
            in >> tmp;
            v->_map.push_back(tmp);
        }
    }
    return in;
}
