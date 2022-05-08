#ifndef JSON_IMPLEMENTATION_H
#define JSON_IMPLEMENTATION_H

// weather_core
#include <weather_core/dependencies/json.h>

// boost
#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

class JSONer : IJSONer {
public:
    JSONer(const std::vector<char> &data);

    template<class T>
    T get(const std::string &path, T defaultValue);

    template<class T>
    void put(const std::string &path, T value);

    std::vector<char> toBuffer();

private:
    pt::ptree _tree;
};

#include "dependencies/json.impl"


#endif // JSON_IMPLEMENTATION_H
