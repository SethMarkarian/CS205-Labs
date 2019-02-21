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
    robotstui.cpp

LIBS    += -lncurses

HEADERS += \
    screen.h \
    ../Engines/engine.h \
    ../Engines/worm.h \
    ../Engines/robots.h \
    wormstui.h \
    robotstui.h

