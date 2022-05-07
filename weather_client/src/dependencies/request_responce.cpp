#include "dependencies/request_responce.h"

RequestRealisation::~RequestRealisation()
{

}

RequestRealisation::RequestRealisation() :
    _request(std::make_shared<QNetworkRequest>()),
    _body()
{
}

void RequestRealisation::setURL(const std::string &url)
{
    _request->setUrl(QUrl(QString::fromStdString(url)));
}

void RequestRealisation::setBody(std::vector<char> &&data)
{
    _body = std::move(data);
}

void RequestRealisation::setHeader(const std::string &header, const std::string &value)
{
    _request->setRawHeader(QByteArray(header.c_str()), QByteArray(value.c_str()));
}

QNetworkRequest &RequestRealisation::getQNetworkRequest() const
{
    return *_request.get();
}


std::vector<std::pair<std::string, std::string> > ResponceRealisation::headers()
{
    _re
}
