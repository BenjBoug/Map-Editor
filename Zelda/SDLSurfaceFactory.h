#ifndef SDLSURFACEFACTORY_H
#define SDLSURFACEFACTORY_H

#include <QString>
#include <QHash>
#include "SDL/SDL.h"
#include <QDebug>

namespace Model
{
class SDLSurfaceFactory
{
public:
    SDLSurfaceFactory();

    SDL_Surface * build(QString name);

private:
    QHash<QString,SDL_Surface*> surfaceHash;
};
}

#endif // SDLSURFACEFACTORY_H
