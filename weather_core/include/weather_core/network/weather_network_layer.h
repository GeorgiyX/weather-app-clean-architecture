#ifndef WEATHER_NETWORK_H
#define WEATHER_NETWORK_H

// weather_core
#include <weather_core/dependencies/inetwork.h>
#include <weather_core/network/network_layers_interface.h>
#include <weather_core/usecases/weather_usecase.h>
#include <weather_core/utils/constants.h>

// stl
#include <string>
#include <memory>
#include <type_traits>

template <class RequestT, class ResponceT>
class WeatherNetworkLayer : public IWeatherNetworkLayer
{
    static_assert(std::is_base_of<IRequest, RequestT>::value, "RequestT должен наследоваться от IRequest");
    static_assert(std::is_base_of<IResponce, ResponceT>::value, "ResponceT должен наследоваться от IResponce");

public:
    WeatherNetworkLayer(const std::string apiKey);
    void setNetwork(std::shared_ptr<INetwork> &network);
    void setWeatherUseCase(std::shared_ptr<WeatherUseCase> &usecase);
    void makeWeatherRequest(const WeatherLocation &weather) override;


private:
    void onWeatherResponce(const IResponce &responce);

    std::shared_ptr<INetwork> _network;
    std::shared_ptr<WeatherUseCase> _usecase;
    std::string _apiKey;
};

template <class RequestT, class ResponceT>
WeatherNetworkLayer<RequestT, ResponceT>::WeatherNetworkLayer(const std::string apiKey) :
    _network(),
    _usecase(),
    _apiKey(apiKey)
{

}

template<class RequestT, class ResponceT>
void WeatherNetworkLayer<RequestT, ResponceT>::setNetwork(std::shared_ptr<INetwork> &network)
{
    _network = network;
}

template<class RequestT, class ResponceT>
void WeatherNetworkLayer<RequestT, ResponceT>::setWeatherUseCase(std::shared_ptr<WeatherUseCase> &usecase)
{
    _usecase = usecase;
}

template<class RequestT, class ResponceT>
void WeatherNetworkLayer<RequestT, ResponceT>::makeWeatherRequest(const WeatherLocation &weather)
{
    RequestT request;
    request.setURL(WEATHER_URL
                   + "?lat=" + std::to_string(weather.lat)
                   + "&lon=" + std::to_string(weather.lon)
                   + "&appid=" + _apiKey);
    _network->get(request,
                  std::bind(&WeatherNetworkLayer<RequestT, ResponceT>::onWeatherResponce,
                            this,
                            std::placeholders::_1));

}

template<class RequestT, class ResponceT>
void WeatherNetworkLayer<RequestT, ResponceT>::onWeatherResponce(const IResponce &responce)
{
    
}
#include "weather_network_layer.impl"

#endif // WEATHER_NETWORK_H
