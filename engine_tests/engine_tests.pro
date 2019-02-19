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


HEADERS += ../Engines/engine.h
SOURCES += ../Engines/engine.cpp

HEADERS += ../Engines/robots.h
SOURCES += ../Engines/robots.cpp

HEADERS += ../Engines/worm.h
SOURCES += ../Engines/worm.cpp

### add any other source or header files you may need
