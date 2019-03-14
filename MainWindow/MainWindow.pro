#-------------------------------------------------
#
# Project created by QtCreator 2019-03-11T15:54:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindow
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    topthreeplayers.cpp \
    topthreegames.cpp \
    calculatedstatistics.cpp \
    ../History/player.cpp \
    ../History/game.cpp \
    ../History/gamehistory.cpp \
    newplayerscreendialog.cpp \
    existingplayerscreendialog.cpp \
    ../History/playergamehistory.cpp \
    ../RobotsGUI/robotsgui.cpp \
    ../WormGUI/wormgui.cpp \
    ../Engines/robots.cpp \
    ../Engines/worm.cpp \
    ../Engines/engine.cpp

HEADERS += \
        mainwindow.h \
    topthreeplayers.h \
    topthreegames.h \
    calculatedstatistics.h \
    ../History/player.h \
    ../History/game.h \
    newplayerscreendialog.h \
    existingplayerscreendialog.h \
    ../History/gamehistory.h \
    ../History/playergamehistory.h \
    ../RobotsGUI/robotsgui.h \
    ../WormGUI/wormgui.h \
    ../Engines/robots.h \
    ../Engines/worm.h \
    ../Engines/engine.h


FORMS += \
        mainwindow.ui \
    topthreeplayers.ui \
    topthreegames.ui \
    calculatedstatistics.ui \
    newplayerscreendialog.ui \
    existingplayerscreendialog.ui \
    #../RobotsGUI/robotsgui.ui \
    #../WormGUI/wormgui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
