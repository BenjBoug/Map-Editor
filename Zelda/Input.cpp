#include "Input.h"

using namespace Model;
Input::Input()
{
    for (int i=0; i<SDLK_LAST; i++)
        m_key[i]=0;
}

bool Input::onKeyXPress()
{
    return m_key[SDLK_x];
}

bool Input::onKeySpacePress()
{
    return m_key[SDLK_SPACE];
}

bool Input::onKeyPPress()
{
    return m_key[SDLK_p];
}

bool Input::onKeyEscapePress()
{
    return m_key[SDLK_ESCAPE];
}

bool Input::onKeyUpPress()
{
    return m_key[SDLK_UP];
}

bool Input::onKeyDownPress()
{
    return m_key[SDLK_DOWN];
}

bool Input::onKeyLeftPress()
{
    return m_key[SDLK_LEFT];
}

bool Input::onKeyRightPress()
{
    return m_key[SDLK_RIGHT];
}

void Input::manage(const IGame *)
{
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_KEYDOWN:
        m_key[event.key.keysym.sym]=true;
        break;
    case SDL_MOUSEMOTION:
        break;
    case SDL_KEYUP:
        m_key[event.key.keysym.sym]=false;
        break;

    }
}

bool Input::onQuit()
{
    return m_key[SDL_QUIT];
}
