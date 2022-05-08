#ifndef JSON_H
#define JSON_H

// stl
#include <vector>
#include <string>

struct IJSONer {
    IJSONer(const std::vector<char> &) {};

    template<class T>
    T get(const std::string &path, T);

    template<class T>
    void put(const std::string &path, T);

    virtual std::vector<char> toBuffer() = 0;
};

#endif // JSON_H
