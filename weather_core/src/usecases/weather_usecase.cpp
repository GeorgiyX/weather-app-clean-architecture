#include "usecases/weather_usecase.h"
#include <functional>

WeatherUseCase::WeatherUseCase() : _network(), _ui()
{

}

void WeatherUseCase::setNetwork(std::shared_ptr<IWeatherNetworkLayer> &network)
{
    _network = network;
}

void WeatherUseCase::setUI(std::shared_ptr<IWeatherUILayer> &ui)
{
    _ui = ui;
}

void WeatherUseCase::onGetForecastClick(double lon, double lat)
{
    if (!std::less_equal<double>{}(std::abs(lon), 180.0)
            || !std::less_equal<double>{}(std::abs(lat), 90.0)) {
         _ui->showError("не корректные координаты");
         return;
    }

    _network->makeWeatherRequest({
                                     lon,
                                     lat,
                                     "metric"
                                 });
    _ui->showProgressBar();
    _ui->clearError();
}
