// weather_client
#include "dependencies/network.h"
#include "dependencies/request_responce.h"

// qt
#include <QUrl>
#include <QString>
#include <QObject>


void NetworkRealisation::get(const IRequest &request,
                             const std::function<void (IResponce &)> &responceCallBack)
{
    auto requestRealisation = dynamic_cast<const RequestRealisation&>(request);
    auto responce = _networkManager->get(requestRealisation.getQNetworkRequest());
    responce->setParent(_networkManager.get());
    connect(responce, &QNetworkReply::finished, [responce, responceCallBack]() {
        ResponceRealisation responceRealisation(responce);
        responceCallBack(responceRealisation);
    });
}

void NetworkRealisation::post(const IRequest &request,
                              const std::function<void (IResponce &)> &responceCallBack)
{
    auto requestRealisation = dynamic_cast<const RequestRealisation&>(request);
    auto responce = _networkManager->post(requestRealisation.getQNetworkRequest(),
                                          requestRealisation.getBody().data());
    responce->setParent(_networkManager.get());
    connect(responce, &QNetworkReply::finished, [responce, responceCallBack]() {
        ResponceRealisation responceRealisation(responce);
        responceCallBack(responceRealisation);
    });
}
