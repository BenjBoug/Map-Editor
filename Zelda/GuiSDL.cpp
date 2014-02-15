#include "GuiSDL.h"

GuiSDL::GuiSDL()
{
}

GuiSDL::~GuiSDL()
{
    SDL_Quit();
}

void GuiSDL::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("The legend of Zelda", NULL);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    screen = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_initFramerate(&manager);
    SDL_setFramerate(&manager,30);
}

void GuiSDL::clearScreen()
{
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 107, 189, 107));
}

void GuiSDL::display()
{
    SDL_Flip(screen);
    SDL_framerateDelay(&manager);
}

void GuiSDL::blit(QString chipset, QPoint position, QRect rect)
{
    SDL_Rect sdl_position = QPointToSDLRect(position);
    SDL_Rect sdl_rect = QRectToSDLRect(rect);
    SDL_BlitSurface(factory.build(chipset), &sdl_rect, screen, &sdl_position);
}

SDL_Rect GuiSDL::QRectToSDLRect(QRect & r)
{
    SDL_Rect res;
    res.x=r.x();
    res.y=r.y();
    res.w=r.width();
    res.h=r.height();
    return res;
}

SDL_Rect GuiSDL::QPointToSDLRect(QPoint & r)
{
    SDL_Rect res;
    res.x=r.x();
    res.y=r.y();
    return res;
}
