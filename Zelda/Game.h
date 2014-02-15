#ifndef GAME_H
#define GAME_H

#include "GraphicEngine.h"

class Game : IEngine
{
public:
    Game();
    virtual void init();
    virtual void run();

    inline bool isRunning()
    {
        return running;
    }

private:
    bool running;
    QVector<IEngine*> engines;
};

#endif // GAME_H
