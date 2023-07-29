#include "../include/request.hpp"

namespace http {
    Request::Request() {}

    Request::Request(const std::string &request) {
        std::string start_line, header, body;
        std::string method, line, key, value;
        std::istringstream stream;
        size_t begin = 0, end = 0;

        // Parse start_line
        end = request.find(CRLF, begin);
        start_line = request.substr(begin, end - begin);
        stream.str(start_line);
        stream >> method >> _path >> _version;
        _method = http::to_method(method);

        // Parse query parameters
        stream.clear();
        stream.str(_path);
        // Remove URL from path
        std::getline(stream, line, '?');
        while (std::getline(stream, line, '&')) {
            std::istringstream query_stream(line);
            std::getline(query_stream, key, '=');
            std::getline(query_stream, value);
            _query[key] = value;
        }

        // Parse header and body
        begin = end + 2;
        end = request.find("\r\n\r\n", begin);
        if (end != std::string::npos) {
            header = request.substr(begin, end - begin);
            begin = end + 4;
            end = request.length();
            if (begin < end) { _body = request.substr(begin, end - begin); }
        }
        stream.clear();
        stream.str(header);
        while (std::getline(stream, line)) {
            std::istringstream header_stream(line);
            std::getline(header_stream, key, ':');
            std::getline(header_stream, value);
            // Remove whitespaces
            key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end());
            value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
            _headers[key] = value;
        }

        // Parse content type from headers
        if (_headers.find(CONTENT_TYPE) != _headers.end()) {
            stream.clear();
            stream.str(_headers[CONTENT_TYPE]);
            std::getline(stream, value, ';');
            _content_type = to_mime_type(value);
        }

        // Parse cookies from headers
        if (_headers.find(COOKIE) != _headers.end()) {
            stream.clear();
            stream.str(_headers[COOKIE]);
            while (std::getline(stream, line, ';')) {
                std::istringstream cookie_stream(line);
                std::getline(cookie_stream, key, '=');
                std::getline(cookie_stream, value);
                _cookies[key] = value;
            }
            _headers.erase(COOKIE);
        }
    }

    void Request::set_method(const Method &method) { _method = method; }

    void Request::set_path(const std::string &path) { _path = path; }

    void Request::set_query(const std::string &key, const std::string &value) {
        _query[key] = value;
    }

    std::string Request::get_query(const std::string &key) { return _query[key]; }

    // An HTTP request is composed of
    // - Start line: Consists of HTTP method, request target and HTTP version
    // - Headers: A case insensitive string followed by a colon (:) and a value
    //            whose structure depends upon the header.
    // - Body: Some requests send data to the server in order to update it.
    //
    // GET /api/v1 HTTP/1.1
    // Host: localhost:8080
    // User-Agent: Mozilla/5.0 ...
    // Accept-Encoding: gzip, deflate
    // Connection: keep-alive
    // Content-Type: application/json
    // Cookie: token=10022004; initials=TG
    std::string Request::to_string() {
        std::ostringstream stream;
        stream << http::to_string(_method) << ' ';
        stream << _path << ' ';
        stream << _version << CRLF;
        if (!_headers.empty()) {
            for (auto item: _headers) { stream << item.first << ": " << item.second << CRLF; }
        }
        if (!_cookies.empty()) {
            stream << COOKIE << ": ";
            for (auto item: _cookies) { stream << item.first << '=' << item.second << "; "; }
            stream << CRLF;
        }
        stream << CRLF;
        if (!_body.empty()) { stream << _body; }
        return stream.str();
    }

    Method Request::method() { return _method; }

    std::string Request::path() { return _path; }

    std::unordered_map<std::string, std::string> Request::query() {
        return _query;
    }
}
