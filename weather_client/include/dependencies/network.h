#ifndef NETWORK_H
#define NETWORK_H

// weather_core
#include <weather_core/dependencies/inetwork.h>

// qt
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

// stl
#include <memory>

class NetworkRealisation : public QObject,  public INetwork {

    Q_OBJECT

public:

    NetworkRealisation();
    void get(const IRequest &request, const std::function<void (IResponce &)> &responceCallBack) override;
    void post(const IRequest &request, const std::function<void (IResponce &)> &responceCallBack) override;

private:
    std::shared_ptr<QNetworkAccessManager> _networkManager;
};




#endif  // NETWORK_H
