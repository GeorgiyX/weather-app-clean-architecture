#ifndef INETWORK_H
#define INETWORK_H

#include <string>
#include <vector>
#include <functional>


struct IRequest {
    virtual void setURL(const std::string &url) = 0;
    virtual void setBody(std::vector<char> &&data) = 0;
    virtual void setHeader(const std::string &header, const std::string &value) = 0;
};

struct IResponce {
    using HeaderString = std::pair<std::string, std::string>;
    virtual int status() = 0;
    virtual bool isError() = 0;
    virtual std::vector<char> &body() = 0;
    virtual std::vector<HeaderString> &headers() = 0;
};


struct INetwork {
    virtual void get(const IRequest &request, const std::function<void(IResponce &)> &responceCallBack) = 0;
    virtual void post(const IRequest &request, const std::function<void(IResponce &)> &responceCallBack) = 0;
};


#endif // INETWORK_H
