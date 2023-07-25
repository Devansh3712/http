#pragma once

#include <algorithm>
#include <sstream>
#include <unordered_map>

#include "message.hpp"
#include "methods.hpp"

namespace http {
    class Request: public Message {
    private:
        Method _method;
        std::string _path;
    public:
        Request();
        Request(const std::string &request);
        void set_method(const Method &method);
        Method method();
        std::string path();
    };
}
