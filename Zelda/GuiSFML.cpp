#include "GuiSFML.h"

GuiSFML::GuiSFML()
{
}

void GuiSFML::init()
{
    app = new RenderWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "The Legend of Zelda", Style::Close | Style::Titlebar);
}

void GuiSFML::clearScreen()
{
    app->Clear(sf::Color(107, 189, 107));
}

void GuiSFML::display()
{
    app->Display();
    app->SetFramerateLimit(40);
}

void GuiSFML::draw(QString chipset, QPoint position, QRect rect)
{
    Image img = factory.build(chipset);
    mySprite.SetImage(img);
    mySprite.SetSubRect(sf::Rect<int> (rect.left(),rect.top(),rect.right(),rect.bottom()));
    mySprite.SetPosition((float)position.x()-0.5,(float)position.y()-0.5);
    app->Draw(mySprite);
}

void GuiSFML::quit()
{
    app->Close();
}
