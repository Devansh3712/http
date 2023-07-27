#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

#include "mimes.hpp"

// CRLF consists of two characters - CR (Carriage Return) and
// LF (Line Feed). It is used as delimiter in HTTP messages.
#define CRLF "\r\n"
#define DEFAULT_HTTP_VERSION "HTTP/1.1"
#define CONTENT_TYPE "Content-Type"
#define COOKIE "Cookie"
#define SET_COOKIE "Set-Cookie"

namespace http {
    class Message {
    protected:
        std::string _body;
        std::string _version;
        MIME _content_type;
        std::unordered_map<std::string, std::string> _headers;
        std::unordered_map<std::string, std::string> _cookies;
    public:
        Message();
        void set_body(const std::string &body);
        void set_version(const std::string &version);
        void set_content_type(const MIME &mime_type);
        void set_header(const std::string &key, const std::string &value);
        void set_cookie(const std::string &key, const std::string &value);
        std::string get_header(const std::string &key);
        std::string get_cookie(const std::string &key);
        void remove_header(const std::string &key);
        void remove_cookie(const std::string &key);
        virtual std::string to_string() = 0;
        std::string body();
        std::string version();
        MIME content_type();
        std::unordered_map<std::string, std::string> headers();
        std::unordered_map<std::string, std::string> cookies();
        friend std::ostream &operator<<(std::ostream &output, Message &message);
    };
}
