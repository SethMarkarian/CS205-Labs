TEMPLATE = subdirs

SUBDIRS += \
    lab \
    unittest \
    Engines \
    engine_tests \
    #ncurses_example \
    #tui \
    TinyGame

HEADERS += \
    robotstui.h

SOURCES += \
    robotstui.cpp
