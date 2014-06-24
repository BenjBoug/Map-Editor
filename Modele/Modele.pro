#-------------------------------------------------
#
# Project created by QtCreator 2014-01-20T14:32:24
#
#-------------------------------------------------

QT += gui
QT += core

TARGET = Zelda_Model
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    Blocmap.cpp \
    Object.cpp \
    Map.cpp \
    Character.cpp \
    Camera.cpp \
    MapFactory.cpp \
    Heros.cpp \
    Ennemi.cpp \
    IEvent.cpp \
    Animation.cpp \
    Frame.cpp

HEADERS += \
    Blocmap.h \
    Constantes.h \
    Object.h \
    Map.h \
    Character.h \
    Camera.h \
    MapFactory.h \
    Heros.h \
    IDisplayable.h \
    IEngine.h \
    IManager.h \
    IMoveable.h \
    Ennemi.h \
    IEvent.h \
    IGame.h \
    ICharacter.h \
    ICamera.h \
    IMap.h \
    ISerializable.h \
    IGui.h \
    IInput.h \
    Animation.h \
    Frame.h \
    IAnimation.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
