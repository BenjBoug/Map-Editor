#ifndef INPUT_H
#define INPUT_H

#include "IInput.h"
#include "SDL/SDL.h"
namespace Model
{
class Input : public IInput
{
public:
    Input();

    virtual bool onKeyXPress();
    virtual bool onKeySpacePress();
    virtual bool onKeyPPress();
    virtual bool onKeyEscapePress();
    virtual bool onKeyUpPress();
    virtual bool onKeyDownPress();
    virtual bool onKeyLeftPress();
    virtual bool onKeyRightPress();
    virtual void manage(const IGame *);

private:
    bool m_key[SDLK_LAST];
    SDL_Event event;
};
}

#endif // INPUT_H
