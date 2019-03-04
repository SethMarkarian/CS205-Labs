TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

# if you have pthread errors, comment/uncomment the next line
LIBS += -pthread

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                   \
                ../gtest/googletest                        \
                ../gtest/googletest/include                \
                ../gtest/googletest/include/gtest

HEADERS += ../History/game.h
SOURCES += ../History/game.cpp

HEADERS += ../History/gamehistory.h
SOURCES += ../History/gamehistory.cpp

HEADERS += ../History/player.h
SOURCES += ../History/player.cpp

HEADERS += ../History/playergamehistory.h
SOURCES += ../History/playergamehistory.cpp
### add any other source or header files you may need
