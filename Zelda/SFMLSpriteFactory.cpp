#include "SFMLSpriteFactory.h"

SFMLSpriteFactory::SFMLSpriteFactory()
{
}

Image SFMLSpriteFactory::build(QString name)
{
    if (!spriteHash.contains(name))
    {
        Image image;
        if (image.LoadFromFile(name.toStdString().c_str()))
        {
            image.CreateMaskFromColor(sf::Color(255, 103, 139));
            spriteHash.insert(name,image);
        }
        else
        {
            qDebug() << "bug image";
        }
    }
    return spriteHash[name];
}
