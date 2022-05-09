// weather_client
#include "applicationcore.h"

ApplicationCore::ApplicationCore() :
    _uiContainer(),
    _usecases(),
    _networks()
{

}

void ApplicationCore::init(const std::string &apiKey)
{
    _uiContainer = std::make_shared<WeatherUIContainer>();
    _usecases.weather = std::make_shared<WeatherUseCase>();
    _networks.weather = std::make_shared<WeatherNetworkLayerSpec>(apiKey);

    _usecases.weather->setUI(_uiContainer->getIWeatherUILayer());
    _usecases.weather->setNetwork(_networks.weather);
    _networks.weather->setWeatherUseCase(_usecases.weather);
}
