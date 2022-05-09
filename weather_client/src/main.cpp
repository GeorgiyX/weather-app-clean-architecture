// qt
#include <QGuiApplication>

// weather_client
#include "applicationcore.h"
#include "utils/utils.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    ApplicationCore core;
    core.init(parseApiKey(app.arguments()));
    return 0;
}
