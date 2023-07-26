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
        std::unordered_map<std::string, std::string> _query;
    public:
        Request();
        Request(const std::string &request);
        void set_method(const Method &method);
        std::string get_query(const std::string &key);
        Method method();
        std::string path();
        std::unordered_map<std::string, std::string> query();
    };
}
