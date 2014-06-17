#-------------------------------------------------
#
# Project created by QtCreator 2014-02-16T13:58:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapEditor
TEMPLATE = app

SOURCES += main.cpp\
        MainWindow.cpp \
    ChipsetView.cpp \
	MapView.cpp \
	GroupeCheckBox.cpp \
	QGraphicsTileItem.cpp \
    IMouseMove.cpp \
	UndoSingleton.cpp \
    MdiChild.cpp \
    TileFactory.cpp \
    DialogChangeDimension.cpp \
\
	layer/DisplayLowerLayerStrategy.cpp \
	layer/DisplayHigherLayerStrategy.cpp \
	layer/DisplayVisuaLayerStrategy.cpp \
	layer/DisplayCollisionLayerStrategy.cpp \
	layer/GridLayerStratgey.cpp \
	layer/LayerStrategy.cpp \
\
	painter/BrushStrategy.cpp \
	painter/PaintPotStratgey.cpp \
	painter/PipetteStrategy.cpp \
	painter/PaintStrategy.cpp \
	painter/RectangleStrategy.cpp \
\
	command/CollideCommand.cpp \
	command/ClearMapCommand.cpp \
	command/ChangeDimensionCommand.cpp \
	command/ChangeChipsetCommand.cpp \
	command/BlitCommand.cpp \
	command/EraseCommand.cpp \
	command/GroupCommand.cpp

HEADERS  += MainWindow.h \
    ChipsetView.h \
	MapView.h \
	IStrategy.h \
	GroupeCheckBox.h \
	QGraphicsTileItem.h \
    IMouseMove.h \
	UndoSingleton.h \
    MdiChild.h \
    TileFactory.h \
    DialogChangeDimension.h \
\
	layer/DisplayLowerLayerStrategy.h \
	layer/DisplayHigherLayerStrategy.h \
	layer/DisplayVisuaLayerStrategy.h \
	layer/DisplayCollisionLayerStrategy.h \
	layer/GridLayerStratgey.h \
	layer/LayerStrategy.h \
\
	painter/PipetteStrategy.h \
	painter/BrushStrategy.h \
	painter/PaintPotStratgey.h \
	painter/PaintStrategy.h \
	painter/RectangleStrategy.h \
\
	command/ICommand.h \
	command/BlitCommand.h \
	command/EraseCommand.h \
	command/CollideCommand.h \
	command/ClearMapCommand.h \
	command/ChangeDimensionCommand.h \
	command/ChangeChipsetCommand.h \
	command/GroupCommand.h

FORMS    += MainWindow.ui \
    DialogChangeDimension.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Modele/release/ -lZelda_Model
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Modele/debug/ -lZelda_Model
else:unix: LIBS += -L$$OUT_PWD/../Modele/ -lZelda_Model

INCLUDEPATH += $$PWD/../Modele
DEPENDPATH += $$PWD/../Modele

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Modele/release/Zelda_Model.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Modele/debug/Zelda_Model.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Modele/libZelda_Model.a

RESOURCES += \
    icons.qrc \
    maps.qrc \
    chipsets.qrc
