#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H

#include "Constantes.h"
#include <SDL/SDL.h>
#include <QString>
#include <QHash>

class ImageFactory
{
public:
    ImageFactory();

    SDL_Surface * build(QString name);

private:
    QHash<QString,SDL_Surface*> * surfaceHash;
};

#endif // IMAGEFACTORY_H
