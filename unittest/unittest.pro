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

HEADERS += ../lab/configuration.h
SOURCES += ../lab/configuration.cpp

HEADERS += ../lab/log.h
SOURCES += ../lab/log.cpp

### add any other source or header files you may need
