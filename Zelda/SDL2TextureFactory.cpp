#include "SDL2TextureFactory.h"

SDL2TextureFactory::SDL2TextureFactory()
{
}

SDL_Surface *SDL2TextureFactory::build(QString name)
{
    if (!surfaceHash.contains(name))
    {
        SDL_Surface * m_chipset;
        m_chipset= SDL_LoadBMP(name.toStdString().c_str());
        //SDL_SetColorKey(m_chipset, SDL_SRCCOLORKEY, SDL_MapRGB(m_chipset->format, 255, 103, 139));
        surfaceHash.insert(name,m_chipset);
    }

    return surfaceHash[name];
}
