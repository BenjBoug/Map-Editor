#ifndef SDL2TEXTUREFACTORY_H
#define SDL2TEXTUREFACTORY_H

#include "SDL2/SDL.h"
#include <QString>
#include <QHash>

class SDL2TextureFactory
{
public:
    SDL2TextureFactory();
    SDL_Surface * build(QString name);

private:
    QHash<QString,SDL_Surface*> surfaceHash;
};

#endif // SDL2TEXTUREFACTORY_H
