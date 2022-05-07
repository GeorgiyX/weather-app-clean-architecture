include($$PWD/../weather_core/include/weather_core.pri)

QT += qml quick
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
        src/applicationcore.cpp \
        src/main.cpp \
        src/ui/weather_ui.cpp \
        src/ui/weather_ui_container.cpp

HEADERS += \
    include/applicationcore.h \
    include/dependencies/network.h \
    include/ui/weather_ui.h \
    include/ui/weather_ui_container.h

INCLUDEPATH += \
    include

QT += widgets

FORMS +=

DISTFILES += \
    res/ui/main_ui.qml
