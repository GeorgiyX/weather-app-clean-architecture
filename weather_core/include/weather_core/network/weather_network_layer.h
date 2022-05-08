#ifndef WEATHER_NETWORK_H
#define WEATHER_NETWORK_H

// weather_core
#include <weather_core/dependencies/inetwork.h>
#include <weather_core/dependencies/json.h>
#include <weather_core/network/network_layers_interface.h>
#include <weather_core/usecases/weather_usecase.h>
#include <weather_core/utils/constants.h>

// stl
#include <string>
#include <memory>
#include <type_traits>

template <class RequestT, class ResponceT, class JSON>
class WeatherNetworkLayer : public IWeatherNetworkLayer
{
    static_assert(std::is_base_of<IRequest, RequestT>::value, "RequestT должен реализовывать IRequest");
    static_assert(std::is_base_of<IResponce, ResponceT>::value, "ResponceT должен реализовывать IResponce");
    static_assert(std::is_base_of<IJSONParser, JSON>::value, "JSON должен реализовывать IJSONParser");

public:
    WeatherNetworkLayer(const std::string apiKey);
    void setNetwork(std::shared_ptr<INetwork> &network);
    void setWeatherUseCase(std::shared_ptr<IWeatherUseCaseNetwork> &usecase);
    void makeWeatherRequest(const WeatherLocation &weather) override;


private:
    void onWeatherResponce(IResponce &responce);

    std::shared_ptr<INetwork> _network;
    std::shared_ptr<IWeatherUseCaseNetwork> _usecase;
    std::string _apiKey;
};

#include <network/weather_network_layer.impl>

#endif // WEATHER_NETWORK_H
