TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        adjlist.cpp \
        destinationcity.cpp \
        dsstring.cpp \
        flight.cpp \
        flightplanner.cpp \
        main.cpp \
        origincity.cpp \
        path.cpp \
        tester.cpp

HEADERS += \
    adjlist.h \
    catch.hpp \
    destinationcity.h \
    dsstack.h \
    dsstring.h \
    dsvector.h \
    flight.h \
    flightplanner.h \
    linkedlist.h \
    origincity.h \
    path.h
