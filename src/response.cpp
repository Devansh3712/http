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

    // An HTTP response is composed of
    // - Status line: Consists of HTTP version, status code and status text.
    // - Headers: A case insensitive string followed by a colon (:) and a value
    //            whose structure depends upon the header.
    // - Body: Not all responses have a body.
    //
    // HTTP/1.1 200 OK
    // Access-Control-Allow-Origin: *
    // Connection: keep-alive
    // Content-Encoding: gzip, deflate
    // Content-Type: application/json
    // Set-Cookie: token=21112003; initials=PP
    std::string Response::to_string() {
        std::ostringstream stream;
        stream << _version << ' ';
        stream << http::to_code(_status_code) << ' ';
        stream << http::to_string(_status_code) << CRLF;
        if (!_headers.empty()) {
            for (auto item: _headers) { stream << item.first << ": " << item.second << CRLF; }
        }
        if (!_cookies.empty()) {
            stream << SET_COOKIE << ": ";
            for (auto item: _cookies) { stream << item.first << '=' << item.second << "; "; }
            stream << CRLF;
        }
        stream << CRLF;
        if (!_body.empty()) { stream << _body; }
        return stream.str();
    }

    Status Response::status_code() { return _status_code; }
}
