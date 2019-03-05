TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    screen.cpp \
    ../Engines/engine.cpp \
    ../Engines/worm.cpp \
    ../Engines/robots.cpp \
    wormstui.cpp \
    robotstui.cpp \
    altscreen.cpp \
    mainscreen.cpp \
    ../History/game.cpp \
    ../History/gamehistory.cpp \
    ../History/player.cpp \
    ../History/playergamehistory.cpp

LIBS    += -lncurses -lform

HEADERS += \
    screen.h \
    ../Engines/engine.h \
    ../Engines/worm.h \
    ../Engines/robots.h \
    wormstui.h \
    robotstui.h \
    altscreen.h \
    mainscreen.h \
    ../History/game.h \
    ../History/gamehistory.h \
    ../History/player.h \
    ../History/playergamehistory.h
