#include "GraphicEngine.h"

GraphicEngine::GraphicEngine(const GameEngine *gameEngine)
{
    this->gameEngine = gameEngine;
    gui = new GuiSDL();
}

void GraphicEngine::init()
{
    gui->init();
}

void GraphicEngine::run()
{
    gui->clearScreen();
    gameEngine->getActualMap()->display(gui,gameEngine->getCamera());
    gui->display();
}
