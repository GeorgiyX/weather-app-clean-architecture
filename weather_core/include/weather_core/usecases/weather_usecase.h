#ifndef WEATHER_UC_H
#define WEATHER_UC_H

// weather_core
#include <weather_core/network/network_layers_interface.h>
#include <weather_core/ui/ui_layers.h>
#include <weather_core/usecases/weather_usecase_interface.h>

// stl
#include <string>
#include <memory>

class WeatherUseCase : public IWeatherUseCaseUi, public IWeatherUseCaseNetwork
{
public:
    WeatherUseCase();
    void setNetwork(std::shared_ptr<IWeatherNetworkLayer> &network);
    void setUI(std::shared_ptr<IWeatherUILayer> &ui);
    void onForecastResponce(const WeatherForecast &forecast);
    void onGetForecastClick(double lon, double lat);

private:
    std::shared_ptr<IWeatherNetworkLayer> _network;
    std::shared_ptr<IWeatherUILayer> _ui;

};

#endif // WEATHER_UC_H
