#include "ui/weather_ui.h"

void WeatherUI::onGetForecastClick(QString lon, QString lat)
{
    _weatherUseCase->onGetForecastClick(lon.toStdString(), lat.toStdString());
}

void WeatherUI::onResetClick()
{
    _weatherUseCase->onResetClick();
}

void WeatherUI::setWeatherUseCase(std::shared_ptr<IWeatherUseCaseUi> usecase)
{
    _weatherUseCase = usecase;
}
