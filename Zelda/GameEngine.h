#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "IGame.h"
#include "IEngine.h"
#include "MapFactory.h"
#include "Camera.h"
#include "Heros.h"
#include <QDir>
#include "Input.h"

using namespace Model;

class GameEngine : public IEngine, public IGame
{
public:
    GameEngine();

    void init();
    void run();

    virtual ICharacter * getHeros() const
    {
        return heros;
    }
    virtual IMap * getActualMap() const
    {
        return actualMap;
    }
    virtual IInput * getInput() const
    {
        return input;
    }
    Camera * getCamera() const
    {
        return cam;
    }

private:
    MapFactory mapFactory;
    Map * actualMap;
    Heros * heros;
    Camera * cam;
    Input* input;
    QVector<IManager*> managers;
};

#endif // GAMEENGINE_H
