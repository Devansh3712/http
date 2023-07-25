#pragma once

#include <string>
#include <unordered_map>

namespace http {
    class Message {
    protected:
        std::string _body;
        std::string _version;
        std::unordered_map<std::string, std::string> _headers;
    public:
        Message();
        void set_body(const std::string &body);
        void set_version(const std::string &version);
        void set_header(const std::string &key, const std::string &value);
        void remove_header(const std::string &key);
        std::string get_header(const std::string &key);
        std::string body();
        std::string version();
        std::unordered_map<std::string, std::string> headers();
    };
}
