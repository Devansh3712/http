#include "../include/message.hpp"

namespace http {
    Message::Message() {}

    void Message::set_body(const std::string &body) { _body = body; }

    void Message::set_version(const std::string &version) { _version = version; }

    void Message::set_header(const std::string &key, const std::string &value) {
        _headers[key] = value;
    }

    void Message::remove_header(const std::string &key) { _headers.erase(key); }

    std::string Message::get_header(const std::string &key) { return _headers[key]; }

    std::string Message::body() { return _body; }

    std::string Message::version() { return _version; }

    std::unordered_map<std::string, std::string> Message::headers() {
        return _headers;
    }
}
