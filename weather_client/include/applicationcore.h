#ifndef APPLICATIONCORE_H
#define APPLICATIONCORE_H

// weather_core
#include <weather_core/usecases/weather_usecase.h>
#include <weather_core/network/weather_network_layer.h>

// weather_client
#include "dependencies/network.h"

// qt
#include <QObject>
#include <QWidget>

// stl
#include <memory>


class ApplicationCore
{
public:
    ApplicationCore();

private:
    struct {
        std::shared_ptr<WeatherUseCase> _weather;
    } usecases;

    struct {
        std::shared_ptr<WeatherNetworkLayer<RequestRealisation, ResponceRealisation>> _weather;
    } networks;

};

#endif // APPLICATIONCORE_H
