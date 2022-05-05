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
    std::string sky;
};

#endif // MYDATATYPES_H
