#ifndef GUISFML_H
#define GUISFML_H

#include "IGui.h"
#include <SFML/Graphics.hpp>
#include "Constantes.h"
#include "SFMLSpriteFactory.h"

using namespace sf;
using namespace Model;

class GuiSFML : public IGui
{
public:
    GuiSFML();

    virtual void init();
    virtual void clearScreen();
    virtual void display();
    virtual void draw(QString chipset,QPoint position, QRect rect);
    virtual void quit();

private:
    RenderWindow *app;
    SFMLSpriteFactory factory;
    Sprite mySprite;
};

#endif // GUISFML_H
