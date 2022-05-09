#ifndef WEATHER_USECASE_INTERFACE_H
#define WEATHER_USECASE_INTERFACE_H

// weather_core
#include <weather_core/data/weather.h>

struct IWeatherUseCaseUi {
    virtual void onGetForecastClick(const std::string &lon, const std::string & lat) = 0;
    virtual void onResetClick() = 0;
};

struct IWeatherUseCaseNetwork {
    virtual void onForecastResponce(const WeatherForecast &forecast) = 0;
    virtual void onForecastError() = 0;
};


#endif // WEATHER_USECASE_INTERFACE_H
