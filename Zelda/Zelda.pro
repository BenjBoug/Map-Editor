TEMPLATE = app
CONFIG += console

SOURCES += main.cpp \
    GraphicEngine.cpp \
    Game.cpp \
    ImageFactory.cpp \
    GameEngine.cpp \
    GuiSDL.cpp \
    GuiOpenGL.cpp \
    SDLSurfaceFactory.cpp \
    sdlglutils.cpp \
    OpenGLTextureFactory.cpp

LIBS += -lSDL -lSDL_gfx -lGL -lGLU -lSDL_image

HEADERS += \
    GraphicEngine.h \
    Game.h \
    ImageFactory.h \
    GameEngine.h \
    GuiSDL.h \
    GuiOpenGL.h \
    SDLSurfaceFactory.h \
    sdlglutils.h \
    OpenGLTextureFactory.h


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Modele/release/ -lZelda_Model
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Modele/debug/ -lZelda_Model
else:unix: LIBS += -L$$OUT_PWD/../Modele/ -lZelda_Model

INCLUDEPATH += $$PWD/../Modele
DEPENDPATH += $$PWD/../Modele

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Modele/release/Zelda_Model.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Modele/debug/Zelda_Model.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Modele/libZelda_Model.a
