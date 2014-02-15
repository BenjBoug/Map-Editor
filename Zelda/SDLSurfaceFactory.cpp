#include "SDLSurfaceFactory.h"

using namespace Model;
SDLSurfaceFactory::SDLSurfaceFactory()
{
}

SDL_Surface *SDLSurfaceFactory::build(QString name)
{
    if (!surfaceHash.contains(name))
    {
        SDL_Surface * m_chipset;
        m_chipset= SDL_LoadBMP(name.toStdString().c_str());
        SDL_SetColorKey(m_chipset, SDL_SRCCOLORKEY, SDL_MapRGB(m_chipset->format, 255, 103, 139));
        m_chipset=SDL_DisplayFormat(m_chipset);
        surfaceHash.insert(name,m_chipset);
    }

    return surfaceHash[name];
}
