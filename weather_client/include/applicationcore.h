#ifndef APPLICATIONCORE_H
#define APPLICATIONCORE_H

// weather_core
#include <weather_core/usecases/weather_usecase.h>
#include <weather_core/network/weather_network_layer.h>

// weather_client
#include "dependencies/network.h"
#include "dependencies/request_responce.h"
#include "dependencies/json.h"
#include "ui/weather_ui_container.h"

// qt
#include <QObject>
#include <QWidget>

// stl
#include <memory>

using WeatherNetworkLayerSpec = WeatherNetworkLayer<RequestRealisation, ResponceRealisation, JSONer>;

class ApplicationCore
{
public:
    ApplicationCore();

    void init(const std::string &apiKey);

private:

    std::shared_ptr<WeatherUIContainer> _uiContainer;
    struct {
        std::shared_ptr<WeatherUseCase> weather;
    } _usecases;
    struct {
        std::shared_ptr<WeatherNetworkLayerSpec> weather;
    } _networks;

};

#endif // APPLICATIONCORE_H
