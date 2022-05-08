// weather_core
#include "dependencies/request_responce.h"

// stl
#include <cstring>

/* RequestRealisation */
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


/* ResponceRealisation */
ResponceRealisation::ResponceRealisation(QNetworkReply *reply) :
    IResponce(),
    _reply(reply),
    _headers(),
    _body()
{
    parseHeaders();
    parseBody();
}

int ResponceRealisation::status()
{
    return _reply->attribute(QNetworkRequest::Attribute::HttpStatusCodeAttribute).toInt();
}

bool ResponceRealisation::isError()
{
    return _reply->error() != QNetworkReply::NetworkError::NoError;
}

std::vector<char> &ResponceRealisation::body()
{
    return _body;
}

std::vector<IResponce::HeaderString> &ResponceRealisation::headers()
{
    return _headers;
}

void ResponceRealisation::parseHeaders()
{
    auto &headersRaw = _reply->rawHeaderPairs();
    _headers.reserve(headersRaw.length());
    std::for_each(headersRaw.begin(), headersRaw.end(),
                  [this](const QNetworkReply::RawHeaderPair &rawHeader) {
        HeaderString stringHeader;
        stringHeader.first = rawHeader.first.data();
        stringHeader.second = rawHeader.second.data();
        _headers.push_back(std::move(stringHeader));
    });
}

void ResponceRealisation::parseBody()
{
    std::vector<char> body;
    auto bodyByteArray = _reply->readAll();
    body.reserve(bodyByteArray.size());
    std::memcpy(body.data(), bodyByteArray.data(), body.capacity());
}
