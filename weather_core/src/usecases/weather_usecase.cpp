#include <weather_core/usecases/weather_usecase.h>
#include <functional>

WeatherUseCase::WeatherUseCase() : _network(), _ui()
{

}

void WeatherUseCase::setNetwork(std::shared_ptr<IWeatherNetworkLayer> network)
{
    _network = network;
}

void WeatherUseCase::setUI(IWeatherUILayer *ui)
{
    _ui = ui;
}

void WeatherUseCase::onGetForecastClick(const std::string &lon, const std::string &lat)
{
    double lonNum = 0.0, latNum = 0.0;
    try {
        lonNum = std::atof(lon.c_str());
        latNum = std::atof(lat.c_str());
    } catch (std::exception &err) {
        _ui->showError(err.what());
        return;
    }

    if (!std::less_equal<double>{}(std::abs(lonNum), 180.0)
            || !std::less_equal<double>{}(std::abs(latNum), 90.0)) {
         _ui->showError("не корректные координаты");
         return;
    }

    _network->makeWeatherRequest({
                                     lonNum,
                                     latNum,
                                     "metric"
                                 });
    _ui->showProgressBar();
    _ui->clearError();

}
