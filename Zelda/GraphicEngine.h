#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include "GameEngine.h"
#include "GuiSDL.h"
#include "GuiOpenGL.h"

class GraphicEngine : public IEngine
{
public:
    GraphicEngine(const GameEngine * gameEngine);

    virtual void init();
    virtual void run();

private:
    const GameEngine * gameEngine;
    IGui * gui;
};

#endif // GRAPHICENGINE_H
