#ifndef REQUEST_RESPONCE_H
#define REQUEST_RESPONCE_H

// weather_core
#include <weather_core/dependencies/inetwork.h>

// qt
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

// stl
#include <memory>


class RequestRealisation : public IRequest {
public:
    RequestRealisation();
    ~RequestRealisation() = default;

    void setURL(const std::string &url) override;
    void setBody(std::vector<char> &&data) override;
    void setHeader(const std::string &header, const std::string &value) override;

    QNetworkRequest &getQNetworkRequest() const;
    std::vector<char> &getBody();

private:
    std::shared_ptr<QNetworkRequest> _request;
    std::vector<char> _body;
};

class ResponceRealisation : public IResponce {
public:

    ResponceRealisation(QNetworkReply *reply);
    ~ResponceRealisation() = default;

    int status() override;
    bool isError() override;
    std::vector<char> &body() override;
    std::vector<HeaderString> &headers() override;

private:
    void parseHeaders();
    void parseBody();

    QNetworkReply *_reply;
    std::vector<HeaderString> _headers;
    std::vector<char> _body;
};
#endif // REQUEST_RESPONCE_H
