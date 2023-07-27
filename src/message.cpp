#include "../include/message.hpp"

namespace http {
    Message::Message() {
        _version = DEFAULT_HTTP_VERSION;
    }

    void Message::set_body(const std::string &body) { _body = body; }

    void Message::set_version(const std::string &version) { _version = version; }

    void Message::set_cookie(const std::string &key, const std::string &value) {
        _cookies[key] = value;
    }

    void Message::set_header(const std::string &key, const std::string &value) {
        _headers[key] = value;
    }

    void Message::set_content_type(const MIME &mime_type) {
        _content_type = mime_type;
        set_header(CONTENT_TYPE, http::to_string(_content_type));
    }

    std::string Message::get_header(const std::string &key) { return _headers[key]; }

    std::string Message::get_cookie(const std::string &key) { return _cookies[key]; }

    void Message::remove_header(const std::string &key) { _headers.erase(key); }

    void Message::remove_cookie(const std::string &key) { _cookies.erase(key); }

    std::string Message::body() { return _body; }

    std::string Message::version() { return _version; }

    MIME Message::content_type() { return _content_type; }

    std::unordered_map<std::string, std::string> Message::headers() {
        return _headers;
    }

    std::unordered_map<std::string, std::string> Message::cookies() {
        return _cookies;
    }

    std::ostream &operator<<(std::ostream &output, Message &message) {
        output << message.to_string();
        return output;
    }
}
