#include "Game.h"

Game::Game()
{
}

void Game::init()
{
    running = true;

    GameEngine * gameEngine = new GameEngine();
    GraphicEngine * graphEngine = new GraphicEngine(gameEngine);
    engines.push_back(gameEngine);
    engines.push_back(graphEngine);

    QVector<IEngine*>::const_iterator it = engines.begin();
    for (;it!=engines.end();it++)
    {
        (*it)->init();
    }

}

void Game::run()
{
    while (running)
    {
        QVector<IEngine*>::const_iterator it = engines.begin();
        for (;it!=engines.end();it++)
        {
            (*it)->run();
        }
    }
}
