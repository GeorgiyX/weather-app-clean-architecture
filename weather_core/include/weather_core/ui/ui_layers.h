#ifndef UILAYERS_H
#define UILAYERS_H

// weather_core
#include <weather_core/data/weather.h>

// stl
#include <string>

struct IWeatherUILayer {
    virtual void showForecast(const WeatherForecast &forecast) = 0;
    virtual void showError(const std::string &message) = 0;
    virtual void clearError() = 0;
    virtual void showProgressBar() = 0;
    virtual void hideProgressBar() = 0;
};

#endif // UILAYERS_H
