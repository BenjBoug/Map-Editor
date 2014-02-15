#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include "GameEngine.h"
#include "GuiSDL.h"
#include "GuiOpenGL.h"
#include "ImageFactory.h"
#include <Map.h>
#include <SDL/SDL.h>

class GraphicEngine : public IEngine
{
public:
    GraphicEngine(const GameEngine * gameEngine);

    virtual void init();
    virtual void run();

private:
    const GameEngine * gameEngine;
    ImageFactory factory;
    IGui * gui;
};

#endif // GRAPHICENGINE_H
