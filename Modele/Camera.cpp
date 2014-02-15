#include "Camera.h"

using namespace Model;
Camera::Camera(IGame *game)
{
    this->game = game;
    coord.setLeft(0);
    coord.setTop(0);
    coord.setWidth(LARGEUR_FENETRE);
    coord.setHeight(HAUTEUR_FENETRE);
}

Camera::~Camera()
{
    //dtor
}


bool Camera::overflowMap()
{
    bool res = false;
    if (coord.x() <= -100)
        res=true;
    if (coord.y() <= -100)
        res=true;
    if (coord.y()+coord.height() > game->getActualMap()->getDim().height()*TAILLE_BLOC)
        res = true;
    if (coord.x()+coord.width() > game->getActualMap()->getDim().width()*TAILLE_BLOC)
        res = true;

    return res;
}
void Camera::replaceCamera()
{
    if (coord.x() < 0)
        coord.moveLeft(0);

    if (coord.y() < 0)
        coord.moveTop(0);

    if (coord.y()+coord.height() > game->getActualMap()->getDim().height()*TAILLE_BLOC)
        coord.moveTop((game->getActualMap()->getDim().height()*TAILLE_BLOC) - coord.height());

    if (coord.x()+coord.width() > game->getActualMap()->getDim().width()*TAILLE_BLOC)
        coord.moveLeft((game->getActualMap()->getDim().width()*TAILLE_BLOC) - coord.width());

}

void Camera::centerCameraOnHeros()
{
    coord.moveTo(game->getHeros()->getCoordBox().x()-MOITIER_ECRAN_X,game->getHeros()->getCoordBox().y()-MOITIER_ECRAN_Y);
}

void Camera::manage(const IGame *)
{
    centerCameraOnHeros();
    replaceCamera();
}

bool Camera::isInTheField(Object* o)
{
    return o->collision(this);
}

