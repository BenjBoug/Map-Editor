#ifndef GUIOPENGL_H
#define GUIOPENGL_H

#include "IGui.h"
#include "Constantes.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "OpenGLTextureFactory.h"
#include "SDL/SDL_framerate.h"
using namespace Model;
class GuiOpenGL : public IGui
{
public:
    GuiOpenGL();

    virtual void init();
    virtual void clearScreen();
    virtual void display();
    virtual void blit(QString chipset,QPoint position, QRect rect);

private:
    OpenGLTextureFactory factory;
    FPSmanager manager;
};

#endif // GUIOPENGL_H
