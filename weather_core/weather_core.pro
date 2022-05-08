include($$PWD/include/weather_core.pri)

CONFIG -= qt

TEMPLATE = lib
DEFINES += CORE_LIBRARY

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    src/core.cpp \
    src/usecases/weather_usecase.cpp \
    src/utils/constants.cpp


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
