include($$PWD/../weather_core/include/weather_core.pri)

QT += qml quick network
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
        src/dependencies/request_responce.cpp \
        src/dependencies/network.cpp \
        src/applicationcore.cpp \
        src/main.cpp \
        src/ui/weather_ui.cpp \
        src/ui/weather_ui_container.cpp

HEADERS += \
    include/dependencies/json.h \
    include/dependencies/request_responce.h \
    include/dependencies/network.h \
    include/applicationcore.h \
    include/ui/weather_ui.h \
    include/ui/weather_ui_container.h

INCLUDEPATH += \
    include \
    src


QT += widgets

FORMS +=

DISTFILES += \
    res/ui/main_ui.qml
