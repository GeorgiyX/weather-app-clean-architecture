#ifndef MYDATATYPES_H
#define MYDATATYPES_H

// stl
#include <string>

struct WeatherLocation {
    double lon;
    double lat;
    std::string units;
};


struct WeatherForecast {
    double temperature;
    double pressure;
    double cloudiness;
    double windSpeed;
    double windDegree;
    double visibility;
};

#endif // MYDATATYPES_H
