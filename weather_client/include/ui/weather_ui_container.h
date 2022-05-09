#ifndef WEATHERUI_CONTAINER_H
#define WEATHERUI_CONTAINER_H

// weather_client
#include "ui/weather_ui.h"

// weather_core
#include <weather_core/usecases/weather_usecase_interface.h>

// qt
#include <QQmlApplicationEngine>
#include <QObject>

class WeatherUIContainer : public QObject
{
    Q_OBJECT

public:
    explicit WeatherUIContainer(QObject *parent = nullptr);
    ~WeatherUIContainer();

    /**
     * @brief Возвращает не умный указатель
     * т.к. в qt за уничтожение объектов отвечает родительский
     * QObject
     */
    IWeatherUILayer *getIWeatherUILayer();

    void setWeatherUseCase(std::shared_ptr<IWeatherUseCaseUi> usecase);

private:
    QQmlApplicationEngine *_engine;
    WeatherUI *_weatherUi;
};

#endif // WEATHERUI_CONTAINER_H
