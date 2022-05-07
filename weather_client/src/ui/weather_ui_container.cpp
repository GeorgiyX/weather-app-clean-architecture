// weather_client
#include "ui/weather_ui_container.h"

// qt
#include <QUrl>
#include <QQmlContext>


WeatherUIContainer::WeatherUIContainer(QObject *parent) :
    QObject(parent),
    _engine(new QQmlApplicationEngine(this)),
    _weatherUi(new WeatherUI(this))
{
    _engine->rootContext()->setContextProperty("uiContainer", this);
    _engine->rootContext()->setContextProperty("weatherUI", _weatherUi);
    _engine->load(QUrl("qrc:/res/ui/main_ui.qml"));
}

IWeatherUILayer *WeatherUIContainer::getIWeatherUILayer()
{
    return _weatherUi;
}
