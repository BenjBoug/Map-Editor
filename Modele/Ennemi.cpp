#include "Ennemi.h"

using namespace Model;
Ennemi::Ennemi()
{
	character = new Character();
}

Ennemi::~Ennemi()
{
}

void Ennemi::onKeySpace(IGame *)
{
    qDebug() << "OK";
}

void Ennemi::onKeyX(IGame *)
{
}

void Ennemi::onEvent(IGame *)
{
}

void Ennemi::manage(const IGame * game)
{
    character->manage(game);
}


void Ennemi::display(IGui * gui, ICamera * cam)
{
    character->display(gui,cam);
}
