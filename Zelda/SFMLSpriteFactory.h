#ifndef SFMLSPRITEFACTORY_H
#define SFMLSPRITEFACTORY_H

#include <SFML/Graphics.hpp>
#include <QString>
#include <QHash>
#include <QDebug>
using namespace sf;

class SFMLSpriteFactory
{
public:
    SFMLSpriteFactory();

    Image build(QString name);

private:
    QHash<QString,Image> spriteHash;
};

#endif // SFMLSPRITEFACTORY_H
