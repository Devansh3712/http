#pragma once

#include <string>
#include <unordered_map>

#include "mimes.hpp"

#define CONTENT_TYPE "Content-Type"

namespace http {
    class Message {
    protected:
        std::string _body;
        std::string _version;
        MIME _content_type;
        std::unordered_map<std::string, std::string> _headers;
    public:
        Message();
        void set_body(const std::string &body);
        void set_version(const std::string &version);
        void set_header(const std::string &key, const std::string &value);
        void set_content_type(const MIME &mime_type);
        void remove_header(const std::string &key);
        std::string get_header(const std::string &key);
        virtual std::string to_string() = 0;
        std::string body();
        std::string version();
        MIME content_type();
        std::unordered_map<std::string, std::string> headers();
    };
}
