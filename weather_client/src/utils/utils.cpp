// weather_client
#include "utils/utils.h"

// qt
#include <QCommandLineOption>
#include <QCommandLineParser>

std::string parseApiKey(const QStringList &args)
{
    QCommandLineParser parser;
    QCommandLineOption apiKeyOption("api-key",
                              QCoreApplication::translate("main", "ключ api бекенда"),
                              QCoreApplication::translate("main", "api-key"));
    parser.addOption(apiKeyOption);

    parser.parse(args);
    auto apiKey = parser.value(apiKeyOption);
    if (apiKey.isEmpty()){
        throw std::runtime_error("не указан ключ api бека");
    }

    return apiKey.toStdString();
}
