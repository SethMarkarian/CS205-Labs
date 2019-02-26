TEMPLATE = subdirs

SUBDIRS += \
    lab \
    unittest \
    Engines \
    engine_tests \
    #ncurses_example \
    #tui \
    TinyGame    \
    TextFinder

HEADERS += \
    robotstui.h

SOURCES += \
    robotstui.cpp
