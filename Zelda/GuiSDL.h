#ifndef GUISDL_H
#define GUISDL_H
#include "Constantes.h"
#include "IGui.h"
#include "SDL/SDL.h"
#include "SDL/SDL_framerate.h"
#include "SDLSurfaceFactory.h"

using namespace Model;

class GuiSDL : public IGui
{
public:
    GuiSDL();
    ~GuiSDL();
    virtual void init();
    virtual void clearScreen();
    virtual void display();
    virtual void blit(QString chipset,QPoint position, QRect rect);

protected:
    SDL_Rect QRectToSDLRect(QRect &);
    SDL_Rect QPointToSDLRect(QPoint &r);

private:
    FPSmanager manager;
    SDLSurfaceFactory factory;
    SDL_Surface *screen;
};


#endif // GUISDL_H
