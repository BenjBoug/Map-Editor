#include "Animation.h"
using namespace Model;

Animation::Animation(QString n, Direction * d)
{
    direction = d;
    position=0;
    nomFichier = n;
    tempsPrecedent=0;
    frameActuel = frames[*direction][position];
    state=1;
    timer.start();
}

Animation::~Animation()
{

}


void Animation::manage(const IGame *)
{
    if (timer.elapsed() - tempsPrecedent > frameActuel->getDelay())
    {
        frameActuel = frames[*direction][position];
        position++;

        if (position>=frames[*direction].size())
        {
            position=0;
            state=0;
        }
        else
        state=1;

        tempsPrecedent = timer.elapsed();
    }
}

void Animation::prepare()
{
    state=1;
    position=0;
}

void Animation::play()
{
}

void Animation::stop()
{
}

int Animation::getDelayTotal()
{
    int somme=0;
    for(int i=0;i<frames[*direction].size();i++)
    {
        somme+=frames[*direction][position]->getDelay();
    }
    return somme;
}

void Animation::display(IGui * gui, ICamera * cam)
{
    QPoint positionS;
    QRect positionRel;
    positionS.setX(cam->getCollisionBox().x()-frameActuel->getDecalage().x());
    positionS.setY(cam->getCollisionBox().y()-frameActuel->getDecalage().y());

    gui->draw(nomCharset,positionS,frameActuel->getCoordBox());
}
