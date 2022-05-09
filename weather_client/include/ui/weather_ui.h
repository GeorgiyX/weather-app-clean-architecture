#ifndef WEATHERUI_H
#define WEATHERUI_H

// weather_core
#include <weather_core/ui/ui_layers.h>

// weather_core
#include <weather_core/usecases/weather_usecase_interface.h>

// qt
#include <QObject>

// stl
#include <memory>

class WeatherUI : public QObject, public IWeatherUILayer
{
    Q_OBJECT
public:
    WeatherUI(QObject *parent);
    ~WeatherUI();

    /* Врапперы, для того что бы вызывать методы UC из QML */
    Q_INVOKABLE void onGetForecastClick(QString lon, QString lat);
    Q_INVOKABLE void onResetClick();

    void setWeatherUseCase(std::shared_ptr<IWeatherUseCaseUi> usecase);

private:
    std::shared_ptr<IWeatherUseCaseUi> _weatherUseCase;
};

#endif // WEATHERUI_H
