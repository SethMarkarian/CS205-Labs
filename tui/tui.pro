TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    screen.cpp \
    wormstui.cpp \
    robotstui.cpp
LIBS    += -lncurses

HEADERS += \
    screen.h \
    wormstui.h \
    robotstui.h
