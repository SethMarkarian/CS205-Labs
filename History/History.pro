TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    playergamehistory.cpp \
    player.cpp \
    game.cpp \
    gamehistory.cpp \
    dbtable.cpp \
    dbtableex.cpp \
    dbtool.cpp \
    gamedbt.cpp \
    gamehistorydbt.cpp \
    playerdbt.cpp \
    playergamehistorydbt.cpp

LIBS    += -lsqlite3

HEADERS += \
    playergamehistory.h \
    player.h \
    game.h \
    gamehistory.h \
    dbtable.h \
    dbtableex.h \
    dbtool.h \
    gamedbt.h \
    gamehistorydbt.h \
    playerdbt.h \
    playergamehistorydbt.h
