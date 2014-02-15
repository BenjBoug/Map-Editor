#ifndef OPENGLTEXTUREFACTORY_H
#define OPENGLTEXTUREFACTORY_H

#include <QHash>
#include <QString>
#include <GL/glu.h>
#include "sdlglutils.h"

class OpenGLTextureFactory
{
public:
    OpenGLTextureFactory();

    GLuint build(QString name);

private:
    QHash<QString,GLuint> textureHash;
};

#endif // OOENGLTEXTUREFACTORY_H
