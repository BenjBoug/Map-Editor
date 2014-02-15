#include "GameEngine.h"

GameEngine::GameEngine()
{
}

void GameEngine::init()
{
    QString nameMap = "map.k2x";
    actualMap = mapFactory.build(nameMap);
    cam = new Camera(this);
    heros = new Heros();
    input = new Input();
    managers.push_back(input);
    managers.push_back(actualMap);
    managers.push_back(heros);
    managers.push_back(cam);
}

void GameEngine::run()
{
    QVector<IManager*>::const_iterator it = managers.begin();
    for (;it!=managers.end();it++)
    {
        (*it)->manage(this);
    }
}
