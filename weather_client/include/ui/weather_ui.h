#ifndef WEATHERUI_H
#define WEATHERUI_H

// weather_core
#include <weather_core/ui/ui_layers.h>

// qt
#include <QObject>

class WeatherUI : public QObject, public IWeatherUILayer
{
    Q_OBJECT
public:
    WeatherUI(QObject *parent);
    ~WeatherUI();
};

#endif // WEATHERUI_H
