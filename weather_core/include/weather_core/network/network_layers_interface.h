#ifndef NETWORKLAYERS_H
#define NETWORKLAYERS_H

// weather_core
#include <weather_core/data/weather.h>

struct IWeatherNetworkLayer {
    virtual void makeWeatherRequest(const WeatherLocation &weather) = 0;
};

#endif // NETWORKLAYERS_H
