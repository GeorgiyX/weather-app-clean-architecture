include($$PWD/../weather_core/include/weather_core.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
        src/applicationcore.cpp \
        src/main.cpp \
        src/ui/weatherui.cpp

HEADERS += \
    include/applicationcore.h \
    include/dependencies/network.h \
    include/ui/weatherui.h

INCLUDEPATH += \
    include

QT += widgets

FORMS += \
    ui/weatherui.ui
