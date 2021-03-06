QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        analyzer.cpp \
        classifier.cpp \
        dsstring.cpp \
        dsvectortest.cpp \
        porter2_stemmer.cpp \
        tweet.cpp
        catch.hpp
        dsstring.cpp
        desvectortest.cpp
        tweet.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../../../Desktop/CSE2341-F19-Brian-Pattison/Sprint2/dsvector.h \
    ../../../Downloads/catch.hpp \
    catch.hpp \
    classifier.h \
    dsstring.h \
    dsvector.h \
    hash.h \
    porter2_stemmer.h \
    string_view.h \
    tweet.h
    dsstring.h
    tweet.h
