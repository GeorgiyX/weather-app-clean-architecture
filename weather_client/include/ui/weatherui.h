#ifndef WEATHERUI_H
#define WEATHERUI_H

// weather_core
#include <weather_core/ui/ui_layers.h>

// qt
#include <QWidget>

namespace Ui {
class WeatherUI;
}

class WeatherUI : public QWidget, public IWeatherUILayer
{
    Q_OBJECT

public:
    explicit WeatherUI(QWidget *parent = nullptr);
    ~WeatherUI();

private:
    Ui::WeatherUI *ui;
};

#endif // WEATHERUI_H
