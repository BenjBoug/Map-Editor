#include "OpenGLTextureFactory.h"

OpenGLTextureFactory::OpenGLTextureFactory()
{
}

GLuint OpenGLTextureFactory::build(QString name)
{
    if (!textureHash.contains(name))
    {
        GLuint identifiant_texture = loadTexture(name.toStdString().c_str());
        textureHash.insert(name,identifiant_texture);
    }

    return textureHash[name];
}
