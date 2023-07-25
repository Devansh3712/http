#include "../include/response.hpp"

namespace http {
    Response::Response() {}

    Response::Response(Request &request) {
        _version = request.version();
    }

    Response::Response(const std::string &body, std::string version, const http::Status &status_code) {
        _body = body;
        _version = version;
        _status_code = status_code;
    }

    void Response::set_status_code(const Status &status_code) { _status_code = status_code; }

    std::string Response::to_string() {
        std::ostringstream stream;
        stream << _version << ' ';
        stream << http::to_code(_status_code) << ' ';
        stream << http::to_string(_status_code) << "\r\n";
        if (!_headers.empty()) {
            for (auto item: _headers) { stream << item.first << ": " << item.second << "\r\n"; }
            stream << "\r\n";
        }
        stream << _body << "\r\n";
        return stream.str();
    }

    Status Response::status_code() { return _status_code; }
}
