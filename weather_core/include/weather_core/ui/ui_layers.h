#ifndef UILAYERS_H
#define UILAYERS_H

// weather_core
#include <weather_core/data/weather.h>

// stl
#include <string>

struct IWeatherUILayer {
    void showForecast(const WeatherForecast &forecast);
    void showError(const std::string &message);
    void clearError();
    void showProgressBar();
    void hideProgressBar();
};

#endif // UILAYERS_H
