TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    screen.cpp
LIBS    += -lncurses

HEADERS += \
    screen.h
