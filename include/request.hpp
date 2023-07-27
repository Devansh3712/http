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
        void set_path(const std::string &path);
        void set_query(const std::string &key, const std::string &value);
        std::string get_query(const std::string &key);
        std::string to_string();
        Method method();
        std::string path();
        std::unordered_map<std::string, std::string> query();
    };
}
