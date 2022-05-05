#include "ui/weatherui.h"
#include "ui_weatherui.h"

WeatherUI::WeatherUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherUI)
{
    ui->setupUi(this);
}

WeatherUI::~WeatherUI()
{
    delete ui;
}
